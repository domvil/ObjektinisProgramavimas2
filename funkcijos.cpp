#include "funkcijos.h"
#include "mylib.h"

mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
uniform_int_distribution<int> dist(0, 10);

int generuotiSkaiciu(){
    return dist(mt);
}

void intIvedimas(int &priskirti, int lowerBound, int upperBound, int stoppage){
    if(random==0){
    cin >> priskirti;
    while((cin.fail() || (priskirti > upperBound && upperBound!=-1) || priskirti < lowerBound) && priskirti != stoppage){
        cout << "Bloga ivestis, ivesti sveika skaiciu is [" << lowerBound << " , ";
        if(upperBound==-1){
            cout << "int32lim]\n";
        }
        else{
            cout << upperBound << "]\n";
        }
        cin.clear();
        cin.ignore(80,'\n');
        cin >> priskirti;
    }
    }
    else{
        priskirti = generuotiSkaiciu();
        cout << "Atsitiktinai priskirta " << priskirti << "\n";
    }
}

double median(vector<int> &arr, int n){
    if(n==0) return 0;
    sort(arr.begin(),arr.end());
    if(n%2!=0){
        return (double)arr[n/2];
    }else{
        return (double)(arr[(n-1)/2]+arr[n/2])/2.0;
    }
}

double avg(vector<int> &arr, int n){
    if(n>0){
        return accumulate(arr.begin(), arr.end(),0.0)/(double)n;
    }
    return 0;
}

double skaiciuotiGalutini(double temp, double egz){
    return 0.4*temp+0.6*(double)egz;
}

Studentas read(int nr){
    Studentas s;
    cout << "Iveskite " << nr+1 << "-tojo studento duomenis:\n";
    cout << "Iveskite studento varda:\n";
    cin >> s.vardas;
    cin.ignore(80,'\n');
    cout << "Iveskite studento pavarde\n";
    cin >> s.pavarde;
    cin.ignore(80,'\n');
    cout << "Ar studento namu darbus sugeneruoti atsitiktinai ar ivesite patys?\n1 - Atsitiktinai 0 - Pats\n";
    random = 0;
    intIvedimas(random,0,1);
    int index = 0;
    int tmp=-1;
    if(random==0){
    while(tmp!=11){
        cout << "Ivesti " << index+1 << "-ojo namu darbu rezultata (norint baigti ivesti 11)\n";
        intIvedimas(tmp,0,10,11);
        if(tmp!=11 && tmp != -1){
        s.ndRezultatai.push_back(0);
        s.ndRezultatai[index]=tmp;
        s.namuDarbuSk+=1;
        }
        index++;
    }
    }
    else{
        cout << "Namu darbu skaicius:\n";
        intIvedimas(s.namuDarbuSk,0,10);
        for(int i = 0; i < s.namuDarbuSk; i++){
            cout << i+1 << "-tojo namu darbu rezultatas:\n";
            s.ndRezultatai.push_back(0);
            intIvedimas(s.ndRezultatai[i],0,10);
        }
    }
    cout << "Iveskite studento egzamino rezultata:\n";
    intIvedimas(s.egzRez,0,10);
    double temp;
    if(pasirinkimas==1){
        temp = avg(s.ndRezultatai,s.namuDarbuSk);
    }
    else temp = median(s.ndRezultatai,s.namuDarbuSk);
    s.galutinis = skaiciuotiGalutini(temp,s.egzRez);
    return s;
}

void print(Studentas s) {
  printf("%-12s %-12s %-16.2lf \n", s.vardas.c_str(),s.pavarde.c_str(), s.galutinis);
}

