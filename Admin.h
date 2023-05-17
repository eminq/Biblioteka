#ifndef PROJEKAT_ADMIN_H
#define PROJEKAT_ADMIN_H


class Admin{
private:
    char ime[50];
    char prezime[50];
    int id;
public:
    Admin(){};

    void setId(int id);
    void setIme();
    void setPrezime();

    int getId();
    char* getIme();
    char* getPrezime();


    ~Admin()=default;

};


#endif //PROJEKAT_ADMIN_H
