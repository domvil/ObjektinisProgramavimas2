#include "mylib.h"
#include "funkcijos.h"


int pasirinkimas;
int random;


int main()
{
    std::chrono::duration<double> diff;
    srand(time(NULL));
    int studentu_skaicius = 0;
    vector<Studentas> sar;
    int veiksmas;
    int ndSk = 0;
    cout << "Pasirinkite programos funkcija\n1 - Ivesti studentu duomenis ranka\n";
    cout << "2 - Nuskaityti pasirinkta duomenu faila\n";
    cout << "3 - Atsitiktinai generuoti studentu duomenu failus\n";
    cout << "Ivesti pasirinkimo nr. 1 , 2 arba 3\n";
    intIvedimas(veiksmas,1,4);
    if(veiksmas == 1){
        pasirinktiMedArVid(pasirinkimas);
        studentu_skaicius=1;
        char ivedimas='X';
        cout << "Iveskite studentu duomenis:\n";
        while(ivedimas!='N' && ivedimas !='n'){
        Studentas s = read(studentu_skaicius-1);
        if(s.namuDarbuSk>ndSk){
            ndSk=s.namuDarbuSk;
        }
        sar.push_back(s);
        cout << "Testi/Baigti ivedima? Ivesti T/N\n";
        cin >> ivedimas;
        cin.ignore(80,'\n');
        while(ivedimas!='T' && ivedimas !='t' && ivedimas !='N' && ivedimas!='n'){
        cout << "Bloga ivestis, bandykite dar karta!\n";
        cin >> ivedimas;
        float bendras = 0;
    }
    studentu_skaicius++;
    }
    }
    else if(veiksmas == 2){
        cout << "Iveskite duomenu failo pavadinima: (pvz 123.txt)\n";
        string filename;
        cin >> filename;
        pasirinktiMedArVid(pasirinkimas);
        auto prad = hrClock::now();
        readfromFile(filename,sar,studentu_skaicius);
        auto pab = hrClock::now();
        diff = pab-prad;
        cout << studentu_skaicius << " irasu failo nuskaitymas uztruko: " << diff.count() << "s\n";
        float bendras = diff.count();

    }
    else if(veiksmas == 3){
        cout << "Iveskite norima sugeneruotu studentu skaiciu\n";
        intIvedimas(studentu_skaicius,0,-1);
        cout << "Iveskite norima studentu namu darbu skaiciu\n";
        intIvedimas(ndSk,0,-1);
        auto prad = hrClock::now();
        generuotiFailus(studentu_skaicius,ndSk);
        auto pab = hrClock::now();
        diff = pab-prad;
        cout << studentu_skaicius << " irasu failo sugeneravimas uztruko: " << diff.count() << "s\n";
    }
    if(veiksmas==1 || veiksmas == 2){
        random = 0;
        auto bendras=diff.count();
        auto prad = hrClock::now();
        sort(sar.begin(),sar.end(),compare);
        auto pab = hrClock::now();
        diff = pab-prad;
        bendras+=diff.count();
        cout << studentu_skaicius << " irasu rusiavimas su sort funkcija uztruko: " << diff.count() << "s\n";
        vector<Studentas> moksliukai, vargsiukai;
        prad = hrClock::now();
        dalintiSarasa(sar,vargsiukai,moksliukai);
        pab = hrClock::now();
        diff = pab-prad;
        bendras+=diff.count();
        cout << studentu_skaicius << " irasu dalijimas i 2 grupes uztruko: " << diff.count() << "s\n";
        prad = hrClock::now();
        printToFile("vargsiukai.txt",vargsiukai,ndSk);
        pab = hrClock::now();
        diff = pab-prad;
        bendras+=diff.count();
        cout << studentu_skaicius << " irasu vargsiuku irasymo i faila laikas uztruko: " << diff.count() << "s\n";
        prad = hrClock::now();
        printToFile("moksliukai.txt",moksliukai,ndSk);
        pab = hrClock::now();
        diff = pab-prad;
        bendras+=diff.count();
        cout << studentu_skaicius << " irasu moksliuku irasymo i faila laikas uztruko: " << diff.count() << "s\n";
        cout << studentu_skaicius << " irasu failo bendras testavimo laikas: " << bendras << "s\n";
    }


    return 0;
}
