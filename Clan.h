#ifndef PROJEKAT_CLAN_H
#define PROJEKAT_CLAN_H
#include <iostream>
#include <vector>
#include <string>

class Clan{
private:
    char ime[50];
    char prezime[50];
    int clanski_broj;
    static int max_zaduzenja;
    std::vector<int> knjige_id;
public:
    Clan(){};
    Clan(const Clan& c);

    void setIme();
    void setIme(char* i);
    void setPrezime();
    void setPrezime(char* p);
    void setClanskiBroj();
    void setClanskiBroj(int x);
    void setMaxZaduzenja();
    void setKnjigaId(int id_knjige);

    char* getIme();
    char* getPrezime();
    int getClanskiBroj();
    static int getMaxZaduzenja();
    std::vector<int> getKnjigeId();

    friend std::istream& operator>>(std::istream& stream, Clan& c);
    friend std::ostream& operator<<(std::ostream& stream, Clan& c);

    bool usporedi(int br);
    void ukloniKnjigaId(int id);

    ~Clan()=default;

};


#endif //PROJEKAT_CLAN_H
