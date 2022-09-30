#include "funkcijos.h"
#include "mylib.h"

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
        priskirti = rand()%11;
        cout << "Atsitiktinai priskirta " << priskirti << "\n";
    }
}

double median(vector<int> arr, int n){
    if(n==0) return 0;
    std::sort(arr.begin(),arr.end());
    if(n%2!=0){
        return (double)arr[n/2];
    }else{
        return (double)(arr[(n-1)/2]+arr[n/2])/2.0;
    }
}

double avg(vector<int> arr, int n){
    if(n>0){
        return std::accumulate(arr.begin(), arr.end(),0.0)/(double)n;
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

void readfromFile(vector<Studentas> &sar){
    string filename="studentai10000.txt";
    try{
        std::ifstream fileRead(filename);
        if(!fileRead.fail()){
        int sk;
        double temp2;
        string line;
        string temp,pirmaEil;
        int kiekNd = -3;
        std::getline(fileRead >> std::ws,pirmaEil);
        std::stringstream iss(pirmaEil);
        while(iss >> temp)
        {
            kiekNd++;
        }
        while(std::getline(fileRead >> std::ws,line)){
            Studentas s;
            std::stringstream iss(line);
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
            throw std::runtime_error(filename);
        }

    }
    catch(std::exception &e){
     cout << "Ivyko problema nuskaitant faila: " << e.what() << "\n";
     return;
  }
}

bool compare(Studentas a, Studentas b){
    if(raktas=='V'){
        return a.vardas<b.vardas;
    }
    else{
        return a.pavarde<b.pavarde;
    }
}


