#pragma once
#include "myLib.h"
class studentas
{
private:
	string vardas, pavarde;
	double mediana, vidurkis;
	int egzaminas;
	vector<int> pazymiai;
public:
	studentas() : vardas(""), pavarde(""), mediana(0), vidurkis(0), egzaminas(0), pazymiai() {}
	studentas(string var, string pav, double med, double vid, int egz);
	studentas(string var, string pav, double med, double vid, int egz, vector<int> paz);
	~studentas() {}

	bool operator<(studentas& val);

	void spausdinti(ostringstream& out, bool arVidurkis);

	void spausdintiDuomenuFailui(ostringstream& out);

	vector<int> grazintiPazymius();

	double grazintiMediana();

	double grazintiVidurki();
};