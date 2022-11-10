**#V1.0**

**Studentų grupavimo strategijų testavimas**

**1 Strategija**

Bendro studentai konteinerio (vector ir list tipų) skaidymas (rūšiavimas) į du naujus to paties tipo konteinerius, ištrinant pradinį.

**2 Strategija**

Bendro studentų konteinerio (vector ir list) skaidymas (rūšiavimas) panaudojant tik vieną naują konteinerį: "vargšiukai". Jei studentas yra vargsiukas,
jis įkeliamas į vargsiukų konteinerį ir ištrinamas iš pradinio studentų konteinerio. Tokiu būdu pradiniame lieka tik moksliukai.

**3 Strategija**

Strategija pritaikoma vector konteineriui pasinaudojant std::partition, std::find_if ir std::copy algoritmais. std::partition naudojamas vietoje std::sort, todėl tai ženkliai paspartina greitį.

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
