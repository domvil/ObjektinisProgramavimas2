#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <stdlib.h>


using std::string;
using std::cout;
using std::cin;


struct Studentas{
    string t;
    string pavarde="";
    string vardas="";
    int ndSkaicius=0;
    int *ndRezultatai;
    int egzRez=0;
    double galutinis=0;
};

int random;
int pasirinkimas;

void intIvedimas(int &priskirti, int lowerBound, int upperBound){
    if(random==0){
    cin >> priskirti;
    while(cin.fail() || (priskirti > upperBound && upperBound!=-1) || priskirti < lowerBound){
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




double median(int arr[], int n){
    if(n==0) return 0;
    std::sort(arr,arr+n);
    if(n%2!=0){
        return (double)arr[n/2];
    }else{
        return (double)(arr[(n-1)/2]+arr[n/2])/2.0;
    }
}

double avg(int arr[], int n){
    if(n>0){
        return std::accumulate(arr,arr+n,0.0)/n;
    }
    return 0;
}

Studentas read(int nr){
    Studentas s;
    cout << "Iveskite " << nr+1 << "-tojo studento duomenis:\n";
    cout << "Iveskite studento varda:\n";
    cin >> s.vardas;
    cout << "Iveskite studento pavarde\n";
    cin >> s.pavarde;
    cin.ignore(80,'\n');
    cout << "Ar studento namu darbus sugeneruoti atsitiktinai ar ivesite patys?\n1 - Atsitiktinai 0 - Pats\n";
    random = 0;
    intIvedimas(random,0,1);
    s.ndRezultatai = new (std::nothrow) int[5];
    for(int i = 0; i < 5; i++){
        cout << "Iveskite " << i+1 << "-aji namu darbo rezultata: \n";
        intIvedimas(s.ndRezultatai[i],0,10);
    }
    cout << "Iveskite studento egzamino rezultata:\n";
    intIvedimas(s.egzRez,0,10);
    double z;
    if(pasirinkimas==1){
        z = avg(s.ndRezultatai,s.ndSkaicius);
    }
    else z = median(s.ndRezultatai,s.ndSkaicius);
    s.galutinis = 0.4*z+0.6*(double)s.egzRez;
    return s;
}

void print(Studentas s) {
  printf("%-12s %-12s %-16.2lf \n", s.vardas.c_str(),s.pavarde.c_str(), s.galutinis);
}

int main()
{
    srand(time(NULL));
    char ivedimas='X';
    int studentu_skaicius = 1,index = 0;
    Studentas *sar,*temp;
    sar = new Studentas[studentu_skaicius];
    cout << "Ar norite, jog galutiniam bale butu naudojamas namu darbu vidurkis ar mediana?\nIvesti 0 arba 1\n0 - Mediana, 1 - Vidurkis\n";
    intIvedimas(pasirinkimas,0,-1);
    cout << "Iveskite studentu duomenis:\n";
    while(ivedimas!='N' && ivedimas !='n'){
    sar[index]=read(index);
    studentu_skaicius++; index++;
    temp = new Studentas[studentu_skaicius+1];
    for(int j = 0; j < studentu_skaicius-1; j++){
        temp[j]=sar[j];
    }

    sar = new Studentas[studentu_skaicius+1];
    sar = temp;
    delete [] temp;
    cout << "Testi/Baigti ivedima? Ivesti T/N\n";
    cin >> ivedimas;
    cin.ignore(80,'\n');
    while(ivedimas!='T' && ivedimas !='t' && ivedimas !='N' && ivedimas!='n'){
        cout << "Bloga ivestis, bandykite dar karta!\n";
        cin >> ivedimas;
    }
    }


    string var[3] = {"Med.", "Vid."};
    printf("%-12s %-12s Galutinis (%s)\n", "Vardas", "Pavarde",var[pasirinkimas].c_str());
    for(int i = 0; i < studentu_skaicius-1; i++){
        print(sar[i]);
    }
    return 0;
}
