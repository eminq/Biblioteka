#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Biblioteka.h"



int meni(){
    int x;
    std::cout<< "\n**** MENI ****\n";
    std::cout<< "1. Novi clan\n";
    std::cout<< "2. Pregled clanova\n";
    std::cout<< "3. Pretraga clana\n";
    std::cout<< "4. Dodavanje knjige\n";
    std::cout<< "5. Pregled knjiga\n";
    std::cout<< "6. Pretraga knjiga \n";
    std::cout<< "7. Novo zaduzenje\n";
    std::cout<< "8. Pregled zaduzenja\n";
    std::cout<< "9. Vracanje knjige\n";
    std::cout<< "10. IZLAZ.\n";
    std::cout<< "Izbor: ";
    do{
        std::cin >> x;
        std::cin.ignore();
    }while(x<1 || x>10);
    return x;
}


int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    Biblioteka b;
    b.postaviBiblioteku();

    int izbor;
    do{
        izbor = meni();
        switch (izbor) {
            case 1:
                b.noviClan();
                b.ispisClanova();
                break;
            case 2:
                b.ispisClanova();
                break;
            case 3:
                int x;
                std::cout << "Unesite clanski broj: ";
                std::cin >> x;
                b.pretragaClana(x);
                break;
            case 4:
                b.dodajKnjigu();
                break;
            case 5:
                b.ispisKnjiga();
                break;
            case 6:
                char naziv[100];
                std::cout << "Unesite naziv knjige: ";
                std::cin.getline(naziv, 100);
                b.pretragaKnjige(naziv);
                break;
            case 7:
                b.novoZaduzenje();
                break;
            case 8:
                b.pregledZaduzenja();
                break;
            case 9:
                b.vracanjeKnjige();
                break;
            default:
                std::cout << "\nHvala i dovidjenja!";
                break;
        }
    }while(izbor!=10);
    return 0;
}


