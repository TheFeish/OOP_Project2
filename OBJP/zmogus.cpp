/// <summary>
/// @file zmogus.cpp
/// Implementation of zmogus class functions.
/// </summary>
#include "zmogus.h"
#include "myLib.h"

zmogus::zmogus(string var, string pav) : vardas(var), pavarde(pav) {}

string zmogus::grazintiVarda() { return vardas; }
string zmogus::grazintiPavarde() { return pavarde; }

void zmogus::nustatytiVarda(string var) { vardas = var; }
void zmogus::nustatytipavarde(string pav) { pavarde = pav; }