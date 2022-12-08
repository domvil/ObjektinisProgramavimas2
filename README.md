**#V1.5**

Sukurta nauja abstrakčioji klasė zmogus.
Klase studentas dabar yra zmogus klasės išvestinė klasė.

**#V1.2**

**Naudojimosi instrukcija**

```
- Vartotojas prašomas pasirinkti viena iš keturių galimų programos veiksmų.
- Pasirinkus studentų duomenų įvedimą ranka, prašoma pasirinkti ar skaičiavime nauodoti mediana ar vidurkį, tada vartotojas dinamiškai įvedinėja studentų duomenis ranka.
- Pasirinkus nuskaityti studentų duomenis iš failo, prašoma įvesti failo pavadinimą bei pasirinkti ar naudoti medianą/vidukrį skaičiavimuose, jeigu toks failas neegzistuoja, programa baigia darbą.
- Pasirinkus atsitiktinį studentų duomenų failo generavimą, prašoma įvesti norimą sugeneruotų studentų skaičių, bei jų namų darbų skaičių.
- Pasirinkus studentų grupavimo testavimą, vartotojas yra prašomas įvesti norimą testuoti studentų skaičių, tada ieškomas failas pagal pasirinktą skaičių, pvz.: studentai1000.txt, jeigu jis nėra surastas, programa baigia darbą.
```


**Pakeitimai**

```
Vietoje struktūrų dabar naudojamos klasės, palikti metodai tik su vector konteineriu, t.y išimti visi List panaudojimai, realizuota "Rule of three" taisyklė.
```

**Spartos palyginimas su V1.0 versija**

![image](https://user-images.githubusercontent.com/113367128/203835026-eaded5db-77be-4fff-b41d-aec27ca6156c.png)

**Spartos palyginimas pagal skirtingus kompiliatoriaus optimizavimo flagus**

![image](https://user-images.githubusercontent.com/113367128/203868740-7a00ce1d-f5f6-49de-b53c-a6128dc91878.png)
