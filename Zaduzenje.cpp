#include "Zaduzenje.h"
#include <iomanip>

Zaduzenje::Zaduzenje(const Zaduzenje& z) {
    this->clan = z.clan;
    this->knjiga = z.knjiga;
    this->datum_zaduzenja = z.datum_zaduzenja;
    this->datum_vracanja = z.datum_vracanja;
}

void Zaduzenje::setKnjiga(Knjiga k) {
    this->knjiga = k;
}

void Zaduzenje::setClan(Clan c) {
    this->clan = c;
}

void Zaduzenje::setDatumZaduzenja(Datum d) {
    this->datum_zaduzenja = d;
}

void Zaduzenje::setDatumVracanja() {
    int mjeseci[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int dani=0,dan,mjesec;
    for(int i=0; i<this->getDatumZaduzenja().getMjesec() ;i++)
        dani=dani+mjeseci[i];
    dani += this->getDatumZaduzenja().getDan() + this->getKnjiga().getRokVracanja();
    if(dani > 365) {
        dani=dani-365;
        this->datum_vracanja.setGodina(this->datum_zaduzenja.getGodina() + 1);
    } else{
        this->datum_vracanja.setGodina(this->datum_zaduzenja.getGodina());
    }
    for(int i=0; i<13; i++){
        dan=dani-mjeseci[i];
        if(dan<=mjeseci[i+1]){
            mjesec = i+1;
            break;
        }else
            dani=dan;
    }
    this->datum_vracanja.setDan(dan);
    this->datum_vracanja.setMjesec(mjesec);
}

Knjiga Zaduzenje::getKnjiga() {
    return this->knjiga;
}

Clan Zaduzenje::getClan() {
    return this->clan;
}

Datum Zaduzenje::getDatumZaduzenja() {
    return this->datum_zaduzenja;
}

void Zaduzenje::postavi(Clan& c, Knjiga& k, Datum& d){
    this->setClan(c);
    this->setKnjiga(k);
    this->setDatumZaduzenja(d);
    this->setDatumVracanja();
}

std::ostream &operator<<(std::ostream &stream, Zaduzenje &z) {
    std::cout << std::setw(2) << z.getClan().getClanskiBroj() << std::setw(15)  << z.getKnjiga().getId()
    << "  " << z.getKnjiga().getNaziv() << std::setw(15);
    z.getDatumZaduzenja().ispisiDatum();
    std::cout << std::setw(15);
    z.getDatumVracanja().ispisiDatum();
    std::cout << "\n";
    return stream;
}

Datum Zaduzenje::getDatumVracanja() {
    return this->datum_vracanja;
}
