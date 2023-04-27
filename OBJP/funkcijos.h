#pragma once
#include "studentas.h"
void atsitiktinisStudentas(studentas& stud, int nr, bool generuotiVisusPaz);
void pridetiPazymius(studentas& stud, string vardas, string pavarde);
//-------------------------------------------------------------------------------------------------------------
void pridetiStudenta(vector<studentas>& mas);
void pridetiStudenta(list<studentas>& mas);
void pridetiStudenta(deque<studentas>& mas);
//-------------------------------------------------------------------------------------------------------------
double vidurkis(vector<int> mas);
double mediana(vector<int> mas);
//-------------------------------------------------------------------------------------------------------------
void spausdinti(vector<studentas> mas1, vector<studentas> mas2, int spBudas, double& visasLaikas);
void spausdinti(list<studentas> mas1, list<studentas> mas2, int spBudas, double& visasLaikas);
void spausdinti(deque<studentas> mas1, deque<studentas> mas2, int spBudas, double& visasLaikas);
//-------------------------------------------------------------------------------------------------------------
int klausimas0_1(string zinute);
//-------------------------------------------------------------------------------------------------------------
void skaitytiIsFailo(vector<studentas>& mas, double& visasLaikas);
void skaitytiIsFailo(list<studentas>& mas, double& visasLaikas);
void skaitytiIsFailo(deque<studentas>& mas, double& visasLaikas);
//-------------------------------------------------------------------------------------------------------------
void kurtiFaila(int studNr, int pazNr, string pavadinimas);
//-------------------------------------------------------------------------------------------------------------
void skirstitiStudentus(vector<studentas>& studentai, vector<studentas>& vargsai, vector<studentas>& kietiakai, int rusBudas, double& visasLaikas);
void skirstitiStudentus(list<studentas>& studentai, list<studentas>& vargsai, list<studentas>& kietiakai, int rusBudas, double& visasLaikas);
void skirstitiStudentus(deque<studentas>& studentai, deque<studentas>& vargsai, deque<studentas>& kietiakai, int rusBudas, double& visasLaikas);

void skirstitiStudentus2(vector<studentas>& kietiakai, vector<studentas>& vargsai, int rusBudas, double& visasLaikas);
void skirstitiStudentus2(list<studentas>& kietiakai, list<studentas>& vargsai, int rusBudas, double& visasLaikas);
void skirstitiStudentus2(deque<studentas>& kietiakai, deque<studentas>& vargsai, int rusBudas, double& visasLaikas);