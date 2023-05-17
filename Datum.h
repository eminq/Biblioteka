#include <string>

class Datum {
private:
    int dan, mjesec, godina;
public:
    Datum();
    void setDan();
    void setDan(int d);
    void setMjesec();
    void setMjesec(int m);
    void setGodina();
    void setGodina(int g);

    int getDan();
    int getMjesec();
    int getGodina();

    void postaviDatum();
    void ispisiDatum();

    std::string getDatum();

    ~Datum(){};

};

