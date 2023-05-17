#include "Knjiga.h"
#include <iostream>
#include <iomanip>
#include "string.h"

Knjiga::Knjiga(const Knjiga& k) {
    strcpy(this->naziv,k.naziv);
    strcpy(this->pisac,k.pisac);
    this->rok_vracanja = k.rok_vracanja;
    this->stanje = k.stanje;
    this->id = k.id;
}

void Knjiga::setId(int id) {
    this->id = id;
}

void Knjiga::setNaziv() {
    std::cout << "Naziv: ";
    std::cin.getline(this->naziv, 100);
}

void Knjiga::setNaziv(char* n) {
    strcpy(this->naziv, n);
}

void Knjiga::setPisac() {
    std::cout << "Pisac: ";
    std::cin.getline(this->pisac, 100);
}

void Knjiga::setPisac(char *p) {
    strcpy(this->pisac, p);
}

void Knjiga::setRokVracanja() {
    std::cout << "Rok vracanja: ";
    std::cin>> this->rok_vracanja;
    std::cin.ignore();
}

void Knjiga::setRokVracanja(int r) {
    this->rok_vracanja = r;
}

void Knjiga::setStanje(Stanje s) {
    this->stanje=s;
}

int Knjiga::getId() {
    return this->id;
}

char *Knjiga::getNaziv() {
    return this->naziv;
}

char *Knjiga::getPisac() {
    return this->pisac;
}

int Knjiga::getRokVracanja() {
    return this->rok_vracanja;
}
Stanje Knjiga::getStanje() {
    return this->stanje;
}

std::istream &operator>>(std::istream &stream, Knjiga &k) {
    k.setNaziv();
    k.setPisac();
    k.setRokVracanja();
    k.stanje = slobodno;
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Knjiga &k) {
    std::cout << std::setw(2) << k.getId() << std::setw(17) <<  k.getNaziv() << std::setw(18) << k.getPisac() << std::setw(15);
    if(k.getStanje()==0){
        std::cout << "slobodno";
    } else{
        std::cout << "zauzeto";
    }
    std::cout << std::setw(15) << k.getRokVracanja();
    return stream;
}

bool Knjiga::usporedi(char *naziv) {
    return strcmpi(this->getNaziv(), naziv);
}








