**#V1.0**

**Naudojimosi instrukcija**

```
- Vartotojas prašomas pasirinkti viena iš keturių galimų programos veiksmų.
- Pasirinkus studentų duomenų įvedimą ranka, prašoma pasirinkti ar skaičiavime nauodoti mediana ar vidurkį, tada vartotojas dinamiškai įvedinėja studentų duomenis ranka.
- Pasirinkus nuskaityti studentų duomenis iš failo, prašoma įvesti failo pavadinimą bei pasirinkti ar naudoti medianą/vidukrį skaičiavimuose, jeigu toks failas neegzistuoja, programa baigia darbą.
- Pasirinkus atsitiktinį studentų duomenų failo generavimą, prašoma įvesti norimą sugeneruotų studentų skaičių, bei jų namų darbų skaičių.
- Pasirinkus studentų grupavimo testavimą, vartotojas yra prašomas įvesti norimą testuoti studentų skaičių, tada ieškomas failas pagal pasirinktą skaičių, pvz.: studentai1000.txt, jeigu jis nėra surastas, programa baigia darbą.
```

**Studentų grupavimo strategijų testavimas**

**1 Strategija**

Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius, ištrinant pradinį.

**2 Strategija**

Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Jei studentas yra vargsiukas,
jis įkeliamas į vargsiukų konteinerį ir ištrinamas iš pradinio studentų konteinerio. Tokiu būdu pradiniame lieka tik moksliukai.

**3 Strategija**

Strategija pritaikoma vector konteineriui pasinaudojant **std::partition**, **std::find_if** ir **std::copy** algoritmais. **std::partition** naudojamas vietoje **std::sort**, padedant pergrupuoti pradinį konteinerį pagal tinkamus ir netinkamus elementus. **std::find_if** naudojamas surasti poziciją studentų vektoriuje iki kur tiksliai yra tinkami elementai. Tada su **std::copy** nukopijuojame surastą dalį studentų konteinerio į vargšiukų konteinerį ir ištriname šiuos elementus iš studentų vektoriaus. 

**Rezultatai**

![1000](https://user-images.githubusercontent.com/113367128/201173288-44060974-ddef-4e40-93bc-19427488962f.png)
![10000](https://user-images.githubusercontent.com/113367128/201173290-a2cd3f1a-46c4-4b01-9a5a-7abfe624a46f.png)
![100000](https://user-images.githubusercontent.com/113367128/201173292-2fb95103-f521-40ce-8286-bcbe360d0f90.png)
![1000000](https://user-images.githubusercontent.com/113367128/201173295-50550483-5d5a-400c-9cff-ce3f456cbc04.png)
![10000000](https://user-images.githubusercontent.com/113367128/201173297-d858a860-88cb-4600-ae60-a561cd4771b0.png)


**Kompiuterio parametrai**

Ryzen 5 5600X

16GB 3600MHz

SSD 
