#ifndef PROJEKAT_ZADUZENJE_H
#define PROJEKAT_ZADUZENJE_H
#include "Knjiga.h"
#include "Clan.h"
#include "Datum.h"

class Zaduzenje{
private:
    Knjiga knjiga;
    Clan clan;
    Datum datum_zaduzenja;
    Datum datum_vracanja;
public:
    Zaduzenje(){};
    Zaduzenje(const Zaduzenje& z);

    void setKnjiga(Knjiga k);
    void setClan(Clan c);
    void setDatumZaduzenja(Datum d);
    void setDatumVracanja();

    Knjiga getKnjiga();
    Clan getClan();
    Datum getDatumZaduzenja();
    Datum getDatumVracanja();

    //friend std::istream& operator>>(std::istream& stream, Zaduzenje& z);
    friend std::ostream& operator<<(std::ostream& stream, Zaduzenje& z);

    void postavi(Clan& c, Knjiga& k, Datum& d);

    ~Zaduzenje()=default;

};


#endif //PROJEKAT_ZADUZENJE_H
