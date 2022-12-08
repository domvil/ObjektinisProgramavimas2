**#V2.0**

**Pokyčiai**

Sukurta Doxygen dokumentacija.

**Naudojimosi instrukcija**

```
- Vartotojas prašomas pasirinkti viena iš keturių galimų programos veiksmų.
- Pasirinkus studentų duomenų įvedimą ranka, prašoma pasirinkti ar skaičiavime nauodoti mediana ar vidurkį, tada vartotojas dinamiškai įvedinėja studentų duomenis ranka.
- Pasirinkus nuskaityti studentų duomenis iš failo, prašoma įvesti failo pavadinimą bei pasirinkti ar naudoti medianą/vidukrį skaičiavimuose, jeigu toks failas neegzistuoja, programa baigia darbą.
- Pasirinkus atsitiktinį studentų duomenų failo generavimą, prašoma įvesti norimą sugeneruotų studentų skaičių, bei jų namų darbų skaičių.
- Pasirinkus studentų grupavimo testavimą, vartotojas yra prašomas įvesti norimą testuoti studentų skaičių, tada ieškomas failas pagal pasirinktą skaičių, pvz.: studentai1000.txt, jeigu jis nėra surastas, programa baigia darbą.
```

**Įdiegimo instrukcija**

```
1) Atsisiųsti visus failus iš repozitorijos. 
2) Įsirašyti cmake.
3) Įkėlus visus failus į vieną direktoriją, juos pasiekti per komandinę eilutę (su cd komanda galima) ir naudojant cmake parašyti šias komandas:

cmake CmakeLists.txt
cmake --install .
cmake --build .
Debug\v10.exe
```
