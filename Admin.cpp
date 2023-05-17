#include "Admin.h"
#include <iostream>

void Admin::setIme() {
    std::cout << "Ime: ";
    std::cin.getline(this->ime, 50);
}

void Admin::setPrezime() {
    std::cout << "Prezime: ";
    std::cin.getline(this->prezime, 50);
}

char *Admin::getIme() {
    return this->ime;
}

char *Admin::getPrezime() {
    return this->prezime;
}

void Admin::setId(int id) {
    this->id = id;
}

int Admin::getId() {
    return this->id;
}
