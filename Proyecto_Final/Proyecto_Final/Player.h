#pragma once
#include "Includes.h"
#include "Cuarto.h"
//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;

class Player
{
public:
	Player();
	Player(vector<string>& Inventory, string Location);
	~Player();
	string m_Location = { "" };
	vector<string> m_Inventory = { "" };

	void Show_Location();
	void Show_Inventory();
	
};

