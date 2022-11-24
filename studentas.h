#include "mylib.h"

class Studentas
{
private:
    string vardas_= "";
    string pavarde_ = "";
    vector <int>nd_;
    int egz_;
    double rez_;
    double medvid_;

public:
    Studentas() {
        egz_ = 0;
        rez_ = 0;
        medvid_ = 0;
    }
    ~Studentas(){ nd_.clear(); }
    Studentas(const Studentas &s)
    {
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        egz_ = s.egz_;
        copy(s.nd_.begin(), s.nd_.end(), nd_.begin());
        rez_=s.rez_;
        medvid_=s.medvid_;
    }
    Studentas& operator=(const Studentas& s)
    {
        if (this == &s)
        {
            return *this;
        }
        vardas_ = s.vardas_;
        pavarde_ = s.pavarde_;
        std::copy(s.nd_.begin(), s.nd_.end(), nd_.begin());
        egz_ = s.egz_;
        rez_ = s.rez_;
        medvid_ = s.medvid_;
        return *this;
    }
    inline string getVardas() const { return vardas_; }
    void setVardas(string vardas) { vardas_ = vardas; }    // get'eriai, inline
    inline string getPavarde() const { return pavarde_; }// get'eriai, inline
    void setPavarde(string pavarde) { pavarde_= pavarde; }

    double getNd(int i) const { return nd_.at(i); }
    void setNd(int nd,int index) { nd_[index]=nd; }
    void addNd(int nd){
        nd_.reserve(nd_.size() + 1);
        nd_.push_back(nd); }
    void clearNd() { nd_.clear(); }
    inline int getNdSize() { return nd_.size(); }
    void sortNd() { sort(nd_.begin(), nd_.end()); }

    inline int getEgz() const { return egz_; }
    void setEgz(int egz) { egz_ = egz; }

    inline double getRez() const { return rez_; }
    void setRez(double rez) { rez_ = rez; }

    inline double getMedVid() const { return medvid_; }
    void setMedVid(double med_vid) { medvid_ = med_vid; }

    void readfromFile(string filename, vector<Studentas> &sar, int &studentu_skaicius, int &ndSk);
    double median();
    double avg();
    double skaiciuotiGalutini();
    void read(int nr);
    void print();
};

bool compare(Studentas a, Studentas b);

