#include "myLib.h"
#include "funkcijos.h"

const string vardai[20]{ "Markas" , "Benas" , "Herkus", "Jonas" , "Dominykas" , "Jokubas" , "Lukas" , "Matas" , "Adomas" , "Nojus" , "Sofija" , "Emilija" , "Amelija" , "Liepa" , "Lukne" , "Patricija" , "Kamile" , "Leja" , "Izabele" , "Elija" };
const int vardaiN = 20;
const string pavardes[20]{ "Kazlausk" , "Petrausk" , "Jankausk"  , "Zukausk"  , "Paulausk"  , "Vasiliausk"  , "Baranausk"  , "Urbon"  , "Savick"  , "Kavaliausk"  , "Bagdon"  , "Ivanausk"  , "Naujok"  , "Malinausk"  , "Kaminsk"  , "Mikalausk"  , "Ivanov"  , "Vitkausk"  , "Sakalausk"  , "Zilinsk" };
const int pavardesN = 20;

void atsitiktinisStudentas(studentas& stud) {

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
    try {
        if (mas.size() < 1) { throw "Nera pridetu studentu."; }
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
    catch (const char* e) {
        cout << e << endl;
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
    int ndNr = -3, failasParuostas = 0;
    ifstream ivestis;
    studentas stud;
    vector<int> pazymiai;
    while (failasParuostas == 0) {
        try {
            ivestis.open(failas);
            if (!ivestis.good()) {
                throw "Nera duomenu failo.";
            }
            failasParuostas = 1;
        }
        catch (const char* e) {
            cout << e << endl;
            if (klausimas0_1("Ar norite bandyti skaityti faila is naujo? 0 - Ne, 1 - taip") == 0) {
                break;
            }
        }
    }
    if (failasParuostas == 1) {
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

    ivestis.close();
}