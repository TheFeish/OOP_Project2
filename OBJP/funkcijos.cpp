#include "myLib.h"
#include "funkcijos.h"

const string vardai[20]{ "Markas" , "Benas" , "Herkus", "Jonas" , "Dominykas" , "Jokubas" , "Lukas" , "Matas" , "Adomas" , "Nojus" , "Sofija" , "Emilija" , "Amelija" , "Liepa" , "Lukne" , "Patricija" , "Kamile" , "Leja" , "Izabele" , "Elija" };
const int vardaiN = 20;
const string pavardes[20]{ "Kazlausk" , "Petrausk" , "Jankausk"  , "Zukausk"  , "Paulausk"  , "Vasiliausk"  , "Baranausk"  , "Urbon"  , "Savick"  , "Kavaliausk"  , "Bagdon"  , "Ivanausk"  , "Naujok"  , "Malinausk"  , "Kaminsk"  , "Mikalausk"  , "Ivanov"  , "Vitkausk"  , "Sakalausk"  , "Zilinsk" };
const int pavardesN = 20;

void atsitiktinisStudentas(studentas& stud, int nr, bool generuotiVisusPaz) {

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

    for (int i = 0; i < nr; i++) {
        mas.push_back(distPazymiai(mt));
    }

    stud.egzaminas = distPazymiai(mt);

    stud.vidurkis = vidurkis(mas) * 0.4 + stud.egzaminas * 0.6;
    stud.mediana = mediana(mas) * 0.4 + stud.egzaminas * 0.6;

    if (generuotiVisusPaz == true) {
        stud.pazymiai = mas;
    }
}

//-------------------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------------------

void pridetiStudenta(vector<studentas>& mas) {
    studentas stud;
    if (klausimas0_1("\nAr ivesti atsitiktinai sugeneruota studenta? 0 - Ne, 1 - Taip") == 0) {
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> stud.vardas >> stud.pavarde;
        pridetiPazymius(stud);
    }
    else {
        atsitiktinisStudentas(stud, 10, false);
    }
    mas.push_back(stud);
}

void pridetiStudenta(list<studentas>& mas) {
    studentas stud;
    if (klausimas0_1("\nAr ivesti atsitiktinai sugeneruota studenta? 0 - Ne, 1 - Taip") == 0) {
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> stud.vardas >> stud.pavarde;
        pridetiPazymius(stud);
    }
    else {
        atsitiktinisStudentas(stud, 10, false);
    }
    mas.push_back(stud);
}

void pridetiStudenta(deque<studentas>& mas) {
    studentas stud;
    if (klausimas0_1("\nAr ivesti atsitiktinai sugeneruota studenta? 0 - Ne, 1 - Taip") == 0) {
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> stud.vardas >> stud.pavarde;
        pridetiPazymius(stud);
    }
    else {
        atsitiktinisStudentas(stud, 10, false);
    }
    mas.push_back(stud);
}

//-------------------------------------------------------------------------------------------------------------

double vidurkis(vector<int> mas) {
    double sum = 0;
    for (int i = 0; i < mas.size(); i++) {
        sum += mas[i];
    }
    return sum / mas.size();
}

//-------------------------------------------------------------------------------------------------------------

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

//-------------------------------------------------------------------------------------------------------------

