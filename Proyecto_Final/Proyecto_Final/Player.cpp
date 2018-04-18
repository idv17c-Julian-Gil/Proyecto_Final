#include "Player.h"

Player::Player() 
{

}

Player::Player(vector<string>& Inventory, string Location)
{
	m_Inventory = Inventory;
	m_Location = Location;
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
}

Player::~Player()
{
}
