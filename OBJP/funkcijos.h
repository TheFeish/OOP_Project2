#pragma once
struct studentas {
    string vardas, pavarde;
    int egzaminas;
    double mediana, vidurkis;

    bool operator<(studentas& val) {
        return pavarde < val.pavarde;
    }
};
void atsitiktinisStudentas(studentas& stud);
void pridetiPazymius(studentas& stud);
void pridetiStudenta(vector<studentas>& mas);
double vidurkis(vector<int> mas);
double mediana(vector<int> mas);
void spausdinti(vector<studentas> mas);
int klausimas0_1(string zinute);
void skaitytiIsFailo(vector<studentas>& mas);