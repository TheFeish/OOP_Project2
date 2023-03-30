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
//-------------------------------------------------------------------------------------------------------------
void pridetiStudenta(vector<studentas>& mas);
void pridetiStudenta(list<studentas>& mas);
void pridetiStudenta(deque<studentas>& mas);
//-------------------------------------------------------------------------------------------------------------
double vidurkis(vector<int> mas);
double mediana(vector<int> mas);
//-------------------------------------------------------------------------------------------------------------
void spausdinti(vector<studentas> mas1, vector<studentas> mas2, double& visasLaikas);
void spausdinti(list<studentas> mas1, list<studentas> mas2, double& visasLaikas);
void spausdinti(deque<studentas> mas1, deque<studentas> mas2, double& visasLaikas);
//-------------------------------------------------------------------------------------------------------------
int klausimas0_1(string zinute);
//-------------------------------------------------------------------------------------------------------------
void skaitytiIsFailo(vector<studentas>& mas, double& visasLaikas);
void skaitytiIsFailo(list<studentas>& mas, double& visasLaikas);
void skaitytiIsFailo(deque<studentas>& mas, double& visasLaikas);
//-------------------------------------------------------------------------------------------------------------
void kurtiFaila(int studNr, int pazNr, string pavadinimas);
//-------------------------------------------------------------------------------------------------------------
void skirstitiStudentus(vector<studentas>& studentai, vector<studentas>& vargsai, vector<studentas>& kietiakai);
void skirstitiStudentus(list<studentas>& studentai, list<studentas>& vargsai, list<studentas>& kietiakai);
void skirstitiStudentus(deque<studentas>& studentai, deque<studentas>& vargsai, deque<studentas>& kietiakai);