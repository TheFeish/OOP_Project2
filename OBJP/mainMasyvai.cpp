#include "myLib.h"

const string vardai[20]{ "Markas" , "Benas" , "Herkus", "Jonas" , "Dominykas" , "Jokubas" , "Lukas" , "Matas" , "Adomas" , "Nojus" , "Sofija" , "Emilija" , "Amelija" , "Liepa" , "Lukne" , "Patricija" , "Kamile" , "Leja" , "Izabele" , "Elija" };
const int vardaiN = 20;
const string pavardes[20]{ "Kazlausk" , "Petrausk" , "Jankausk"  , "Zukausk"  , "Paulausk"  , "Vasiliausk"  , "Baranausk"  , "Urbon"  , "Savick"  , "Kavaliausk"  , "Bagdon"  , "Ivanausk"  , "Naujok"  , "Malinausk"  , "Kaminsk"  , "Mikalausk"  , "Ivanov"  , "Vitkausk"  , "Sakalausk"  , "Zilinsk" };
const int pavardesN = 20;

struct studentas {
    string vardas, pavarde;
    int egzaminas;
    int* pazymiai;
};

void padidintiMasyva(studentas*& mas, int& masyvoDydis);
void padidintiMasyva(int*& mas, int& masyvoDydis);
studentas atsitiktinisStudentas();
void pridetiPazymius(studentas& stud);
void pridetiStudenta(studentas* mas, int masyvoDydis);
double vidurkis(int* mas);
double mediana(int* mas);
void spausdinti(studentas* mas, int masyvoDydis);

int main()
{
    studentas* mas = new studentas[1];
    int studentuNr = 1;
    int temp;
    for (int i = 0; i < studentuNr; i++) {
        pridetiStudenta(mas, studentuNr);
        temp = -1;
        cout << endl << "Prideti nauja irasa? 0 - Ne, 1 - Taip" << endl;
        while (temp != 0 && temp != 1) {
            cin >> temp;
            if (temp == 1)
            {
                padidintiMasyva(mas, studentuNr);
                cout << endl;
            }
            else if (temp != 0 || cin.fail()) {
                cout << "Ivedete neteisinga reiksme" << endl;
                temp = -1;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
    spausdinti(mas, studentuNr);
    cout << endl << "Iveskite bet koki simboli norint isjungti programa" << endl;
    cin >> temp;
    cin.ignore();
    return 0;
}

void padidintiMasyva(studentas*& mas, int& masyvoDydis) {
    masyvoDydis++;
    studentas* temp = new studentas[masyvoDydis];
    copy(mas, mas + masyvoDydis - 1, temp);
    delete[] mas;
    mas = temp;
}
void padidintiMasyva(int*& mas, int& masyvoDydis) {
    masyvoDydis++;
    int* temp = new int[masyvoDydis];
    copy(mas, mas + masyvoDydis - 1, temp);
    delete[] mas;
    mas = temp;
}

studentas atsitiktinisStudentas() {

    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> distVardai(0, vardaiN - 1), distPavardes(0, pavardesN - 1), distPazymiai(0, 10);

    studentas stud;
    string vardas, pavarde;
    vardas = vardai[distVardai(mt)];
    pavarde = pavardes[distPavardes(mt)];
    if (vardas.back() == 's') {
        pavarde += "as";
    }
    else {
        pavarde += "aite";
    }

    int* mas = new int[11];
    for (int i = 0; i < 10; i++) {
        mas[i] = distPazymiai(mt);
    }
    mas[10] = -1;

    stud.vardas = vardas;
    stud.pavarde = pavarde;
    stud.pazymiai = mas;
    stud.egzaminas = distPazymiai(mt);

    return stud;
}

void pridetiPazymius(studentas& stud) {
    int pazymiuNr = 1;
    int* mas = new int[1];
    int temp;
    cout << "Iveskite studento namu darbu pazymius (Noredami uzbaigti iveskite, bet koki simboli): ";
    while (pazymiuNr <= 1) {
        while (cin >> temp) {
            if (temp <= 10 && temp >= 0) {
                mas[pazymiuNr - 1] = temp;
                padidintiMasyva(mas, pazymiuNr);
            }
            else {
                cout << "Ivedete neteisinga reiksme" << endl;
            }
        }
        if (pazymiuNr <= 1) {
            cout << "Neivedete pazymiu" << endl;
        }
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    mas[pazymiuNr - 1] = -1;
    stud.pazymiai = mas;
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

void pridetiStudenta(studentas* mas, int masyvoDydis) {
    studentas stud;
    int temp = -1;
    cout << "Ar ivesti atsitiktinai sugeneruota studenta? 0 - Ne, 1 - Taip" << endl;
    while (temp != 0 && temp != 1) {
        cin >> temp;
        if (temp != 0 && temp != 1 || cin.fail()) {
            cout << "Ivedete neteisinga reiksme" << endl;
            temp = -1;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    if (temp == 0) {
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> stud.vardas >> stud.pavarde;
        pridetiPazymius(stud);
    }
    else {
        stud = atsitiktinisStudentas();
    }
    mas[masyvoDydis - 1] = stud;
}

double vidurkis(int* mas) {
    double sum = 0;
    int i = 0;
    while (mas[i] != -1) {
        sum += mas[i];
        i++;
    }
    return sum / i;
}

double mediana(int* mas) {
    int i = 0;
    while (mas[i] != -1) {
        i++;
    }
    sort(mas, mas + i);
    if (i % 2 == 1) {
        return mas[i / 2];
    }
    else {
        return (mas[i / 2] + mas[i / 2 - 1]) / 2.0;
    }
}

void spausdinti(studentas* mas, int masyvoDydis) {
    double galutinis;
    int temp = -1;
    cout << "Kaip skaiciuoti galutini studento pazymi? 0 - Naudojant vidurki, 1 - naudojant mediana" << endl;
    while (temp != 0 && temp != 1) {
        cin >> temp;
        if (temp != 0 && temp != 1 || cin.fail()) {
            cout << "Ivedete neteisinga reiksme" << endl;
            temp = -1;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    if (temp == 0) {
        cout << endl << "Pavarde        Vardas         Galutinis (Vid)" << endl;
    }
    else {
        cout << endl << "Pavarde        Vardas         Galutinis (Med)" << endl;
    }
    cout << "---------------------------------------------" << endl;
    for (int i = 0; i < masyvoDydis; i++) {
        if (temp == 0) {
            galutinis = vidurkis(mas[i].pazymiai) * 0.4;
        }
        else {
            galutinis = mediana(mas[i].pazymiai) * 0.4;
        }
        galutinis += mas[i].egzaminas * 0.6;
        cout << setw(15) << left << mas[i].vardas << setw(15) << left << mas[i].pavarde << setprecision(2) << fixed << galutinis << endl;
    }
}