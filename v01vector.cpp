#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <stdlib.h>
#include <vector>

using std::string;
using std::cout;
using std::cin;
using std::vector;

struct Studentas{
    string vardas;
    string pavarde;
    vector<int> ndRezultatai;
    int egzRez;
    double galutinis;
    int namuDarbuSk;
};

int random;
int pasirinkimas;

void intIvedimas(int &priskirti, int lowerBound, int upperBound, bool stoppage=false){
    if(random==0){
    cin >> priskirti;
    while((cin.fail() || (priskirti > upperBound && upperBound!=-1) || priskirti < lowerBound) && !stoppage || (stoppage && priskirti!=11)){
        cout << "Bloga ivestis, ivesti sveika skaiciu is [" << lowerBound << " , ";
        if(upperBound==-1){
            cout << "int32lim]\n";
        }
        else{
            cout << upperBound << "]\n";
        }
        cin.clear();
        cin.ignore(80,'\n');
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
        return std::accumulate(arr.begin(), arr.end(),0.0)/n;
    }
    return 0;
}

void read(Studentas &s,int nr){
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
    int tmp=0;
    if(random==0){
    while(tmp!=11){
        cout << "Ivesti " << index+1 << "-ojo namu darbu rezultata (norint baigti ivesti 11)\n";
        s.ndRezultatai.push_back(0);
        intIvedimas(tmp,0,10,true);
        if(tmp!=11){
        s.ndRezultatai[index]=tmp;
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
        temp = avg(s.ndRezultatai,s.ndRezultatai.size());
    }
    else temp = median(s.ndRezultatai,s.ndRezultatai.size());
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

    vector<Studentas> sar;
    for(int i = 0; i < studentu_skaicius; i++){
        Studentas s;
        read(s,i);
        sar.push_back(s);
    }
    string var[3] = {"Med.", "Vid."};
    srand(time(NULL));
    printf("%-12s %-12s Galutinis (%s)\n", "Vardas", "Pavarde",var[pasirinkimas].c_str());
    for(int i = 0; i < studentu_skaicius; i++){
        print(sar[i]);
    }
    return 0;
}
