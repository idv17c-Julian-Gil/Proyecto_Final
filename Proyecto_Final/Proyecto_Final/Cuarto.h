#pragma once
#include "Includes.h"
class Cuarto
{
public:
	Cuarto(string Name, string Description, string Analyze, vector <string> Objects, bool First);
	string m_Name = {};
	string m_Description = {};
	string m_Analyze = {};
	vector <string> Objects = {};
	bool m_First = true;

	~Cuarto();
};

