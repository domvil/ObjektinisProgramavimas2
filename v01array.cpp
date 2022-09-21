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
    string vardas;
    string pavarde;
    int ndSkaicius=0;
    int *ndRezultatai;
    int egzRez;
    double galutinis;
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

void read(Studentas &s, int nr){
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
    cout << "Kiek studentas turejo namu darbu?\n";
    intIvedimas(s.ndSkaicius,0,-1);
    s.ndRezultatai = new (std::nothrow) int[s.ndSkaicius];
    for(int i = 0; i < s.ndSkaicius; i++){
        cout << "Iveskite " << i+1 << "-aji namu darbo rezultata: \n";
        intIvedimas(s.ndRezultatai[i],0,10);
    }

    cout << "Iveskite studento egzamino rezultata:\n";
    intIvedimas(s.egzRez,0,10);
    double temp;
    if(pasirinkimas==1){
        temp = avg(s.ndRezultatai,s.ndSkaicius);
    }
    else temp = median(s.ndRezultatai,s.ndSkaicius);
    s.galutinis = 0.4*temp+0.6*(double)s.egzRez;

}

void print(Studentas s) {
  printf("%-12s %-12s %-16.2lf \n", s.vardas.c_str(),s.pavarde.c_str(), s.galutinis);
}

int main()
{
    int studentu_skaicius;
    cout << "Iveskite studentu skaiciu:\n";
    intIvedimas(studentu_skaicius,1,-1);
    cout << "Ar norite, jog galutiniam bale butu naudojamas namu darbu vidurkis ar mediana?\nIvesti 0 arba 1\n0 - Mediana, 1 - Vidurkis\n";
    intIvedimas(pasirinkimas,0,-1);
    Studentas *sar = new Studentas[studentu_skaicius];
    for(int i= 0; i < studentu_skaicius; i++){
        read(sar[i],i);
    }
    string var[3] = {"Med.", "Vid."};
    srand(time(NULL));
    printf("%-12s %-12s Galutinis (%s)\n", "Vardas", "Pavarde",var[pasirinkimas].c_str());
    for(int i = 0; i < studentu_skaicius; i++){
        print(sar[i]);
    }
    return 0;
}
