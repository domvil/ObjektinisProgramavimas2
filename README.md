#V0.1

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

- Priskiriant kintamojo **random** reikšmę kreipiamasi į intIvedimas() funkciją su lowerBound ir upperBound argumentais **0,1**. Kadangi random yra integer tipo kintamasis, jis gali įgyti tik **dvi** reikšmes, t.y **0 arba 1**. Atitinkamai namų darbų ir egzamino rezultatam parenkam **[0,10]** rėžius.


- Įvedant kintamojo **pasirinkimas** reikšmę, tikrinama ar ji atitinka bent vieną iš galimų variantų t.y **"Vidurkis"** arba **"Mediana"**. Jeigu ne, vartotojas yra prašomas pakartoti veiksmą.
