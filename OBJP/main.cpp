#include "myLib.h"
#include "funkcijos.h"

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
    if (klausimas0_1("\nAr skaityti duomenis is failo? 0 - Ne, 1 - Taip") == 0) {
        int studentuNr = 1;
        for (int i = 0; i < studentuNr; i++) {
            if(kont == 0){ pridetiStudenta(vek); }
            else if (kont == 1) { pridetiStudenta(sar); }
            else if (kont == 2) { pridetiStudenta(dek); }
            
            if (klausimas0_1("\nPrideti nauja irasa? 0 - Ne, 1 - Taip") == 1) {
                studentuNr++;
            }
        }
    }
    else {
        if (kont == 0) { skaitytiIsFailo(vek, visasLaikas); }
        else if (kont == 1) { skaitytiIsFailo(sar, visasLaikas); }
        else if (kont == 2) { skaitytiIsFailo(dek, visasLaikas); }
    }
    if (kont == 0) {
        skirstitiStudentus(vek, vek1, vek2);
        spausdinti(vek1, vek2, visasLaikas);
        cout << endl << vek1.size() + vek2.size() << " irasu visos programos vykdimo laikas: " << visasLaikas << " s" << endl;
    }
    else if (kont == 1) {
        skirstitiStudentus(sar, sar1, sar2);
        spausdinti(sar1, sar2, visasLaikas);
        cout << endl << sar1.size() + sar2.size() << " irasu visos programos vykdimo laikas: " << visasLaikas << " s" << endl;
    }
    else if (kont == 2) {
        skirstitiStudentus(dek, dek1, dek2);
        spausdinti(dek1, dek2, visasLaikas);
        cout << endl << dek1.size() + dek2.size() << " irasu visos programos vykdimo laikas: " << visasLaikas << " s" << endl;
    }
    cout << endl << "Iveskite bet koki simboli norint isjungti programa" << endl;
    cin >> temp;
    cin.ignore();

    return 0;
}