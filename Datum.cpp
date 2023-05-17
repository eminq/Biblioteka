#include "Datum.h"
#include <iostream>

Datum::Datum() {
    this->dan = 1;
    this->mjesec = 1;
    this->godina = 1900;
}
void Datum::setDan() {
    switch (this->mjesec) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            do{
                std::cout << "Unesite dan: ";
                std::cin >> this->dan;
                if(this->dan>31 || this->dan<1){
                    std::cout << "[GRESKA] Pogresan unos!\n";
                }
            }while(this->dan>31 || this->dan<1);
            break;
        case 4: case 6: case 9: case 11:
            do{
                std::cout << "Unesite dan: ";
                std::cin >> this->dan;
                if(this->dan>30 || this->dan<1){
                    std::cout << "[GRESKA] Pogresan unos!\n";
                }
            }while(this->dan>30 || this->dan<1);
            break;
        case 2:
            if(this->godina % 4 == 0){
                do{
                    std::cout << "Unesite dan: ";
                    std::cin >> this->dan;
                    if(this->dan>29 || this->dan<1){
                        std::cout << "[GRESKA] Pogresan unos!\n";
                    }
                }while(this->dan>29 || this->dan<1);
                break;
            }else{
                do{
                    std::cout << "Unesite dan: ";
                    std::cin >> this->dan;
                    if(this->dan>28 || this->dan<1){
                        std::cout << "[GRESKA] Pogresan unos!\n";
                    }
                }while(this->dan>28 || this->dan<1);
                break;
            }
        default:
            break;
    }
    std::cin.ignore();

}

void Datum::setMjesec() {
    do{
        std::cout << "Unesite mjesec: ";
        std::cin >> this->mjesec;
        if(this->mjesec<1 || this->mjesec>12){
            std::cout << "[GRESKA] Pogresan unos!\n";
        }
    }while(this->mjesec<1 || this->mjesec>12);
    std::cin.ignore();
}

void Datum::setGodina() {
    do{
        std::cout << "Unesite godinu: ";
        std::cin >> this->godina;
        if(this->godina<1900){
            std::cout << "[GRESKA] Pogresno unesena godina!\n";
        }
    }while(this->godina<1900);
    std::cin.ignore();
}
void Datum::setDan(int d) {
    this->dan = d;
}

void Datum::setMjesec(int m) {
    this->mjesec = m;
}

void Datum::setGodina(int g) {
    this->godina = g;
}

int Datum::getDan() {
    return this->dan;
}

int Datum::getMjesec() {
    return this->mjesec;
}

int Datum::getGodina() {
    return this->godina;
}

void Datum::postaviDatum() {
    this->setGodina();
    this->setMjesec();
    this->setDan();
}

void Datum::ispisiDatum() {
    std::cout << this->getDan() << "." << this->getMjesec() << "." << this->getGodina() << ".";
}

std::string Datum::getDatum() {
    std::string stringDan, stringMjesec;
    if(this->dan<10){
        stringDan = "0" + std::to_string(this->dan);
    }else{
        stringDan = std::to_string(this->dan);
    }
    if(this->mjesec<10){
        stringMjesec = "0" + std::to_string(this->mjesec);
    }else{
        stringDan = std::to_string(this->mjesec);
    }
    std::string result = stringDan + "." + stringMjesec + "." + std::to_string(this->godina);
    return result;
}






