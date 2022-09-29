#ifndef FUNKCIJOS_H_INCLUDED
#define FUNKCIJOS_H_INCLUDED

#include "mylib.h"


struct Studentas{
    string vardas;
    string pavarde;
    vector<int> ndRezultatai;
    int egzRez;
    double galutinis;
    int namuDarbuSk=0;
};

void intIvedimas(int &priskirti, int lowerBound, int upperBound, int stoppage=-999);
double median(vector<int> a, int n);
double avg(vector<int> arr, int n);
double skaiciuotiGalutini(double temp, double egz);
Studentas read(int nr);
void print(Studentas s);
void readfromFile(vector<Studentas> &sar);
bool compare(Studentas a, Studentas b);

#endif
