#include "mylib.h"
#include "funkcijos.h"


int pasirinkimas;
char raktas = 'X';
int random;


int main()
{
    int studentu_skaicius = 0;
    srand(time(NULL));
    cout << "Ar norite, jog galutiniam bale butu naudojamas namu darbu vidurkis ar mediana?\nIvesti 0 arba 1\n0 - Mediana, 1 - Vidurkis\n";
    intIvedimas(pasirinkimas,0,1);
    vector<Studentas> sar;
    char isFailoarNe='X';
    while(isFailoarNe!='R' && isFailoarNe !='r' && isFailoarNe !='F' && isFailoarNe!='f'){
        cout <<"Ar norite ivesti studentu failu duomenis ranka ar nuskaityti is failo? R - ranka F - is failo\n";
        cin.clear();
        cin.ignore(80, '\n');
        cin >> isFailoarNe;
    }
    while(raktas!='V' && raktas !='v' && raktas !='P' && raktas!='p'){
        cout <<"Ar norite studentus rusiuoti pagal varda ar pagal pavarde? V - varda , P - pavarde\n";
        cin.clear();
        cin.ignore(80, '\n');
        cin >> raktas;
    }
    if(isFailoarNe=='F' or isFailoarNe=='f'){
    readfromFile(sar);
    }
    else{
    studentu_skaicius=1;
    char ivedimas='X';
    cout << "Iveskite studentu duomenis:\n";
    while(ivedimas!='N' && ivedimas !='n'){
        sar.push_back(read(studentu_skaicius-1));
        cout << "Testi/Baigti ivedima? Ivesti T/N\n";
        cin >> ivedimas;
        cin.ignore(80,'\n');
        while(ivedimas!='T' && ivedimas !='t' && ivedimas !='N' && ivedimas!='n'){
        cout << "Bloga ivestis, bandykite dar karta!\n";
        cin >> ivedimas;
    }
    studentu_skaicius++;
    }
    }
    string var[3] = {"Med.", "Vid."};
    printf("%-12s %-12s Galutinis (%s)\n", "Vardas", "Pavarde",var[pasirinkimas].c_str());
    sort(sar.begin(),sar.end(),compare);
    for(int i = 0; i < sar.size(); i++){
        print(sar[i]);
    }
    return 0;
}
