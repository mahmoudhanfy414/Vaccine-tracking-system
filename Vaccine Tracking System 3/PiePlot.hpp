/*#ifndef PYHELPER_HPP
#define PYHELPER_HPP
#pragma once
#include "User.h"
#include "System.h"
#include <iostream>
#include <Python.h>

class CPyInstance
{
public:
	CPyInstance()
	{
		Py_Initialize();
	}
	~CPyInstance()
	{
		Py_Finalize();
	}
};
class CPyObject
{
private:
	PyObject* p;
public:
	CPyObject() : p(NULL)
	{}
	CPyObject(PyObject* _p) : p(_p)
	{}

	~CPyObject()
	{
		Release();
	}
	void Release()
	{
		if (p)
		{
			Py_DECREF(p);
		}
		p = NULL;
	}
	operator PyObject* ()
	{
		return p;
	}
};*/
/**
 * plot pie chart with two numbers.
 *  using matplotlib library in python.
 *
 * @param value1, value2, Label1, Label2, plot_name.
 */
/*
void PieChart()
{
	CPyInstance hInstance;
	CPyObject pName = PyUnicode_FromString("PieChartModule");
	CPyObject pModule = PyImport_Import(pName);
	if (pModule)
	{
		CPyObject pFunc = PyObject_GetAttrString(pModule, "piechart");
		if (pFunc && PyCallable_Check(pFunc))
		{
			
			PyObject_CallFunction(pFunc, "I,I,s,s,s", User::count_Female, User::count_male, "Female", "Male", "Percentage Of Females And Males Registered In The System");

			PyObject_CallFunction(pFunc, "I,I,s,s,s", int(Vaccine::ones_count/System::users.size()), System::users.size(), "One Dose", "Two Doses", "Percentage Of People Who took the First Dose And The Second One ");

			PyObject_CallFunction(pFunc, "I,I,s,s,s", Vaccine::one_dose_Female, Vaccine::one_dose_male, "Female", "Male", "Percentage Of Females And Males Who Took the 1st dose");

			PyObject_CallFunction(pFunc, "I,I,s,s,s", Vaccine::both_dose_Female, Vaccine::both_dose_Female, "Female", "Male", "Percentage Of Females And Males Who Took the both doses");

			PyObject_CallFunction(pFunc, "I,I,s,s,s", Vaccine::one_dose_Female, Vaccine::both_dose_Female, "One Dose", "Two Doses", "Percentage Of Females  Who Took the 1st dose and 2nd dose");

			PyObject_CallFunction(pFunc, "I,I,s,s,s", Vaccine::one_dose_male, Vaccine::both_dose_male, "One Dose", "Two Doses", "Percentage Of males  Who Took the 1st dose and 2nd dose");
		
		}
		else
		{
			printf("ERROR: function not found\n");
		}
	}
	else
	{
		printf_s("ERROR: Module not imported\n");
	}
}
#endif
*/