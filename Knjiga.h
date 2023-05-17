#ifndef PROJEKAT_KNJIGA_H
#define PROJEKAT_KNJIGA_H
#include <iostream>

enum Stanje{slobodno=0, zauzeto};
class Knjiga {
private:
    int id;
    char naziv[100];
    char pisac[100];
    int rok_vracanja;
    Stanje stanje;
public:
    Knjiga(){};
    Knjiga(const Knjiga& k);
    void setId(int id);
    void setNaziv();
    void setNaziv(char* n);
    void setPisac();
    void setPisac(char* p);
    void setRokVracanja();
    void setRokVracanja(int r);
    void setStanje(Stanje s);

    int getId();
    char* getNaziv();
    char* getPisac();
    int getRokVracanja();
    Stanje getStanje();


    friend std::istream& operator>>(std::istream& stream, Knjiga& k);
    friend std::ostream& operator<<(std::ostream& stream, Knjiga& k);

    bool usporedi(char* naziv);

    ~Knjiga()=default;
};


#endif //PROJEKAT_KNJIGA_H
