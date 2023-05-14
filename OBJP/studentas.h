/// <summary>
/// @file studentas.h
/// Header file for studentas class.
/// </summary>
#pragma once
#include "myLib.h"
#include "zmogus.h"
/// <summary>
/// Object that holds information about a student.
/// </summary>
class studentas: public zmogus
{
private:
	double mediana, vidurkis;
	int egzaminas;
	vector<int> pazymiai;
public:
	/// <summary>
	/// Creates an empty **studentas** object.
	/// @returns empty **studentas** object.
	/// </summary>
	studentas() : zmogus{}, mediana(0), vidurkis(0), egzaminas(0), pazymiai() {}

	/// <summary>
	/// Creates a **studentas** object with name, surname, median, average and exam values.
	/// @param var This describes student's name.
	/// @param pav This describes student's surname.
	/// @param med This describes median value of student's grades.
	/// @param vid This describes average value of student's grades.
	/// @param egz This describes student's exam grade.
	/// @returns **studentas** object with name, surname, median, average and exam values.
	/// </summary>
	studentas(string var, string pav, double med, double vid, int egz);

	/// <summary>
	/// Creates a **studentas** object with name, surname, median, average, exam and grade values.
	/// @param var This describes student's name.
	/// @param pav This describes student's surname.
	/// @param med This describes median value of student's grades.
	/// @param vid This describes average value of student's grades.
	/// @param egz This describes student's exam grade.
	/// @param paz This describes student's grades.
	/// @returns **studentas** object with name, surname, median, average, exam and grade values.
	/// </summary>
	studentas(string var, string pav, double med, double vid, int egz, vector<int> paz);

	/// <summary>
	/// Creates a copy of **zmogus** object.
	/// @param val **studentas** object to copy.
	/// @returns a copy of **zmogus** object.
	/// </summary>
	studentas(const studentas& val);

	/// <summary>
	/// Moves data from one **studentas** object to another.
	/// @param val **studentas** object to move.
	/// @returns a new **studentas** object with data from another.
	/// @note This function deletes data from original **studentas** object.
	/// </summary>
	studentas(studentas&& val);

	/// <summary>
	/// Destroys **studentas** object.
	/// </summary>
	~studentas() {}

	/// <summary>
	/// Overrides copy assingnment operator.
	/// </summary>
	studentas& operator=(const studentas& val);

	/// <summary>
	/// Overrides move assingnment operator.
	/// </summary>
	studentas& operator=(studentas&& val);

	/// <summary>
	/// Overrides less than operator.
	/// </summary>
	bool operator<(studentas& val);

	/// <summary>
	/// Overrides put-to operator.
	/// </summary>
	friend ostream& operator<< (ostream& out, const studentas& val);

	/// <summary>
	/// prints out **studentas** name, surname and either average or median grade values.
	/// @param out **ostringstream** object for output.
	/// @param arVidurkis **true** to print out **average** value or **false** to print out **median** value.
	/// </summary>
	void spausdinti(ostringstream& out, bool arVidurkis);

	/// <summary>
	/// prints out **studentas** name, surname, grade, and exam values.
	/// @param out **ostringstream** object for output.
	/// </summary>
	void spausdinti(ostringstream& out);

	/// <summary>
	/// Gets **pazymiai** value.
	/// @returns **pazymiai** value.
	/// </summary>
	vector<int> grazintiPazymius();

	/// <summary>
	/// Gets **mediana** value.
	/// @returns **mediana** value.
	/// </summary>
	double grazintiMediana();

	/// <summary>
	/// Gets **vidurkis** value.
	/// @returns **vidurkis** value.
	/// </summary>
	double grazintiVidurki();

	/// <summary>
	/// Gets **egzaminas** value.
	/// @returns **egzaminas** value.
	/// </summary>
	int grazintiEgzamina();

	/// <summary>
	/// Sets **pazymiai** value.
	/// @param var New **pazymiai** value.
	/// </summary>
	void nustatytiPazymius(vector<int> paz);

	/// <summary>
	/// Sets **mediana** value.
	/// @param var New **mediana** value.
	/// </summary>
	void nustatytiMediana(double med);

	/// <summary>
	/// Sets **vidurkis** value.
	/// @param var New **vidurkis** value.
	/// </summary>
	void nustatytiVidurki(double vid);

	/// <summary>
	/// Sets **egzaminas** value.
	/// @param var New **egzaminas** value.
	/// </summary>
	void nustatytiEgzamina(int egz);
};