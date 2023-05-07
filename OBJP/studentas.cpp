#include "studentas.h"
#include "myLib.h"

studentas::studentas(string var, string pav, double med, double vid, int egz) : vardas(var), pavarde(pav), mediana(med), vidurkis(vid), egzaminas(egz), pazymiai() {}
studentas::studentas(string var, string pav, double med, double vid, int egz, vector<int> paz) : vardas(var), pavarde(pav), mediana(med), vidurkis(vid), egzaminas(egz), pazymiai(paz) {}
studentas::studentas(const studentas& val) : vardas(val.vardas), pavarde(val.pavarde), mediana(val.mediana), vidurkis(val.vidurkis), egzaminas(val.egzaminas), pazymiai(val.pazymiai) {}
studentas::studentas(studentas&& val) : vardas(val.vardas), pavarde(val.pavarde), mediana(val.mediana), vidurkis(val.vidurkis), egzaminas(val.egzaminas), pazymiai(move(val.pazymiai)) {
	val.vardas = "";
	val.pavarde = "";
	val.mediana = 0;
	val.vidurkis = 0;
	val.egzaminas = 0;
}

studentas& studentas::operator=(const studentas& val) {
	if (&val == this) { return *this; }
	vardas = val.vardas;
	pavarde = val.pavarde;
	mediana = val.mediana;
	vidurkis = val.vidurkis;
	egzaminas = val.egzaminas;
	pazymiai = vector<int>(val.pazymiai);
}

studentas& studentas::operator=(studentas&& val) {
	if (&val == this) { return *this; }
	vardas = val.vardas;
	pavarde = val.pavarde;
	mediana = val.mediana;
	vidurkis = val.vidurkis;
	egzaminas = val.egzaminas;
	pazymiai = move(val.pazymiai);

	val.vardas = "";
	val.pavarde = "";
	val.mediana = 0;
	val.vidurkis = 0;
	val.egzaminas = 0;
}

bool studentas::operator<(studentas& val) {
	if (vardas != val.vardas) {
		return vardas < val.vardas;
	}
	else {
		return pavarde < val.pavarde;
	}
}

ostream& operator << (ostream& out, const studentas& val)
{
	out << setw(28) << left << val.vardas << setw(31) << left << val.pavarde << "Vidurkis: " << setprecision(2) << fixed << val.vidurkis << " Mediana: " << setprecision(2) << fixed << val.mediana << " Pazymiai:";
	for (auto paz : val.pazymiai) {
		out << " " << paz;
	}
	return out;
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

void studentas::keistiPazymius(vector<int> paz) { pazymiai = paz; }