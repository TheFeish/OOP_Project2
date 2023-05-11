#pragma once
#include "myLib.h"
class zmogus {
protected:
	string vardas, pavarde;
	~zmogus() {}
public:
	zmogus() : vardas(""), pavarde("") {}
	zmogus(string var, string pav);

	virtual void spausdinti(ostringstream& out) = 0;

	string grazintiVarda();
	string grazintiPavarde();

	void nustatytiVarda(string var);
	void nustatytipavarde(string pav);
};