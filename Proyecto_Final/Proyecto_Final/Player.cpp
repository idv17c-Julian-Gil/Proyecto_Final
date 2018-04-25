#include "Player.h"

Player::Player() 
{

}

Player::Player(vector<string>& Inventory, string Location, bool Ganar)
{
	m_Inventory = Inventory;
	m_Location = Location;
	m_Ganar = Ganar;
}

void Player::Show_Location()
{
	string Mensaje = "Estas en ";
	int x = 0;
	while (Mensaje[x] != '\0')
	{
		cout << Mensaje [x];
		Sleep(80);
		x++;
	}
	cout << m_Location << endl;
}

void Player::Show_Inventory()
{
	if (m_Inventory.size() != 0)
	{
		string Mensaje = "Traes contigo: ";
		int x = 0;
		while (Mensaje[x] != '\0')
		{
			cout << Mensaje[x];
			Sleep(80);
			x++;
		}
		for (int i = 0; i < m_Inventory.size(); i++)
			
			cout << m_Inventory[i] + " ";
		cout << '\n' << endl;
	}
	else
	{
		string Mensaje = "No traes nada contigo por el momento";
		int x = 0;
		while (Mensaje[x] != '\0')
		{
			cout << Mensaje[x];
			Sleep(80);
			x++;
		}
		cout << '\n' << endl;
	}
}

Player::~Player()
{

}
