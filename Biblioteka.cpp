#include <memory>
#include "Biblioteka.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <ctime>
#include <stdio.h>

void Biblioteka::setClan(Clan &c) {
    this->clanovi.push_back(c);
}

void Biblioteka::setKnjiga(Knjiga &k) {
    this->knjige.push_back(k);
}

void Biblioteka::setZaduzenje(Zaduzenje& z) {
    this->zaduzenja.push_back(z);
}

std::vector<Clan> Biblioteka::getClanovi() {
    return this->clanovi;
}

std::vector<Knjiga> Biblioteka::getKnjige() {
    return this->knjige;
}

std::vector<Zaduzenje> &Biblioteka::getZaduzenja() {
    return this->zaduzenja;
}

void Biblioteka::noviClan() {
    std::fstream ispisi("clanovi.txt",std::ios::app);
    std::shared_ptr<Clan> temp = std::make_shared<Clan>();
    std::cin >> *temp;
    this->setClan(*temp);
    if(!ispisi.is_open()){
        std::cout << "Fajl nije otvoren.";
    }else{
        ispisi << "clanski_br: " << temp->getClanskiBroj() << "\nime: " << temp->getIme() << "\nprezime: " << temp->getPrezime() << "\n";
    }
    ispisi.close();
}

void Biblioteka::ispisClanova() {
    std::cout<<std::setw(2)<<"Cl.broj"<<std::setw(13)<<"Ime"<<std::setw(18)<<"Prezime"<<std::setw(18)<<"Zad.1"<<std::setw(15)
             <<"Zad.2"<<std::setw(15)<<"Zad.3\n";
    std::cout << "==================================================================================================" << std::endl;
    for(int i=0; i< this->clanovi.size(); i++){
        std::cout << this->clanovi[i] << "\n";
    }
}

void Biblioteka::dodajKnjigu() {
    std::fstream ispisi("knjige.txt",std::ios::app);
    srand(time(NULL));
    bool postoji;
    int n, id;
    std::unique_ptr<Knjiga> temp = std::make_unique<Knjiga>();
    std::cin >> *temp;
    std::cout << "Kolicina: ";
    std::cin >> n;
    for(int i=0; i<n; i++){
        do {
            postoji = false;
            id = rand()%1000+1;
            for(int i=0; i< this->getKnjige().size(); i++){
                if(id == this->getKnjige()[i].getId()){
                    postoji = true;
                    break;
                }
            }
        } while (postoji);
        temp->setId(id);
        this->setKnjiga(*temp);
        if(!ispisi.is_open()){
            std::cout << "Fajl nije otvoren.";
        }
        ispisi << "id: " << temp->getId() << "\nnaziv: " << temp->getNaziv() << "\npisac: " << temp->getPisac() << "\nrok: " << temp->getRokVracanja() << "\n";
    }
    ispisi.close();
}

void Biblioteka::ispisKnjiga() {
    std::cout<<std::setw(2)<<"ID"<<std::setw(15)<<"Naziv"<<std::setw(20)<<"Pisac"<<std::setw(20)<<"Stanje"
             <<std::setw(18)<<"Rok vracanja\n";
    std::cout << "==============================================================================" << std::endl;
    for(int i=0; i< this->knjige.size(); i++){
        std::cout << this->knjige[i] << "\n";
    }
}

void Biblioteka::pretragaClana(int br) {
    bool pronadjen=false;
    for(int i=0; i< this->clanovi.size(); i++){
        if(this->clanovi[i].usporedi(br)==true){
            std::cout<<std::setw(2)<<"Cl.broj"<<std::setw(13)<<"Ime"<<std::setw(18)<<"Prezime"<<std::setw(18)<<"Zad.1"<<std::setw(15)
                     <<"Zad.2"<<std::setw(15)<<"Zad.3\n";
            std::cout << "==================================================================================================" << std::endl;
            std::cout << this->clanovi[i];
            pronadjen=true;
        }
    }
    if(!pronadjen){
        std::cout<<"Clan sa clanskim brojem "<<br<<" ne postoji.";
    }
}

