#ifndef PROJEKAT_BIBLIOTEKA_H
#define PROJEKAT_BIBLIOTEKA_H

#include "Clan.h"
#include "Knjiga.h"
#include "Zaduzenje.h"
#include <vector>

class Biblioteka {
private:
    std::vector<Clan> clanovi;
    std::vector<Knjiga> knjige;
    std::vector<Zaduzenje> zaduzenja;
public:
    Biblioteka(){};

    void setClan(Clan& c);
    void setKnjiga(Knjiga& k);
    void setZaduzenje(Zaduzenje& z);

    std::vector<Clan> getClanovi();
    std::vector<Knjiga> getKnjige();
    std::vector<Zaduzenje>& getZaduzenja();


    void noviClan();
    void ispisClanova();
    void dodajKnjigu();
    void ispisKnjiga();
    void pretragaClana(int br);
    void pretragaKnjige(char* naziv);
    void novoZaduzenje();
    void pregledZaduzenja();
    void vracanjeKnjige();

    void postaviBiblioteku();

    ~Biblioteka()=default;
};


#endif //PROJEKAT_BIBLIOTEKA_H