void spausdinti(vector<studentas> mas1, vector<studentas> mas2, int spBudas, double& visasLaikas) {
    try {
        if (mas1.size() + mas2.size() < 1) { throw "Nera pridetu studentu."; }
        double funkLaikas = 0;

        auto pradzia = high_resolution_clock::now();

        ofstream failas("kietiakai.txt");
        ostringstream ss;

        if (spBudas == 0) {
            failas << "Vardas                      Pavarde                        Galutinis (Vid)";
        }
        else {
            failas << "Vardas                      Pavarde                        Galutinis (Med)";
        }
        failas << endl << "--------------------------------------------------------------------------";

        for (auto stud : mas1) {
            ss.str(string());
            if (spBudas == 0) {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.vidurkis;
            }
            else {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.mediana;
            }
            failas << ss.str();
        }
        failas.close();

        auto pabaiga = high_resolution_clock::now();
        auto laikas = duration<double>(pabaiga - pradzia);
        funkLaikas += laikas.count();
        cout << mas1.size() << " kietiaku irasymo i faila laikas: " << fixed << laikas.count() << " s" << endl;

        pradzia = high_resolution_clock::now();

        failas.open("vargsai.txt");
        ss.str(string());

        if (spBudas == 0) {
            failas << "Vardas                      Pavarde                        Galutinis (Vid)";
        }
        else {
            failas << "Vardas                      Pavarde                        Galutinis (Med)";
        }
        failas << endl << "--------------------------------------------------------------------------";

        for (auto stud : mas2) {
            ss.str(string());
            if (spBudas == 0) {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.vidurkis;
            }
            else {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.mediana;
            }
            failas << ss.str();
        }
        failas.close();

        pabaiga = high_resolution_clock::now();
        laikas = duration<double>(pabaiga - pradzia);
        funkLaikas += laikas.count();
        visasLaikas += funkLaikas;
        cout << mas2.size() << " vargsu irasymo i faila laikas: " << fixed << laikas.count() << " s" << endl;
    }
    catch (const char* e) {
        cout << e << endl;
    }
}

void spausdinti(list<studentas> mas1, list<studentas> mas2, int spBudas, double& visasLaikas) {
    try {
        if (mas1.size() + mas2.size() < 1) { throw "Nera pridetu studentu."; }
        double funkLaikas = 0;

        auto pradzia = high_resolution_clock::now();

        ofstream failas("kietiakai.txt");
        ostringstream ss;

        if (spBudas == 0) {
            failas << "Vardas                      Pavarde                        Galutinis (Vid)";
        }
        else {
            failas << "Vardas                      Pavarde                        Galutinis (Med)";
        }
        failas << endl << "--------------------------------------------------------------------------";

        for (auto stud : mas1) {
            ss.str(string());
            if (spBudas == 0) {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.vidurkis;
            }
            else {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.mediana;
            }
            failas << ss.str();
        }
        failas.close();

        auto pabaiga = high_resolution_clock::now();
        auto laikas = duration<double>(pabaiga - pradzia);
        funkLaikas += laikas.count();
        cout << mas1.size() << " kietiaku irasymo i faila laikas: " << fixed << laikas.count() << " s" << endl;

        pradzia = high_resolution_clock::now();

        failas.open("vargsai.txt");
        ss.str(string());

        if (spBudas == 0) {
            failas << "Vardas                      Pavarde                        Galutinis (Vid)";
        }
        else {
            failas << "Vardas                      Pavarde                        Galutinis (Med)";
        }
        failas << endl << "--------------------------------------------------------------------------";

        for (auto stud : mas2) {
            ss.str(string());
            if (spBudas == 0) {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.vidurkis;
            }
            else {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.mediana;
            }
            failas << ss.str();
        }
        failas.close();

        pabaiga = high_resolution_clock::now();
        laikas = duration<double>(pabaiga - pradzia);
        funkLaikas += laikas.count();
        visasLaikas += funkLaikas;
        cout << mas2.size() << " vargsu irasymo i faila laikas: " << fixed << laikas.count() << " s" << endl;
    }
    catch (const char* e) {
        cout << e << endl;
    }
}

