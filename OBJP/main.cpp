#include "myLib.h"

const string vardai[20]{ "Markas" , "Benas" , "Herkus", "Jonas" , "Dominykas" , "Jokubas" , "Lukas" , "Matas" , "Adomas" , "Nojus" , "Sofija" , "Emilija" , "Amelija" , "Liepa" , "Lukne" , "Patricija" , "Kamile" , "Leja" , "Izabele" , "Elija" };
const int vardaiN = 20;
const string pavardes[20]{ "Kazlausk" , "Petrausk" , "Jankausk"  , "Zukausk"  , "Paulausk"  , "Vasiliausk"  , "Baranausk"  , "Urbon"  , "Savick"  , "Kavaliausk"  , "Bagdon"  , "Ivanausk"  , "Naujok"  , "Malinausk"  , "Kaminsk"  , "Mikalausk"  , "Ivanov"  , "Vitkausk"  , "Sakalausk"  , "Zilinsk" };
const int pavardesN = 20;

struct studentas {
    string vardas, pavarde;
    int egzaminas;
    double mediana, vidurkis;

    bool operator<(studentas& val){
        return pavarde < val.pavarde;
    }
};

studentas atsitiktinisStudentas(studentas& stud);
void pridetiPazymius(studentas& stud);
void pridetiStudenta(vector<studentas>& mas);
double vidurkis(vector<int> mas);
double mediana(vector<int> mas);
void spausdinti(vector<studentas> mas);
int klausimas0_1(string zinute);
void skaitytiIsFailo(vector<studentas>& mas);

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

studentas atsitiktinisStudentas(studentas& stud) {

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> distVardai(0, vardaiN - 1), distPavardes(0, pavardesN - 1), distPazymiai(0, 10);

    vector<int> mas;

    stud.vardas = vardai[distVardai(mt)];
    stud.pavarde = pavardes[distPavardes(mt)];
    if (stud.vardas.back() == 's') {
        stud.pavarde += "as";
    }
    else {
        stud.pavarde += "aite";
    }

    for (int i = 0; i < 10; i++) {
        mas.push_back(distPazymiai(mt));
    }

    stud.vidurkis = vidurkis(mas);
    stud.mediana = mediana(mas);
    stud.egzaminas = distPazymiai(mt);

    return stud;
}

void pridetiPazymius(studentas& stud) {
    int pazymiuNr = 1;
    vector<int> mas;
    int temp;
    cout << "Iveskite studento namu darbu pazymius (Noredami uzbaigti iveskite, bet koki simboli): ";
    while (mas.size() < 1) {
        while (cin >> temp) {
            if (temp <= 10 && temp >= 0) {
                mas.push_back(temp);
            }
            else {
                cout << "Ivedete neteisinga reiksme" << endl;
            }
        }
        if (mas.size() < 1) {
            cout << "Neivedete pazymiu" << endl;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    stud.vidurkis = vidurkis(mas);
    stud.mediana = mediana(mas);
    temp = -1;
    cout << "Iveskite studento egzamino pazymi: ";
    while (temp < 0 || temp > 10) {
        cin >> temp;
        if (temp <= 10 && temp >= 0 && !cin.fail()) {
            stud.egzaminas = temp;
        }
        else {
            cout << "Ivedete neteisinga reiksme" << endl;
            temp = -1;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void pridetiStudenta(vector<studentas>& mas) {
    studentas stud;
    if (klausimas0_1("\nAr ivesti atsitiktinai sugeneruota studenta? 0 - Ne, 1 - Taip") == 0) {
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> stud.vardas >> stud.pavarde;
        pridetiPazymius(stud);
    }
    else {
        atsitiktinisStudentas(stud);
    }
    mas.push_back(stud);
}

double vidurkis(vector<int> mas) {
    double sum = 0;
    for (int i = 0; i < mas.size(); i++) {
        sum += mas[i];
    }
    return sum / mas.size();
}

double mediana(vector<int> mas) {
    int i = mas.size();
    sort(mas.begin(), mas.end());
    if (i % 2 == 1) {
        return mas[i / 2];
    }
    else {
        return (mas[i / 2] + mas[i / 2 - 1]) / 2.0;
    }
}

void spausdinti(vector<studentas> mas) {
    double galutinis;
    sort(mas.begin(), mas.end());
    int temp = klausimas0_1("\nKaip skaiciuoti galutini studento pazymi? 0 - Naudojant vidurki, 1 - naudojant mediana");
    if (temp == 0) {
        cout << endl << "Pavarde        Vardas         Galutinis (Vid)" << endl;
    }
    else {
        cout << endl << "Pavarde        Vardas         Galutinis (Med)" << endl;
    }
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < mas.size(); i++) {
        if (temp == 0) {
            galutinis = mas[i].vidurkis * 0.4;
        }
        else {
            galutinis = mas[i].mediana * 0.4;
        }
        galutinis += mas[i].egzaminas * 0.6;
        cout << setw(15) << left << mas[i].pavarde << setw(15) << left << mas[i].vardas << setprecision(2) << fixed << galutinis << endl;
    }
}

int klausimas0_1(string zinute) {
    int temp = -1;
    cout << zinute << endl;
    while (temp != 0 && temp != 1) {
        cin >> temp;
        if (temp != 0 && temp != 1 || cin.fail()) {
            cout << "Ivedete neteisinga reiksme" << endl;
            temp = -1;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return temp;
}

void skaitytiIsFailo(vector<studentas>& mas) {
    string failas = "kursiokai.txt", temp;
    ifstream ivestis;
    int ndNr = -3;
    studentas stud;
    vector<int> pazymiai;

    ivestis.open(failas);
    getline(ivestis, temp);
    istringstream ss(temp);
    while (ss >> temp) {
        ndNr++;
    }
    ss.clear();

    while (getline(ivestis, temp)) {
        pazymiai.clear();
        ss.clear();
        ss.str(temp);

        ss >> stud.vardas >> stud.pavarde;
        for (int i = 0; i < ndNr; i++) {
            ss >> temp;
            pazymiai.push_back(stoi(temp));
        }
        ss >> temp;
        stud.egzaminas = stoi(temp);

        stud.vidurkis = vidurkis(pazymiai);
        stud.mediana = mediana(pazymiai);

        mas.push_back(stud);
    }
}