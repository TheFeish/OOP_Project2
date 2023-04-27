#include "studentas.h"
#include "myLib.h"

studentas::studentas(string var, string pav, double med, double vid, int egz) : vardas(var), pavarde(pav), mediana(med), vidurkis(vid), egzaminas(egz), pazymiai() {}
studentas::studentas(string var, string pav, double med, double vid, int egz, vector<int> paz) : vardas(var), pavarde(pav), mediana(med), vidurkis(vid), egzaminas(egz), pazymiai(paz) {}

bool studentas::operator<(studentas& val) {
	if (vardas != val.vardas) {
		return vardas < val.vardas;
	}
	else {
		return pavarde < val.pavarde;
	}
}

void studentas::spausdinti(ostringstream& out, bool arVidurkis) {
	if (arVidurkis) {
		out << endl << setw(28) << left << vardas << setw(31) << left << pavarde << setprecision(2) << fixed << vidurkis;
	}
	else {
		out << endl << setw(28) << left << vardas << setw(31) << left << pavarde << setprecision(2) << fixed << mediana;
	}
}

void studentas::spausdintiDuomenuFailui(ostringstream& out) {
	out.str(string());
	out << endl << left << setw(28) << vardas << left << setw(31) << pavarde;
	for (auto paz : pazymiai) {
		out << left << setw(10) << paz;
	}
	out << setw(10) << left << egzaminas;
}

vector<int> studentas::grazintiPazymius() { return pazymiai; }

double studentas::grazintiMediana() { return mediana; }

double studentas::grazintiVidurki() { return vidurkis; }