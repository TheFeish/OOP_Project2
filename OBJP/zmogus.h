/// <summary>
/// @file zmogus.h
/// Header file for zmogus class.
/// </summary>
#pragma once
#include "myLib.h"
/// <summary>
/// Object that holds information about a person.
/// </summary>
class zmogus {
protected:
	string vardas, pavarde;
	/// <summary>
	/// Destroys **zmogus** object.
	/// </summary>
	~zmogus() {}
public:
	/// <summary>
	/// Creates an empty **zmogus** object.
	/// @returns empty **zmogus** object.
	/// </summary>
	zmogus() : vardas(""), pavarde("") {}

	/// <summary>
	/// Creates a **zmogus** object with name and surname values.
	/// @param var This describes person's name.
	/// @param pav This describes person's surname.
	/// @returns **zmogus** object with name and surname values.
	/// </summary>
	zmogus(string var, string pav);

	/// <summary>
	/// Pure virtual function for printing object's data.
	/// @param out **ostringstream** object for output.
	/// </summary>
	virtual void spausdinti(ostringstream& out) = 0;

	/// <summary>
	/// Gets **vardas** value.
	/// @returns **vardas** value.
	/// </summary>
	string grazintiVarda();

	/// <summary>
	/// Gets **pavarde** value.
	/// @returns **pavarde** value.
	/// </summary>
	string grazintiPavarde();

	/// <summary>
	/// Sets **vardas** value.
	/// @param var New **vardas** value.
	/// </summary>
	void nustatytiVarda(string var);

	/// <summary>
	/// Sets **pavarde** value.
	/// @param var New **pavarde** value.
	/// </summary>
	void nustatytipavarde(string pav);
};