int pasirinktiMedArVid(int &pasirinkimas){
    cout << "Ar norite, jog galutiniam bale butu naudojamas namu darbu vidurkis ar mediana?\nIvesti 0 arba 1\n0 - Mediana, 1 - Vidurkis\n";
    intIvedimas(pasirinkimas,0,1);
}
void readfromFile(string filename, list<Studentas> &sar, int &studentu_skaicius){
    try{
        ifstream fr(filename);
        if(!fr.fail()){
        int sk;
        double temp2;
        string line;
        string temp,pirmaEil;
        int kiekNd = -3;
        getline(fr >> ws,pirmaEil);
        stringstream iss(pirmaEil);
        while(iss >> temp)
        {
            kiekNd++;
        }
        while(getline(fr >> ws,line)){
            Studentas s;
            stringstream iss(line);
            iss>> s.vardas;
            iss >> s.pavarde;
            for(int i = 0; i < kiekNd; i++){
                iss>> sk;
                s.ndRezultatai.push_back(sk);
            }
            iss >> sk;
            s.egzRez=sk;
            if(pasirinkimas==1){
                temp2 = avg(s.ndRezultatai,kiekNd);
            }
            else temp2 = median(s.ndRezultatai,kiekNd);
            s.galutinis = skaiciuotiGalutini(temp2,s.egzRez);
            sar.push_back(s);
        }
        }
        else{
            throw runtime_error(filename);
        }
        studentu_skaicius=sar.size();
    }
    catch(exception &e){
     cout << "Ivyko problema nuskaitant faila: " << e.what() << "\n";
     exit(0);
  }
}
void readfromFile(string filename, vector<Studentas> &sar, int &studentu_skaicius){
    try{
        ifstream fr(filename);
        if(!fr.fail()){
        int sk;
        double temp2;
        string line;
        string temp,pirmaEil;
        int kiekNd = -3;
        getline(fr >> ws,pirmaEil);
       stringstream iss(pirmaEil);
        while(iss >> temp)
        {
            kiekNd++;
        }
        while(getline(fr >> ws,line)){
            Studentas s;
            stringstream iss(line);
            iss>> s.vardas;
            iss >> s.pavarde;
            for(int i = 0; i < kiekNd; i++){
                iss>> sk;
                s.ndRezultatai.push_back(sk);
            }
            iss >> sk;
            s.egzRez=sk;
            if(pasirinkimas==1){
                temp2 = avg(s.ndRezultatai,kiekNd);
            }
            else temp2 = median(s.ndRezultatai,kiekNd);
            s.galutinis = skaiciuotiGalutini(temp2,s.egzRez);
            sar.push_back(s);
        }
        }
        else{
            throw runtime_error(filename);
        }
        studentu_skaicius=sar.size();
    }
    catch(exception &e){
     cout << "Ivyko problema nuskaitant faila: " << e.what() << "\n";
     exit(0);
  }
}

void pirmaStrategija(vector<Studentas>&sar, vector<Studentas> &vargsiukai, vector<Studentas> &moksliukai){
    for(auto &s: sar){
        if(s.galutinis<5.00) vargsiukai.push_back(s);
        else moksliukai.push_back(s);
    }
    sar.clear();
}

void pirmaStrategija(list<Studentas>&sar, list<Studentas> &vargsiukai, list<Studentas> &moksliukai){
    for(auto &s: sar){
        if(s.galutinis<5.00) vargsiukai.push_back(s);
        else moksliukai.push_back(s);
    }
    sar.clear();
}
void antraStrategija(vector<Studentas>&sar, vector<Studentas> &vargsiukai){
    auto it = sar.begin();
    while(it!=sar.end()){
        if( (*it).galutinis < 5.00){
                vargsiukai.push_back(*it);
                it++;
            }
        else{
            break;
        }
    }
    sar.erase(sar.begin(),it);
}
void antraStrategija(list<Studentas>&sar, list<Studentas> &vargsiukai){
    auto it = sar.begin();
    while(it!=sar.end()){
        if( (*it).galutinis < 5.00){
                vargsiukai.push_back(*it);
                it++;
            }
        else{
            break;
        }
    }
    sar.erase(sar.begin(),it);
}

void vectorOptimizacija(vector<Studentas> &sar, vector <Studentas> &vargsiukai){
    partition(sar.begin(), sar.end(), [](const Studentas &s){ return s.galutinis < 5.00; });
    auto it = find_if(sar.begin(),sar.end(),[](const Studentas &s){ return s.galutinis >= 5.00;});
    copy(sar.begin(),it,back_inserter(vargsiukai));
    sar.erase(sar.begin(),it);
}
void printToFile(string filename, vector<Studentas> &sar, int ndSkaicius){
    string var[3] = {"Med.", "Vid."};
    stringstream buffer;
    ofstream out(filename);
    buffer << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << "Galutinis("<< var[pasirinkimas] << ")" << "\n";
    for(int i = 0; i < sar.size(); i++){
        buffer << left << setw(15) << sar[i].vardas << setw(15) << sar[i].pavarde << fixed
        << setprecision(2) << sar[i].galutinis << "\n";
    }
    out << buffer.str();
    buffer.clear();
    out.close();
}

void generuotiFailus(int &studentu_skaicius,int ndSk){
    string filename = "studentai"+to_string(studentu_skaicius)+".txt";
    stringstream buffer;
    ofstream out(filename);
    buffer << "Vardas" << setw(15) << "Pavarde";
    for(int i = 0; i < ndSk; i++){
        buffer << setw(15) << "ND" << i+1;
    }
    buffer << setw(15) << "Egz.\n";
    for(int i = 0; i < studentu_skaicius; i++){
        buffer << "Vardas" << i+1 << setw(15) << "Pavarde" << i+1;
        for(int j = 0; j < ndSk; j++){
            buffer << setw(15) << generuotiSkaiciu();
        }
        buffer << setw(15) << generuotiSkaiciu() << "\n";
    }
    out << buffer.str();
    buffer.clear();
    out.close();
}

bool compare(Studentas a, Studentas b){
    return a.galutinis<b.galutinis;
}


