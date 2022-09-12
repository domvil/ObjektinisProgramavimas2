#V0.1

**Programos pagrindinės operacijos**

```
- Klaviatura ivedami studento vardas bei pavarde
- Pasirenkama ar studento rezultatus (t.y namu darbu, egz balus) generuoti atsitiktinai ar ivesti  ranka
- Ivedami arba sugeneruojami studento rezultatai
- Pasirenkama ar galutinio balo skaiciavime naudoti namu darbu rezultatų vidurkį arba medianą.
- Isvedami studento duomenys: pavarde, vardas, galutinis balas
```

**Apribojimai**

Visi ivedami / sugeneruojami studento rezultatų duomenys atitinka tam tikrus reikalavimus. 

- Funkcijoje intIvedimas() parametrai **lowerBound** ir **upperBound** nustato kokias reikšmes gali įgyti ivedami integer tipo duomenys. Įvedamas sveikasis skaičius gali būti tik **[**lowerbound,upperBound**]** intervale. Be to, leidžiama įvesti tik sveikuosius skaičius, kitu atveju nebus priimta įvestis ir reikės vesti iš naujo. 

```c++
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
```

- Priskiriant kintamojo **random** reikšmę kreipiamasi į intIvedimas() funkciją su lowerBound ir upperBound argumentais **0,1**. Kadangi random yra integer tipo kintamasis, jis gali įgyti tik **dvi** reikšmes, t.y **0 arba 1**. Atitinkamai namų darbų ir egzamino rezultatam parenkam **[0,10]** rėžius.

```c++
intIvedimas(random,0,1);
```

```c++
intIvedimas(s.ndRezultatai[index],0,10);
```
```c++
intIvedimas(s.egzRez,0,10);
```

- Įvedant kintamojo **pasirinkimas** reikšmę, tikrinama ar ji atitinka bent vieną iš galimų variantų t.y **"Vidurkis"** arba **"Mediana"**. Jeigu ne, vartotojas yra prašomas pakartoti veiksmą.

```c++
while(pasirinkimas != "Vidurkis" && pasirinkimas != "Mediana"){
        cout << "Bloga ivestis, ivesti Vidurkis arba Mediana:\n";
        cin.clear();
        cin.ignore(80,'\n');
        cin >> pasirinkimas;
}
```
- Vartotojui įvedant kintamojo **ar** reikšme taip pat yra tikrinama ar ji atitinka bent vieną iš galimų variantų, t.y **"Taip"** arba **"Ne"**. Kitu atveju reikia įvesti reikšmę iš naujo.
```c++
while(cin.fail() || (ar != "Taip" & ar != "Ne")){
        cin.clear();
        cin.ignore(80,'\n');
        cout << "Bloga ivestis, ivesti Taip/Ne\n";
        cin >> ar;
}
```
