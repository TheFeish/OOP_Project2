#pragma once
#include "myLib.h"
#include "zmogus.h"

class studentas: public zmogus
{
private:
	double mediana, vidurkis;
	int egzaminas;
	vector<int> pazymiai;
public:
	studentas() : zmogus{}, mediana(0), vidurkis(0), egzaminas(0), pazymiai() {}
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

	void spausdinti(ostringstream& out);

	vector<int> grazintiPazymius();
	double grazintiMediana();
	double grazintiVidurki();
	int grazintiEgzamina();

	void nustatytiPazymius(vector<int> paz);
	void nustatytiMediana(double med);
	void nustatytiVidurki(double vid);
	void nustatytiEgzamina(int egz);
};