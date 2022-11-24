#include "mylib.h"

class Studentas
{
private:
    string c_vardas = "";
    string c_pavarde = "";
    vector <int>c_nd;
    int c_egz;
    int c_sum;
    double c_rez;
    double c_med_vid;

public:
    Studentas() {
        c_egz = 0;
        c_sum = 0;
        c_rez = 0;
        c_med_vid = 0;
    }
    inline string getVardas() const { return c_vardas; }
    void setVardas(string vardas) { c_vardas = vardas; }    // get'eriai, inline
    inline string getPavarde() const { return c_pavarde; }// get'eriai, inline
    void setPavarde(string pavarde) { c_pavarde= pavarde; }

    double getNd(int i) const { return c_nd.at(i); }
    void setNd(int nd,int index) { c_nd[index]=nd; }
    void addNd(int nd){
        c_nd.reserve(c_nd.size() + 1);
        c_nd.push_back(nd); }
    void clearNd() { c_nd.clear(); }
    inline int getNdSize() { return c_nd.size(); }
    void sortNd() { sort(c_nd.begin(), c_nd.end()); }

    inline int getEgz() const { return c_egz; }
    void setEgz(int egz) { c_egz = egz; }

    inline double getRez() const { return c_rez; }
    void setRez(double rez) { c_rez = rez; }

    inline double getMedVid() const { return c_med_vid; }
    void setMedVid(double med_vid) { c_med_vid = med_vid; }

    void readfromFile(string filename, vector<Studentas> &sar, int &studentu_skaicius, int &ndSk);
    double median();
    double avg();
    double skaiciuotiGalutini();
    void read(int nr);
    void print();
};

bool compare(Studentas a, Studentas b);

