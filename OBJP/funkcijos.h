#pragma once
struct studentas {
    string vardas, pavarde;
    int egzaminas;
    vector<int> pazymiai;
    double mediana, vidurkis;

    bool operator<(studentas& val) {
        if (vardas != val.vardas) {
            return vardas < val.vardas;
        }
        else {
            return pavarde < val.pavarde;
        }
    }
};
void atsitiktinisStudentas(studentas& stud, int nr, bool generuotiVisusPaz);
void pridetiPazymius(studentas& stud);
void pridetiStudenta(vector<studentas>& mas);
double vidurkis(vector<int> mas);
double mediana(vector<int> mas);
void spausdinti(vector<studentas> mas1, vector<studentas> mas2);
int klausimas0_1(string zinute);
void skaitytiIsFailo(vector<studentas>& mas);
void kurtiFaila(int studNr, int pazNr, string pavadinimas);
void skirstitiStudentus(vector<studentas>& studentai, vector<studentas>& vargsai, vector<studentas>& kietiakai);