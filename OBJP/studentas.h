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
	studentas(const studentas& val);
	studentas(studentas&& val);
	~studentas() {}

	studentas& operator=(const studentas& val);

	studentas& operator=(studentas&& val);

	bool operator<(studentas& val);

	friend ostream& operator<< (ostream& out, const studentas& val);

	void spausdinti(ostringstream& out, bool arVidurkis);

	void spausdintiDuomenuFailui(ostringstream& out);

	vector<int> grazintiPazymius();

	double grazintiMediana();

	double grazintiVidurki();

	void keistiPazymius(vector<int> paz);
};