void spausdinti(deque<studentas> mas1, deque<studentas> mas2, int spBudas, double& visasLaikas) {
    try {
        if (mas1.size() + mas2.size() < 1) { throw "Nera pridetu studentu."; }
        double funkLaikas = 0;

        auto pradzia = high_resolution_clock::now();

        ofstream failas("kietiakai.txt");
        ostringstream ss;

        if (spBudas == 0) {
            failas << "Vardas                      Pavarde                        Galutinis (Vid)";
        }
        else {
            failas << "Vardas                      Pavarde                        Galutinis (Med)";
        }
        failas << endl << "--------------------------------------------------------------------------";

        for (auto stud : mas1) {
            ss.str(string());
            if (spBudas == 0) {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.vidurkis;
            }
            else {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.mediana;
            }
            failas << ss.str();
        }
        failas.close();

        auto pabaiga = high_resolution_clock::now();
        auto laikas = duration<double>(pabaiga - pradzia);
        funkLaikas += laikas.count();
        cout << mas1.size() << " kietiaku irasymo i faila laikas: " << fixed << laikas.count() << " s" << endl;

        pradzia = high_resolution_clock::now();

        failas.open("vargsai.txt");
        ss.str(string());

        if (spBudas == 0) {
            failas << "Vardas                      Pavarde                        Galutinis (Vid)";
        }
        else {
            failas << "Vardas                      Pavarde                        Galutinis (Med)";
        }
        failas << endl << "--------------------------------------------------------------------------";

        for (auto stud : mas2) {
            ss.str(string());
            if (spBudas == 0) {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.vidurkis;
            }
            else {
                ss << endl << setw(28) << left << stud.vardas << setw(31) << left << stud.pavarde << setprecision(2) << fixed << stud.mediana;
            }
            failas << ss.str();
        }
        failas.close();

        pabaiga = high_resolution_clock::now();
        laikas = duration<double>(pabaiga - pradzia);
        funkLaikas += laikas.count();
        visasLaikas += funkLaikas;
        cout << mas2.size() << " vargsu irasymo i faila laikas: " << fixed << laikas.count() << " s" << endl;
    }
    catch (const char* e) {
        cout << e << endl;
    }
}

//-------------------------------------------------------------------------------------------------------------

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


//-------------------------------------------------------------------------------------------------------------

