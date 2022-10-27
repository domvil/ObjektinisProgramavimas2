
**#V0.4**

**Konteinerių testavimas**

Pridėta nauja programos funkcija: konteinerių testavimas. Ji atlieka Vector ir List konteinerių spartos palyginimus nuskaitant duomenis iš failo ir rūšiuojant, dalijant duomenis į dvi grupes. 

**Rezultatai**

![image](https://user-images.githubusercontent.com/113367128/198270662-0b985f37-a602-4e6e-8ab8-20a817c15970.png)

**Kompiuterio parametrai**

Ryzen 5 5600X

GTX 970

16GB 3600MHz

SSD 


**#V0.3**

**Studentų skirstymas į kategorijas**

Studentai dabar skirstomi į dvi atskiras kategorijas, priklausomai nuo jų galutinio balo.

**Rezultatų išvedimas į failą**

Rezultatai dabar išvedami į txt failus.

**Failų generavimas**

Pridėta galimybė sugeneruoti studentų duomenis pačiam, įvedus studentų ir namų darbų skaičius.

**Programos veikimo greičio analizė**

Pridėtas programos veiksmų atlikimo laikmatis, kuris padeda įvertinti jos spartą. 

![1000](https://user-images.githubusercontent.com/113367128/194946146-0b5d04b7-e0c3-4ea8-ba0f-aa8d2f5dbe1b.png)
![10000](https://user-images.githubusercontent.com/113367128/194946147-aa35c9d9-7696-426b-9569-8227e7892637.png)
![100000](https://user-images.githubusercontent.com/113367128/194946150-e8bf66b2-727e-4396-a692-2bfd93dccbae.png)
![1000000](https://user-images.githubusercontent.com/113367128/194946152-7da4fb54-1b18-48c7-830f-11c434125c74.png)
![10000000](https://user-images.githubusercontent.com/113367128/194946144-11797f35-80cf-48cf-981a-308c3d0b925b.png)

**#V0.2**

**Failų skaitymas**

Pridėta galimybė duomenis įvesti nuskaitant failą. 

**#V0.1**

**Programos pagrindinės operacijos**

```
- Klaviatūra ivedami studento vardas bei pavarde
- Pasirenkama ar studento rezultatus (t.y namų darbų, egz balus) generuoti atsitiktinai ar įvesti  ranka
- Įvedami arba sugeneruojami studento rezultatai
- Pasirenkama ar galutinio balo skaičiavime naudoti namų darbų rezultatų vidurkį ar medianą.
- Išvedami studento duomenys: pavardė, vardas, galutinis balas
```

**Apribojimai**

Visi ivedami / sugeneruojami studento rezultatų duomenys atitinka tam tikrus reikalavimus. 

- Funkcijoje intIvedimas() parametrai **lowerBound** ir **upperBound** nustato kokias reikšmes gali įgyti ivedami integer tipo duomenys. Įvedamas sveikasis skaičius gali būti tik **[**lowerbound,upperBound**]** intervale. Be to, leidžiama įvesti tik sveikuosius skaičius, kitu atveju nebus priimta įvestis ir reikės vesti iš naujo. 

- Programoje, kur vietoj vektoriaus yra naudojamas masyvas, daugiausiai saugoti leidžiama **10** namų darbų rezultatų reiškmių.

- Priskiriant kintamojo **random** reikšmę kreipiamasi į intIvedimas() funkciją su lowerBound ir upperBound argumentais **0,1**. Kadangi random yra integer tipo kintamasis, jis gali įgyti tik **dvi** reikšmes, t.y **0 arba 1**. Atitinkamai namų darbų ir egzamino rezultatam parenkam **[0,10]** rėžius.


- Įvedant kintamojo **pasirinkimas** reikšmę, tikrinama ar ji atitinka bent vieną iš galimų variantų t.y **"Vidurkis"** arba **"Mediana"**. Jeigu ne, vartotojas yra prašomas pakartoti veiksmą.

- Vartotojui įvedant kintamojo **ar** reikšme taip pat yra tikrinama ar ji atitinka bent vieną iš galimų variantų, t.y **"Taip"** arba **"Ne"**. Kitu atveju reikia įvesti reikšmę iš naujo.