void Biblioteka::pretragaKnjige(char* naziv) {
    bool pronadjen= false;
    std::cout<<std::setw(2)<<"ID"<<std::setw(15)<<"Naziv"<<std::setw(20)<<"Pisac"<<std::setw(20)<<"Stanje"
             <<std::setw(18)<<"Rok vracanja\n";
    std::cout << "==============================================================================" << std::endl;
    for(int i=0; i<this->knjige.size(); i++){
        if(this->knjige[i].usporedi(naziv)==0){
            std::cout << this->knjige[i] << "\n";
            pronadjen=true;
        }
    }
    if(!pronadjen){
        std::cout<<"Knjiga sa nazivom "<<naziv<<" ne postoji.";
    }
}

void Biblioteka::novoZaduzenje() {
    std::shared_ptr<Zaduzenje> zaduzenje = std::make_shared<Zaduzenje>();
    std::shared_ptr<Clan> tempClan = std::make_shared<Clan>();
    std::shared_ptr<Knjiga> tempKnjiga = std::make_shared<Knjiga>();
    std::shared_ptr<Datum> tempDatum = std::make_shared<Datum>();
    std::fstream ispisi("zaduzenja.txt",std::ios::app);
    int clan_br;
    char naziv[100];
    bool postoji = false;
    std::cout<<"\n*** Novo zaduzenje ***\n";
    try {
        std::cout << "Clanski broj clana: ";
        std::cin >> clan_br;
        std::cin.ignore();
        for (int i = 0; i < this->clanovi.size(); i++) {
            if (this->clanovi[i].getClanskiBroj() == clan_br) {
                *tempClan = this->clanovi[i];
                postoji = true;
            }
        }
        if (!postoji) {
            throw "[GRESKA] Clan sa tim clanskim brojem ne postoji!";
        }
        if(tempClan->getKnjigeId().size()==3){
            throw "[GRESKA] Ovaj clan ima 3 zaduzene knjige.";
        }
        postoji = false;
        bool slobodna=false;
        std::cout << "Naziv knjige: ";
        std::cin.getline(naziv, 100);
        for (int i = 0; i < this->getKnjige().size(); i++) {
            if (this->getKnjige()[i].usporedi(naziv) == 0) {
                postoji = true;
                if(this->knjige[i].getStanje() == slobodno){
                    slobodna = true;
                    this->knjige[i].setStanje(zauzeto);
                    *tempKnjiga = this->knjige[i];
                    break;
                }
            }
        }
        if (!postoji) {
            throw "[GRESKA] Knjiga sa tim nazivom ne postoji.";
        }
        if (!slobodna) {
            throw "[GRESKA] Nema niti jedne slobodne knjige sa tim nazivom.";
        }

        std::cout << "Datum.\n ";
        tempDatum->postaviDatum();
        for (int i = 0; i < this->clanovi.size(); i++) {
            if (this->clanovi[i].getClanskiBroj() == clan_br) {
                this->clanovi[i].setKnjigaId(tempKnjiga->getId());
            }
        }
        zaduzenje->postavi(*tempClan, *tempKnjiga, *tempDatum);
        std::cout<<std::setw(2)<<"Clan"<<std::setw(20)<< "ID   Naziv" <<std::setw(30)<<"Datum zaduzenja"<<std::setw(15)<<"Rok\n";
        std::cout << "================================================================================" << std::endl;
        std::cout << *zaduzenje;
        this->setZaduzenje(*zaduzenje);
    }catch(const char* poruka){
        std::cout<<poruka<<"\n";
    }
    if(!ispisi.is_open()){
        std::cout << "Fajl nije otvoren.";
    }else{
        ispisi << "knjiga_id: " << tempKnjiga->getId() << "\nbr_clana: " << tempClan->getClanskiBroj() <<
        "\ngodina_zaduzenja: " << tempDatum->getGodina() << "\nmjesec_zaduzenja: " << tempDatum->getMjesec() << "\ndan_zaduzenja: " << tempDatum->getDan() << "\n";
    }
}

void Biblioteka::pregledZaduzenja() {
    std::cout<<"\n***PREGLED ZADUZENJA***\n";
    std::cout<<std::setw(2)<<"Clan"<<std::setw(20)<< "ID   Naziv" <<std::setw(30)<<"Datum zaduzenja"<<std::setw(15)<<"Rok\n";
    std::cout << "================================================================================" << std::endl;
    for(int i=0; i<this->zaduzenja.size(); i++){
        std::cout << this->zaduzenja[i];
    }
}