void skaitytiIsFailo(vector<studentas>& mas, double& visasLaikas) {
    string failas, temp;
    int ndNr = -3, failasParuostas = 0;
    ifstream ivestis;
    studentas stud;
    vector<int> pazymiai;
    while (failasParuostas == 0) {
        try {
            int failaiNr = 0;
            for (auto& dir : directory_iterator("./")) {
                temp = dir.path().string();
                if (temp.ends_with(".txt")) {
                    cout << temp << endl;;
                    failaiNr++;
                }
            }
            if (failaiNr < 1) {
                throw "Direktorijoje nera tekstiniu failu.";
            }
            cout << endl << "Pasirinkite duomenu faila: ";
            cin >> failas;
            ivestis.open(failas);
            if (ivestis.fail()) {
                throw "Pasirinktas failas neegzistuoja.";
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
    auto pradzia = high_resolution_clock::now();
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

            stud.vidurkis = vidurkis(pazymiai) * 0.4 + stud.egzaminas * 0.6;
            stud.mediana = mediana(pazymiai) * 0.4 + stud.egzaminas * 0.6;

            mas.push_back(stud);
        }
    }
    ivestis.close();
    auto pabaiga = high_resolution_clock::now();
    auto laikas = duration<double>(pabaiga - pradzia);
    visasLaikas += laikas.count();
    cout << mas.size() << " irasu failo skaitymo laikas: " << fixed << fixed << laikas.count() << " s" << endl;
}

void skaitytiIsFailo(list<studentas>& mas, double& visasLaikas) {
    string failas, temp;
    int ndNr = -3, failasParuostas = 0;
    ifstream ivestis;
    studentas stud;
    vector<int> pazymiai;
    while (failasParuostas == 0) {
        try {
            int failaiNr = 0;
            for (auto& dir : directory_iterator("./")) {
                temp = dir.path().string();
                if (temp.ends_with(".txt")) {
                    cout << temp << endl;;
                    failaiNr++;
                }
            }
            if (failaiNr < 1) {
                throw "Direktorijoje nera tekstiniu failu.";
            }
            cout << endl << "Pasirinkite duomenu faila: ";
            cin >> failas;
            ivestis.open(failas);
            if (ivestis.fail()) {
                throw "Pasirinktas failas neegzistuoja.";
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
    auto pradzia = high_resolution_clock::now();
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

            stud.vidurkis = vidurkis(pazymiai) * 0.4 + stud.egzaminas * 0.6;
            stud.mediana = mediana(pazymiai) * 0.4 + stud.egzaminas * 0.6;

            mas.push_back(stud);
        }
    }
    ivestis.close();
    auto pabaiga = high_resolution_clock::now();
    auto laikas = duration<double>(pabaiga - pradzia);
    visasLaikas += laikas.count();
    cout << mas.size() << " irasu failo skaitymo laikas: " << fixed << fixed << laikas.count() << " s" << endl;
}

void skaitytiIsFailo(deque<studentas>& mas, double& visasLaikas) {
    string failas, temp;
    int ndNr = -3, failasParuostas = 0;
    ifstream ivestis;
    studentas stud;
    vector<int> pazymiai;
    while (failasParuostas == 0) {
        try {
            int failaiNr = 0;
            for (auto& dir : directory_iterator("./")) {
                temp = dir.path().string();
                if (temp.ends_with(".txt")) {
                    cout << temp << endl;;
                    failaiNr++;
                }
            }
            if (failaiNr < 1) {
                throw "Direktorijoje nera tekstiniu failu.";
            }
            cout << endl << "Pasirinkite duomenu faila: ";
            cin >> failas;
            ivestis.open(failas);
            if (ivestis.fail()) {
                throw "Pasirinktas failas neegzistuoja.";
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
    auto pradzia = high_resolution_clock::now();
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

            stud.vidurkis = vidurkis(pazymiai) * 0.4 + stud.egzaminas * 0.6;
            stud.mediana = mediana(pazymiai) * 0.4 + stud.egzaminas * 0.6;

            mas.push_back(stud);
        }
    }
    ivestis.close();
    auto pabaiga = high_resolution_clock::now();
    auto laikas = duration<double>(pabaiga - pradzia);
    visasLaikas += laikas.count();
    cout << mas.size() << " irasu failo skaitymo laikas: " << fixed << fixed << laikas.count() << " s" << endl;
}

//-------------------------------------------------------------------------------------------------------------

void kurtiFaila(int studNr, int pazNr, string pavadinimas) {
    auto pradzia = high_resolution_clock::now();
    ofstream failas(pavadinimas);
    string temp;
    studentas stud;
    ostringstream ss;
    ss << "Vardas                      Pavarde                        ";
    for (int i = 0; i < pazNr; i++) {
        ss << "ND" << left << setw(8) << i + 1;
    }
    ss << "Egz.";
    failas << ss.str();
    for (int i = 0; i < studNr; i++) {
        atsitiktinisStudentas(stud, pazNr, true);
        ss.str(string());
        ss << endl << left << setw(28) << stud.vardas << left << setw(31) << stud.pavarde;
        for (int x = 0; x < pazNr; x++) {
            ss << left << setw(10) << stud.pazymiai[x];
        }
        ss << setw(10) << left << stud.egzaminas;
        failas << ss.str();
    }
    failas.close();
    auto pabaiga = high_resolution_clock::now();
    auto laikas = duration<double>(pabaiga - pradzia);
    cout << studNr << " irasu failo kurimo laikas: " << fixed << laikas.count() << " s" << endl;
}

//-------------------------------------------------------------------------------------------------------------

void skirstitiStudentus(vector<studentas>& studentai, vector<studentas>& vargsai, vector<studentas>& kietiakai, int rusBudas, double& visasLaikas) {
    double funkLaikas = 0;
    auto pradzia = high_resolution_clock::now();
    if (rusBudas == 0) {
        auto iteratorius = partition(studentai.begin(), studentai.end(), [](studentas stud) {return stud.vidurkis < 5; });
        vargsai = vector<studentas>(studentai.begin(), iteratorius);
        kietiakai = vector<studentas>(iteratorius, studentai.end());
        studentai.clear();
    }
    else {
        auto iteratorius = partition(studentai.begin(), studentai.end(), [](studentas stud) {return stud.mediana < 5; });
        vargsai = vector<studentas>(studentai.begin(), iteratorius);
        kietiakai = vector<studentas>(iteratorius, studentai.end());
        studentai.clear();
    }
    
    auto pabaiga = high_resolution_clock::now();
    auto laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu skirtimo i dvi grupes laikas: " << fixed << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();

    pradzia = high_resolution_clock::now();
    sort(kietiakai.begin(), kietiakai.end());
    sort(vargsai.begin(), vargsai.end());
    pabaiga = high_resolution_clock::now();
    laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu rusiavimo laikas: " << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();
    visasLaikas += funkLaikas;
}


void skirstitiStudentus(list<studentas>& studentai, list<studentas>& vargsai, list<studentas>& kietiakai, int rusBudas, double& visasLaikas) {
    double funkLaikas = 0;
    auto pradzia = high_resolution_clock::now();
    if (rusBudas == 0) {
        auto iteratorius = partition(studentai.begin(), studentai.end(), [](studentas stud) {return stud.vidurkis < 5; });
        vargsai = list<studentas>(studentai.begin(), iteratorius);
        kietiakai = list<studentas>(iteratorius, studentai.end());
        studentai.clear();
    }
    else {
        auto iteratorius = partition(studentai.begin(), studentai.end(), [](studentas stud) {return stud.mediana < 5; });
        vargsai = list<studentas>(studentai.begin(), iteratorius);
        kietiakai = list<studentas>(iteratorius, studentai.end());
        studentai.clear();
    }
    
    auto pabaiga = high_resolution_clock::now();
    auto laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu skirtimo i dvi grupes laikas: " << fixed << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();

    pradzia = high_resolution_clock::now();
    kietiakai.sort();
    vargsai.sort();
    pabaiga = high_resolution_clock::now();
    laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu rusiavimo laikas: " << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();
    visasLaikas += funkLaikas;
}


void skirstitiStudentus(deque<studentas>& studentai, deque<studentas>& vargsai, deque<studentas>& kietiakai, int rusBudas, double& visasLaikas) {
    double funkLaikas = 0;
    auto pradzia = high_resolution_clock::now();
    if (rusBudas == 0) {
        auto iteratorius = partition(studentai.begin(), studentai.end(), [](studentas stud) {return stud.vidurkis < 5; });
        vargsai = deque<studentas>(studentai.begin(), iteratorius);
        kietiakai = deque<studentas>(iteratorius, studentai.end());
        studentai.clear();
    }
    else {
        auto iteratorius = partition(studentai.begin(), studentai.end(), [](studentas stud) {return stud.mediana < 5; });
        vargsai = deque<studentas>(studentai.begin(), iteratorius);
        kietiakai = deque<studentas>(iteratorius, studentai.end());
        studentai.clear();
    }
    
    auto pabaiga = high_resolution_clock::now();
    auto laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu skirtimo i dvi grupes laikas: " << fixed << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();

    pradzia = high_resolution_clock::now();
    sort(kietiakai.begin(), kietiakai.end());
    sort(vargsai.begin(), vargsai.end());
    pabaiga = high_resolution_clock::now();
    laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu rusiavimo laikas: " << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();
    visasLaikas += funkLaikas;
}

//-------------------------------------------------------------------------------------------------------------

void skirstitiStudentus2(vector<studentas>& kietiakai, vector<studentas>& vargsai, int rusBudas, double& visasLaikas) {
    double funkLaikas = 0;
    auto pradzia = high_resolution_clock::now();
    if (rusBudas == 0) {
        auto iteratorius = partition(kietiakai.begin(), kietiakai.end(), [](studentas stud) {return stud.vidurkis < 5; });
        vargsai = vector<studentas>(kietiakai.begin(), iteratorius);
        kietiakai.erase(kietiakai.begin(), iteratorius);
    }
    else {
        auto iteratorius = partition(kietiakai.begin(), kietiakai.end(), [](studentas stud) {return stud.mediana < 5; });
        vargsai = vector<studentas>(kietiakai.begin(), iteratorius);
        kietiakai.erase(kietiakai.begin(), iteratorius);
    }

    auto pabaiga = high_resolution_clock::now();
    auto laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu skirtimo i dvi grupes laikas: " << fixed << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();

    pradzia = high_resolution_clock::now();
    sort(kietiakai.begin(), kietiakai.end());
    sort(vargsai.begin(), vargsai.end());
    pabaiga = high_resolution_clock::now();
    laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu rusiavimo laikas: " << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();

    visasLaikas += funkLaikas;
}


void skirstitiStudentus2(list<studentas>& kietiakai, list<studentas>& vargsai, int rusBudas, double& visasLaikas) {
    double funkLaikas = 0;
    auto pradzia = high_resolution_clock::now();
    if (rusBudas == 0) {
        auto iteratorius = partition(kietiakai.begin(), kietiakai.end(), [](studentas stud) {return stud.vidurkis < 5; });
        vargsai = list<studentas>(kietiakai.begin(), iteratorius);
        kietiakai.erase(kietiakai.begin(), iteratorius);
    }
    else {
        auto iteratorius = partition(kietiakai.begin(), kietiakai.end(), [](studentas stud) {return stud.mediana < 5; });
        vargsai = list<studentas>(kietiakai.begin(), iteratorius);
        kietiakai.erase(kietiakai.begin(), iteratorius);
    }

    auto pabaiga = high_resolution_clock::now();
    auto laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu skirtimo i dvi grupes laikas: " << fixed << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();

    pradzia = high_resolution_clock::now();
    kietiakai.sort();
    vargsai.sort();
    pabaiga = high_resolution_clock::now();
    laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu rusiavimo laikas: " << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();

    visasLaikas += funkLaikas;
}


void skirstitiStudentus2(deque<studentas>& kietiakai, deque<studentas>& vargsai, int rusBudas, double& visasLaikas) {
    double funkLaikas = 0;
    auto pradzia = high_resolution_clock::now();
    if (rusBudas == 0) {
        auto iteratorius = partition(kietiakai.begin(), kietiakai.end(), [](studentas stud) {return stud.vidurkis < 5; });
        vargsai = deque<studentas>(kietiakai.begin(), iteratorius);
        kietiakai.erase(kietiakai.begin(), iteratorius);
    }
    else {
        auto iteratorius = partition(kietiakai.begin(), kietiakai.end(), [](studentas stud) {return stud.mediana < 5; });
        vargsai = deque<studentas>(kietiakai.begin(), iteratorius);
        kietiakai.erase(kietiakai.begin(), iteratorius);
    }

    auto pabaiga = high_resolution_clock::now();
    auto laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu skirtimo i dvi grupes laikas: " << fixed << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();

    pradzia = high_resolution_clock::now();
    sort(kietiakai.begin(), kietiakai.end());
    sort(vargsai.begin(), vargsai.end());
    pabaiga = high_resolution_clock::now();
    laikas = duration<double>(pabaiga - pradzia);
    cout << vargsai.size() + kietiakai.size() << " irasu rusiavimo laikas: " << laikas.count() << " s" << endl;
    funkLaikas += laikas.count();

    visasLaikas += funkLaikas;
}