/// <summary>
/// @file funkcijos.h
/// Other functions used in program.
/// </summary>
#pragma once
#include "studentas.h"

/// <summary>
/// Writes randomized values into **studentas** object.
/// @param stud **studentas** object to write in.
/// @param nr Number of grades to write.
/// @param generuotiVisusPaz Whether to write grade values into **studentas**.
/// </summary>
void atsitiktinisStudentas(studentas& stud, int nr, bool generuotiVisusPaz);

/// <summary>
/// Function for manually writing grades into **studentas** object.
/// @param stud **studentas** object to write in.
/// @param vardas Name of student.
/// @param pavarde Surname of student.
/// </summary>
void pridetiPazymius(studentas& stud, string vardas, string pavarde);
//-------------------------------------------------------------------------------------------------------------

/// <summary>
/// Adds new **studentas** to **vector**.
/// @param mas **vector** to write in
/// </summary>
void pridetiStudenta(vector<studentas>& mas);

/// <summary>
/// Adds new **studentas** to **list**.
/// @param mas **list** to write in
/// </summary>
void pridetiStudenta(list<studentas>& mas);

/// <summary>
/// Adds new **studentas** to **deque**.
/// @param mas **deque** to write in
/// </summary>
void pridetiStudenta(deque<studentas>& mas);
//-------------------------------------------------------------------------------------------------------------

/// <summary>
/// Calculates average value of student's grades.
/// @param mas Student's grades
/// @returns average value of student's grades.
/// </summary>
double vidurkis(vector<int> mas);

/// <summary>
/// Calculates median value of student's grades.
/// @param mas Student's grades
/// @returns median value of student's grades.
/// </summary>
double mediana(vector<int> mas);
//-------------------------------------------------------------------------------------------------------------
/// <summary>
/// Writes all students' names, surnames and either average or median grade values into files.
/// @param mas1 Students with passing grades.
/// @param mas2 Students without passing grades.
/// @param spBudas **0** to print **average** value. **1** to print **median** value.
/// @param visasLaikas Program run time for calculating execution time.
/// </summary>
void spausdinti(vector<studentas> mas1, vector<studentas> mas2, int spBudas, double& visasLaikas);

/// <summary>
/// Writes all students' names, surnames and either average or median grade values into files.
/// @param mas1 Students with passing grades.
/// @param mas2 Students without passing grades.
/// @param spBudas **0** to print **average** value. **1** to print **median** value.
/// @param visasLaikas Program run time for calculating execution time.
/// </summary>
void spausdinti(list<studentas> mas1, list<studentas> mas2, int spBudas, double& visasLaikas);

/// <summary>
/// Writes all students' names, surnames and either average or median grade values into files.
/// @param mas1 Students with passing grades.
/// @param mas2 Students without passing grades.
/// @param spBudas **0** to print **average** value. **1** to print **median** value.
/// @param visasLaikas Program run time for calculating execution time.
/// </summary>
void spausdinti(deque<studentas> mas1, deque<studentas> mas2, int spBudas, double& visasLaikas);
//-------------------------------------------------------------------------------------------------------------

/// <summary>
/// Show a question that can be aswered by typing either 0 or 1 into console.
/// @param zinute Question to show.
/// @returns 0 or 1 based on user's answer.
/// </summary>
int klausimas0_1(string zinute);
//-------------------------------------------------------------------------------------------------------------

/// <summary>
/// Reads student data from a file.
/// @param mas **vector** to write in.
///	@param visasLaikas Program run time for calculating execution time.
/// </summary>
void skaitytiIsFailo(vector<studentas>& mas, double& visasLaikas);

/// <summary>
/// Reads student data from a file.
/// @param mas **list** to write in.
///	@param visasLaikas Program run time for calculating execution time.
/// </summary>
void skaitytiIsFailo(list<studentas>& mas, double& visasLaikas);

/// <summary>
/// Reads student data from a file.
/// @param mas **deque** to write in.
///	@param visasLaikas Program run time for calculating execution time.
/// </summary>
void skaitytiIsFailo(deque<studentas>& mas, double& visasLaikas);
//-------------------------------------------------------------------------------------------------------------

/// <summary>
/// Creates students' data file.
/// @param studNr Number of students to write.
///	@param pazNr Number of grades to write.
/// @param pavadinimas Name of the file.
/// </summary>
void kurtiFaila(int studNr, int pazNr, string pavadinimas);
//-------------------------------------------------------------------------------------------------------------

/// <summary>
/// Sorts students by name and splits them into two groups based on their final grade.
/// @param sudentai All students.
/// @param vargsai **vector** to write students without passing grade in.
/// @param kietiakai **vector** to write students with passing grade in.
/// @param rusBudas **0** to split students based on **average** value. **1** to split students based on **median** value.
///	@param visasLaikas Program run time for calculating execution time.
/// </summary>
void skirstitiStudentus(vector<studentas>& studentai, vector<studentas>& vargsai, vector<studentas>& kietiakai, int rusBudas, double& visasLaikas);

/// <summary>
/// Sorts students by name and splits them into two groups based on their final grade.
/// @param sudentai All students.
/// @param vargsai **list** to write students without passing grade in.
/// @param kietiakai **list** to write students with passing grade in.
/// @param rusBudas **0** to split students based on **average** value. **1** to split students based on **median** value.
///	@param visasLaikas Program run time for calculating execution time.
/// </summary>
void skirstitiStudentus(list<studentas>& studentai, list<studentas>& vargsai, list<studentas>& kietiakai, int rusBudas, double& visasLaikas);

/// <summary>
/// Sorts students by name and splits them into two groups based on their final grade.
/// @param sudentai All students.
/// @param vargsai **deque** to write students without passing grade in.
/// @param kietiakai **deque** to write students with passing grade in.
/// @param rusBudas **0** to split students based on **average** value. **1** to split students based on **median** value.
///	@param visasLaikas Program run time for calculating execution time.
/// </summary>
void skirstitiStudentus(deque<studentas>& studentai, deque<studentas>& vargsai, deque<studentas>& kietiakai, int rusBudas, double& visasLaikas);

/// <summary>
/// Sorts students by name and splits them into two groups based on their final grade.
/// @param kietiakai All students. After execution only students with passing grades are left.
/// @param vargsai **vector** to write students without passing grade in.
/// @param rusBudas **0** to split students based on **average** value. **1** to split students based on **median** value.
///	@param visasLaikas Program run time for calculating execution time.
/// </summary>
void skirstitiStudentus2(vector<studentas>& kietiakai, vector<studentas>& vargsai, int rusBudas, double& visasLaikas);

/// <summary>
/// Sorts students by name and splits them into two groups based on their final grade.
/// @param kietiakai All students. After execution only students with passing grades are left.
/// @param vargsai **list** to write students without passing grade in.
/// @param rusBudas **0** to split students based on **average** value. **1** to split students based on **median** value.
///	@param visasLaikas Program run time for calculating execution time.
/// </summary>
void skirstitiStudentus2(list<studentas>& kietiakai, list<studentas>& vargsai, int rusBudas, double& visasLaikas);

/// <summary>
/// Sorts students by name and splits them into two groups based on their final grade.
/// @param kietiakai All students. After execution only students with passing grades are left.
/// @param vargsai **deque** to write students without passing grade in.
/// @param rusBudas **0** to split students based on **average** value. **1** to split students based on **median** value.
///	@param visasLaikas Program run time for calculating execution time.
/// </summary>
void skirstitiStudentus2(deque<studentas>& kietiakai, deque<studentas>& vargsai, int rusBudas, double& visasLaikas);