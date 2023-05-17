#include "Clan.h"
#include <iostream>
#include <string.h>
#include <iomanip>

int Clan::max_zaduzenja = 3;

Clan::Clan(const Clan &c) {
    strcpy(this->ime,c.ime);
    strcpy(this->prezime,c.prezime);
    this->clanski_broj = c.clanski_broj;
    this->max_zaduzenja = c.max_zaduzenja;

}
void Clan::setIme() {
    std::cout << "Ime: ";
    std::cin.getline(this->ime, 50);
}

void Clan::setIme(char* i) {
    strcpy(this->ime,i);
}

void Clan::setPrezime() {
    std::cout << "Prezime: ";
    std::cin.getline(this->prezime, 50);
}

void Clan::setPrezime(char *p) {
    strcpy(this->prezime,p);
}

void Clan::setClanskiBroj() {
    std::cout << "Clanski broj: ";
    std::cin>>this->clanski_broj;
    std::cin.ignore();
}

void Clan::setClanskiBroj(int x) {
    this->clanski_broj = x;
}

void Clan::setKnjigaId(int id_knjige) {
    this->knjige_id.push_back(id_knjige);
}

void Clan::setMaxZaduzenja() {
    Clan::max_zaduzenja = 3;
}

char *Clan::getIme() {
    return this->ime;
}

char *Clan::getPrezime() {
    return this->prezime;
}


int Clan::getClanskiBroj() {
    return this->clanski_broj;
}

int Clan::getMaxZaduzenja() {
    return Clan::max_zaduzenja;
}

std::vector<int> Clan::getKnjigeId(){
    return this->knjige_id;
}

std::istream &operator>>(std::istream &stream, Clan &c) {
    c.setClanskiBroj();
    c.setIme();
    c.setPrezime();
    c.setMaxZaduzenja();
    return stream;
}

std::ostream &operator<<(std::ostream &stream, Clan &c) {
    std::cout << std::setw(2)<< c.getClanskiBroj() << std::setw(20) << c.getIme() << std::setw(17) << c.getPrezime() << std::setw(17);
    for(int i=0; i<c.getKnjigeId().size(); i++){
        std::cout << c.getKnjigeId()[i] << std::setw(15);
    }
    return stream;
}

bool Clan::usporedi(int br){
    return this->clanski_broj == br;
}

void Clan::ukloniKnjigaId(int id) {
    for(int i=0; i< this->getKnjigeId().size(); i++){
        if(this->getKnjigeId()[i] == id){
            this->knjige_id.erase(this->knjige_id.begin()+i);
        }
    }
}








