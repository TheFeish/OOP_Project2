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
    vector<studentas> mas;
    vector<studentas> mas1;
    vector<studentas> mas2;
    double visasLaikas = 0;
    int temp;
    if (klausimas0_1("\nAr skaityti duomenis is failo? 0 - Ne, 1 - Taip") == 0) {
        int studentuNr = 1;
        for (int i = 0; i < studentuNr; i++) {
            pridetiStudenta(mas);
            if (klausimas0_1("\nPrideti nauja irasa? 0 - Ne, 1 - Taip") == 1) {
                studentuNr++;
            }
        }
    }
    else {
        skaitytiIsFailo(mas, visasLaikas);
    }
    skirstitiStudentus(mas, mas1, mas2);
    spausdinti(mas1, mas2, visasLaikas);
    cout << endl << mas1.size() + mas2.size() << " irasu visos programos vykdimo laikas: " << visasLaikas << " s" << endl;
    cout << endl << "Iveskite bet koki simboli norint isjungti programa" << endl;
    cin >> temp;
    cin.ignore();

    return 0;
}