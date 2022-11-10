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
double median(vector<int> &a, int n);
double avg(vector<int> &arr, int n);
double skaiciuotiGalutini(double temp, double egz);
Studentas read(int nr);
void print(Studentas s);
void readfromFile(string filename,vector<Studentas> &sar,int &studentu_skaicius);
bool compare(Studentas a, Studentas b);
void generuotiFailus(int &studentu_skaicius,int ndSk);
int pasirinktiMedArVid(int &pasirinkimas);
void pirmaStrategija(vector<Studentas>&sar, vector<Studentas> &vargsiukai, vector<Studentas> &moksliukai);
void printToFile(string filename, vector<Studentas> &sar, int ndSkaicius);
void readfromFile(string filename, list<Studentas> &sar, int &studentu_skaicius);
void pirmaStrategija(list<Studentas>&sar, list<Studentas> &vargsiukai, list<Studentas> &moksliukai);
void antraStrategija(vector<Studentas>&sar, vector<Studentas> &vargsiukai);
void antraStrategija(list<Studentas>&sar, list<Studentas> &vargsiukai);
void vectorOptimizacija(vector<Studentas> &sar, vector <Studentas> &vargsiukai);

#endif