void Biblioteka::postaviBiblioteku() {
    // CLANOVI
    std::shared_ptr<Clan> tempClan = std::make_shared<Clan>();
    std::string tempStr = "";
    std::string rijec;
    int broj;
    std::ifstream ucitaj;
    ucitaj.open("clanovi.txt", std::ifstream::in);
    if(!ucitaj.is_open()) std::cout << "Fajl ne postoji.";
    ucitaj >> rijec;
    while(!ucitaj.eof()){
        if(rijec == "clanski_br:"){
            ucitaj >> broj;
            tempClan->setClanskiBroj(broj);
            ucitaj >> rijec;
        }
        tempStr = "";
        if(rijec == "ime:"){
            ucitaj >> rijec;
            while (rijec!="prezime:"){
                tempStr += rijec;
                ucitaj >> rijec;
                if(rijec!="prezime:"){
                    tempStr += " ";
                }
            }
            char temp[tempStr.length()+1];
            strcpy(temp, tempStr.c_str());
            tempClan->setIme(temp);
        }
        tempStr = "";
        if(rijec == "prezime:"){
            ucitaj >> rijec;
            while (rijec!="clanski_br:"){
                tempStr += rijec;
                ucitaj >> rijec;
                if(ucitaj.eof()){
                    break;
                }
                if(rijec!="clanski_br:"){
                    tempStr += " ";
                }
            }
            char temp[tempStr.length()+1];
            strcpy(temp, tempStr.c_str());
            tempClan->setPrezime(temp);
        }
        this->setClan(*tempClan);
        if(ucitaj.eof()){
            break;
        }
    }
    ucitaj.close();
    // KNJIGA
    std::shared_ptr<Knjiga> tempKnjiga = std::make_shared<Knjiga>();
    ucitaj.open("knjige.txt", std::ifstream::in);
    if(!ucitaj.is_open()) std::cout << "Fajl ne postoji.";
    ucitaj >> rijec;
    while(!ucitaj.eof()){
        if(rijec == "id:"){
            ucitaj >> broj;
            tempKnjiga->setId(broj);
            ucitaj >> rijec;
        }
        tempStr = "";
        if(rijec == "naziv:"){
            ucitaj >> rijec;
            while(rijec!="pisac:"){
                tempStr += rijec;
                ucitaj >> rijec;
                if(rijec!="pisac:"){
                    tempStr += " ";
                }
            }
            char temp[tempStr.length()+1];
            strcpy(temp, tempStr.c_str());
            tempKnjiga->setNaziv(temp);
        }
        tempStr = "";
        if(rijec == "pisac:"){
            ucitaj >> rijec;
            while(rijec!="rok:"){
                tempStr += rijec;
                ucitaj >> rijec;
                if(rijec!="rok:"){
                    tempStr += " ";
                }
            }
            char temp[tempStr.length()+1];
            strcpy(temp, tempStr.c_str());
            tempKnjiga->setPisac(temp);
        }
        if(rijec == "rok:"){
            ucitaj >> broj;
            tempKnjiga->setRokVracanja(broj);
        }
        tempKnjiga->setStanje(slobodno);
        this->setKnjiga(*tempKnjiga);
        ucitaj >> rijec;
        if(ucitaj.eof()){
            break;
        }
    }
    ucitaj.close();
    // ZADUZENJA
    std::shared_ptr<Zaduzenje> tempZaduzenje = std::make_shared<Zaduzenje>();
    std::shared_ptr<Datum> tempDatum = std::make_shared<Datum>();
    ucitaj.open("zaduzenja.txt", std::ifstream::in);
    if(!ucitaj.is_open()) std::cout << "Fajl ne postoji.";
    ucitaj >> rijec;
    while(!ucitaj.eof()){
        if(rijec == "knjiga_id:"){
            ucitaj >> broj;
            for(int i=0; i< this->getKnjige().size(); i++){
                if(this->getKnjige()[i].getId()==broj){
                    tempZaduzenje->setKnjiga(this->getKnjige()[i]);
                    this->knjige[i].setStanje(zauzeto);
                }
            }
            ucitaj >> rijec;
        }
        if(rijec == "br_clana:"){
            ucitaj >> broj;
            for(int i=0; i< this->getClanovi().size(); i++){
                if(this->getClanovi()[i].getClanskiBroj()==broj){
                    tempZaduzenje->setClan(this->getClanovi()[i]);
                    this->clanovi[i].setKnjigaId(tempZaduzenje->getKnjiga().getId());
                }
            }
            ucitaj >> rijec;
        }
        if(rijec == "godina_zaduzenja:"){
            ucitaj >> broj;
            tempDatum->setGodina(broj);
            ucitaj >> rijec;
        }
        if(rijec == "mjesec_zaduzenja:"){
            ucitaj >> broj;
            tempDatum->setMjesec(broj);
            ucitaj >> rijec;
        }
        if(rijec == "dan_zaduzenja:"){
            ucitaj >> broj;
            tempDatum->setDan(broj);
            ucitaj >> rijec;
        }
        tempZaduzenje->setDatumZaduzenja(*tempDatum);
        tempZaduzenje->setDatumVracanja();
        this->setZaduzenje(*tempZaduzenje);
        if(ucitaj.eof()){
            break;
        }
    }

}

