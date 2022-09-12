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
};

int random=0;
string pasirinkimas;

void intIvedimas(int &priskirti, int lowerBound, int upperBound){
    if(random==0){
    cin >> priskirti;
    while(cin.fail() || priskirti > upperBound || priskirti < lowerBound){
        cout << "Bloga ivestis, ivesti sveika skaiciu is [" << lowerBound << " , " << upperBound << "]\n";
        cin.clear();
        cin.ignore(80,'\n');
        cin >> priskirti;
    }
    }
    else{
        priskirti = rand()%upperBound;
        cout << "Atsitiktinai priskirta " << priskirti << "\n";
    }
}

double median(vector<int> arr, int n){
    std::sort(arr.begin(),arr.end());
    if(n%2!=0){
        return (double)arr[n/2];
    }else{
        return (double)(arr[(n-1)/2]+arr[n/2])/2;
    }
}

double avg(vector<int> arr, int n){
    if(n!=0){
        return std::accumulate(arr.begin(), arr.end(),0.0)/n;
    }
    return 0;
}

void read(Studentas &s){
    cout << "Iveskite studento varda:\n";
    cin >> s.vardas;
    cin.ignore(80,'\n');
    cout << "Iveskite studento pavarde\n";
    cin >> s.pavarde;
    cin.ignore(80,'\n');
    cout << "Ar studento namu darbus sugeneruoti atsitiktinai ar ivesite patys?\n1 - Atsitiktinai 0 - Pats\n";
    intIvedimas(random,0,1);
    string ar;
    int index = 0;
    while(true){
        cout << "Ar norite ivesti " << index+1 << "-aji namu darbo rezultata?: (Taip/Ne)\n";
        cin >> ar;
        while(cin.fail() || (ar != "Taip" & ar != "Ne")){
            cin.clear();
            cin.ignore(80,'\n');
            cout << "Bloga ivestis, ivesti Taip/Ne\n";
            cin >> ar;
        }
        if(ar=="Taip"){
            s.ndRezultatai.push_back(0);
            intIvedimas(s.ndRezultatai[index],0,10);
            index++;
        }
        else{
            break;
        }
    }
    cout << "Iveskite studento egzamino rezultata:\n";
    intIvedimas(s.egzRez,0,10);
    cout << "Ar norite, jog galutiniam bale butu naudojamas namu darbu vidurkis ar mediana?\nIvesti Vidurkis arba Mediana\n";
    cin >> pasirinkimas;
    while(pasirinkimas != "Vidurkis" && pasirinkimas != "Mediana"){
        cout << "Bloga ivestis, ivesti Vidurkis arba Mediana:\n";
        cin.clear();
        cin.ignore(80,'\n');
        cin >> pasirinkimas;
    }
    double temp;
    if(pasirinkimas=="Vidurkis"){
        temp = avg(s.ndRezultatai,s.ndRezultatai.size());
    }
    else temp = median(s.ndRezultatai,s.ndRezultatai.size());
    s.galutinis = 0.4*temp+0.6*(double)s.egzRez;
}

void print(Studentas s) {
  printf("%-12s %-12s Galutinis (%s)\n", "Vardas", "Pavarde",pasirinkimas.c_str());
  printf("%-12s %-12s %-16.2lf \n", s.vardas.c_str(),s.pavarde.c_str(), s.galutinis);
}

int main()
{
    srand(time(NULL));
    Studentas s;
    read(s);
    print(s);
    return 0;
}




