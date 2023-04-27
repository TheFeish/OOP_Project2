#include "myLib.h"
#include "funkcijos.h"
#include "studentas.h"

int main()
{
    if (klausimas0_1("Ar kurti duomenu failus? 0 - Ne, 1 - Taip") == 1) {
        kurtiFaila(1000, 10, "kursiokai1000.txt");
        kurtiFaila(10000, 10, "kursiokai10000.txt");
        kurtiFaila(100000, 10, "kursiokai100000.txt");
        kurtiFaila(1000000, 10, "kursiokai1000000.txt");
        kurtiFaila(10000000, 10, "kursiokai10000000.txt");
    }

    int kont = -1;
    cout << "\nKoki konteinerio tipa naudoti? 0 - Vector, 1 - List, 2 - Deque" << endl;
    while (kont < 0 || kont > 2) {
        cin >> kont;
        if (kont < 0 || kont > 2 || cin.fail()) {
            cout << "Ivedete neteisinga reiksme" << endl;
            kont = -1;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    vector<studentas> vek;
    vector<studentas> vek1;
    vector<studentas> vek2;

    list<studentas> sar;
    list<studentas> sar1;
    list<studentas> sar2;

    deque<studentas> dek;
    deque<studentas> dek1;
    deque<studentas> dek2;

    int temp;
    double visasLaikas = 0;
    int alg = klausimas0_1("\nKaip skirstyti studentus? 0 - Senu budu, 1 - Nauju budu");
    if (klausimas0_1("\nAr skaityti duomenis is failo? 0 - Ne, 1 - Taip") == 0) {
        int studentuNr = 1;
        for (int i = 0; i < studentuNr; i++) {
            if(kont == 0){
                if (alg == 0) {
                    pridetiStudenta(vek);
                }
                else {
                    pridetiStudenta(vek1);
                }
            }
            else if (kont == 1) {
                if (alg == 0) {
                    pridetiStudenta(sar);
                }
                else {
                    pridetiStudenta(sar1);
                }
            }
            else if (kont == 2) {
                if (alg == 0) {
                    pridetiStudenta(dek);
                }
                else {
                    pridetiStudenta(dek1);
                }
            }
            
            if (klausimas0_1("\nPrideti nauja irasa? 0 - Ne, 1 - Taip") == 1) {
                studentuNr++;
            }
        }
    }
    else {
        if (kont == 0) {
            if (alg == 0) {
                skaitytiIsFailo(vek, visasLaikas);
            }
            else {
                skaitytiIsFailo(vek1, visasLaikas);
            }
        }
        else if (kont == 1) {
            if (alg == 0) {
                skaitytiIsFailo(sar, visasLaikas);
            }
            else {
                skaitytiIsFailo(sar1, visasLaikas);
            }
        }
        else if (kont == 2) {
            if (alg == 0) {
                skaitytiIsFailo(dek, visasLaikas);
            }
            else {
                skaitytiIsFailo(dek1, visasLaikas);
            }
        }
    }
    int rusiavimas = klausimas0_1("\nKaip skaiciuoti galutini studento pazymi? 0 - Naudojant vidurki, 1 - naudojant mediana");
    if (kont == 0) {
        if (alg == 0) {
            skirstitiStudentus(vek, vek2, vek1, rusiavimas, visasLaikas);
        }
        else {
            skirstitiStudentus2(vek1, vek2, rusiavimas, visasLaikas);
        }
        spausdinti(vek1, vek2, rusiavimas, visasLaikas);
        cout << endl << vek1.size() + vek2.size() << " irasu visos programos vykdimo laikas: " << visasLaikas << " s" << endl;
    }
    else if (kont == 1) {
        if (alg == 0) {
            skirstitiStudentus(sar, sar2, sar1, rusiavimas, visasLaikas);
        }
        else {
            skirstitiStudentus2(sar1, sar2, rusiavimas, visasLaikas);
        }
        spausdinti(sar1, sar2, rusiavimas, visasLaikas);
        cout << endl << sar1.size() + sar2.size() << " irasu visos programos vykdimo laikas: " << visasLaikas << " s" << endl;
    }
    else if (kont == 2) {
        if (alg == 0) {
            skirstitiStudentus(dek, dek2, dek1, rusiavimas, visasLaikas);
        }
        else {
            skirstitiStudentus2(dek1, dek2, rusiavimas, visasLaikas);
        }
        spausdinti(dek1, dek2, rusiavimas, visasLaikas);
        cout << endl << dek1.size() + dek2.size() << " irasu visos programos vykdimo laikas: " << visasLaikas << " s" << endl;
    }
    cout << endl << "Iveskite bet koki simboli norint isjungti programa" << endl;
    cin >> temp;
    cin.ignore();

    return 0;
}