void Biblioteka::vracanjeKnjige() {
    bool postoji= false;
    int id_knjige;
    int br;
    try {
        std::cout << "Clanski broj clana: ";
        std::cin >> br;
        std::cin.ignore();
        for (int i = 0; i < this->clanovi.size(); i++) {
            if (this->clanovi[i].getClanskiBroj() == br) {
                std::cout << "\n***PREGLED ZADUZENJA***\n";
                std::cout<<std::setw(2)<<"Clan"<<std::setw(20)<< "ID   Naziv" <<std::setw(30)<<"Datum zaduzenja"<<std::setw(15)<<"Rok\n";
                std::cout << "================================================================================" << std::endl;
                if(this->clanovi[i].getKnjigeId().size()==0){
                    std::cout << "\nOvaj clan nema zaduzenja.";
                    postoji = true;
                    break;
                }
                for(int i=0; i<this->getZaduzenja().size(); i++){
                    if(this->getZaduzenja()[i].getClan().getClanskiBroj()==br){
                        std::cout << this->getZaduzenja()[i];
                    }
                }
                std::cout << "\nID knjige:";
                do{
                    postoji = false;
                    std::cin >> id_knjige;
                    for (int j = 0; j < this->clanovi[i].getKnjigeId().size(); j++){
                        if (this->clanovi[i].getKnjigeId()[j] == id_knjige) {
                            postoji = true;
                            this->clanovi[i].ukloniKnjigaId(id_knjige);
                        }
                    }
                    if(!postoji){
                        std::cout << "Pogresan id. Pokusajte ponovo.\n";
                    }
                } while (!postoji);
                for(int i=0; i<this->getKnjige().size(); i++){
                    if(this->getKnjige()[i].getId() == id_knjige){
                        this->knjige[i].setStanje(slobodno);
                    }
                }
                for(int i=0; i<this->getZaduzenja().size(); i++){
                    if(this->getZaduzenja()[i].getKnjiga().getId() == id_knjige){
                        this->zaduzenja.erase(this->zaduzenja.begin()+i);
                    }
                }
                std::fstream ispisi("zaduzenja.txt", std::ios::out);
                for(int i=0; i<this->getZaduzenja().size(); i++){
                    if(!ispisi.is_open()){
                        std::cout << "Fajl nije otvoren.";
                    }else{
                        ispisi << "knjiga_id: " << this->getZaduzenja()[i].getKnjiga().getId() <<
                                  "\nbr_clana: " << this->getZaduzenja()[i].getClan().getClanskiBroj() <<
                                  "\ngodina_zaduzenja: " << this->getZaduzenja()[i].getDatumZaduzenja().getGodina() <<
                                  "\nmjesec_zaduzenja: " << this->getZaduzenja()[i].getDatumZaduzenja().getMjesec() <<
                                  "\ndan_zaduzenja: " << this->getZaduzenja()[i].getDatumZaduzenja().getDan() << "\n";
                    }
                }
                ispisi.close();
            }
        }
        if (!postoji) {
            throw "[GRESKA] Clan sa tim clanskim brojem ne postoji!";
        }
    }catch(const char* poruka) {
        std::cout << poruka;
    }
}




