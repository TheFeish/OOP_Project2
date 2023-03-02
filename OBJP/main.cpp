#include "myLib.h"
#include "funkcijos.h"

int main()
{
    vector<studentas> mas;
    int temp;
    if (klausimas0_1("Ar skaityti duomenis is failo? 0 - Ne, 1 - Taip") == 0) {
        int studentuNr = 1;
        for (int i = 0; i < studentuNr; i++) {
            pridetiStudenta(mas);
            if (klausimas0_1("\nPrideti nauja irasa? 0 - Ne, 1 - Taip") == 1) {
                studentuNr++;
            }
        }
    }
    else {
        skaitytiIsFailo(mas);
    }
    spausdinti(mas);
    cout << endl << "Iveskite bet koki simboli norint isjungti programa" << endl;
    cin >> temp;
    cin.ignore();
    return 0;
}