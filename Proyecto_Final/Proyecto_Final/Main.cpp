#include <fstream>
//#include <vector>
#include <unordered_map>
//#include <string>
//#include <iostream>
#include "Player.h"

/*
	ToDo:
		Crear descripciones para cada cuarto
		Ver que objetos va a tener cada cuarto
		Ver que interacciones va a tener cada cuarto
		Anidar cuartos
		Ver que se va a hacer cuanda se gana, si tener otro cuarto o solo una funcion con texto
*/


struct Rooms
{
	string Name;
	string Description { "" };
	string Analyze{ "" };
	vector <string> Objects;
	string Norte;
	string Sur;
	string Este;
	string Oeste;
	bool First_Visit;
};

void Inicio(bool& Empezar, Player& player)
{
	player.m_Inventory;
	player.m_Location = "Kiosko";
	Empezar = false;
}

void Input(string& palabras, vector<string>& unir)
{
	unir = {};
	cout << "Que deseas hacer? " << endl; 
	//cin >> Accion;
	getline(cin, palabras);
	palabras += ' ';
	//cout << palabras << endl;

	int j = 0;
	char palabra[20] = { 0 };

	for (int i = 0; i < palabras.length(); i++)
	{
		if (palabras[i] == ' ')
		{
			unir.push_back(palabra);
			for (int p = 0; p < 20; p++)
			{
				palabra[p] = 0;
			}
			j = 0;
		}
		else
		{
			palabra[j] = palabras[i];
			j++;
		}
	}
}

void Leer_Input(vector<string> unir, Player& player, unordered_map<string,Rooms> &Habitaciones)
{
	if (unir[0] == "ir")
		if (unir[1] == "norte")
			if (Habitaciones[player.m_Location].Norte != "No")
			{
				player.m_Location = Habitaciones[player.m_Location].Norte;
			}
			else
			{
				cout << "No se puede ir en esa direccion..." << endl;
			}
		if (unir[1] == "sur")
			if (Habitaciones[player.m_Location].Sur != "No")
			{
				player.m_Location = Habitaciones[player.m_Location].Sur;
			}
			else
			{
				cout << "No se puede ir en esa direccion..." << endl;
			}
		if (unir[1] == "este")
			if (Habitaciones[player.m_Location].Este != "No")
			{
				player.m_Location = Habitaciones[player.m_Location].Este;
			}
			else
			{
				cout << "No se puede ir en esa direccion..." << endl;
			}
		if (unir[1] == "oeste")
			if (Habitaciones[player.m_Location].Oeste != "No")
			{
				player.m_Location = Habitaciones[player.m_Location].Oeste;
			}
			else
			{
				cout << "No se puede ir en esa direccion..." << endl;
			}
		else 
		{
			cout << "No se puede ir a " << unir[1] << ", intente otravez..." << endl;
		}
		cout << "Estas en " << player.m_Location << endl;
}

void Ir(unordered_map<string,Rooms>& Habitaciones, Player& Show_Location)
{
	


}

void Assign_Room_Properties(unordered_map<string, Rooms>& Habitaciones)
{
	Rooms Kiosko;
	Kiosko.Name = "Kiosko";
	Kiosko.Description = "El centro de la plaza, hay salidas a la calle en las cuatro direcciones cardinales.";
	Kiosko.Analyze = "Es un kiosko grande y muy decorado. En la base hay unos botes de basura que estan rebosando de basura que huele bastante mal."; //Falta especificar los detalles de cada cuarto, aqui van a ir las cosas que se pueden hacer
	Kiosko.Objects = {"Revolver"};
	Kiosko.First_Visit = true;
	Habitaciones[Kiosko.Name] = Kiosko;
	

	Rooms Parque_Norte;
	Parque_Norte.Name = "Parque entrada norte";
	Parque_Norte.Description = "Estas al norte del parque, detras de ti esta la plaza y frente a ti una calle.";
	Parque_Norte.Analyze = "Es una camino corto rodeado de arbustos que va del kiosko a la calle. Hay algunas bancas a lo largo del camino y una parece tener varias cajas.";
	Parque_Norte.Objects = {"Telefono inteligente","Cuerpo de llave"};
	Parque_Norte.First_Visit = true;
	Habitaciones[Parque_Norte.Name] = Parque_Norte;

	Rooms Parque_Sur;
	Parque_Sur.Name = "Parque entrada sur";
	Parque_Sur.Description = "Estas al sur del parque, frente a ti esta una calle y detras esta el kiosko.";
	Parque_Sur.Analyze = "El camino hacia la calle esta algo destruido, con hoyos e incluso un auto volteado cerca de la calle. El auto parece tener la cajuela abierta.";
	Parque_Sur.Objects = {"Palanca"};
	Parque_Sur.First_Visit = true;
	Habitaciones[Parque_Sur.Name] = Parque_Sur;

	Rooms Parque_Este;
	Parque_Este.Name = "Parque entrada este";
	Parque_Este.Description = "Estas al este del parque, a tu izquierda hay una calle y a tu derecha esta el kiosko.";
	Parque_Este.Analyze = "El kiosko se ve quemado desde ese lado, sobre todo en la parte del techo. Hay un arbusto en llamas cerca del kiosko que emite un olor muy fuerte.";
	Parque_Este.Objects = {};
	Parque_Este.First_Visit = true;
	Habitaciones[Parque_Este.Name] = Parque_Este;

	Rooms Parque_Oeste;
	Parque_Oeste.Name = "Parque entrada oeste";
	Parque_Oeste.Description = "Estas al oeste del parque, a tu izquierda esta el kiosko y a tu derecha hay una calle.";
	Parque_Oeste.Analyze = "Parece ser uno de los lados mejor cuidados del parque, aun hay muchos arbustos y pasto. No parece haber mucho de interes que ver.";
	Parque_Oeste.Objects = {"Una bala"};
	Parque_Oeste.First_Visit = true;
	Habitaciones[Parque_Oeste.Name] = Parque_Oeste;

	Rooms Entrada_Sur;
	Entrada_Sur.Name = "Calle lado sur";
	Entrada_Sur.Description = "";
	Entrada_Sur.Objects = {};
	Entrada_Sur.First_Visit = true;
	Habitaciones[Entrada_Sur.Name] = Entrada_Sur;

	Rooms Entrada_Norte;
	Entrada_Norte.Name = "Calle lado norte";
	Entrada_Norte.Description = "";
	Entrada_Norte.Analyze = "Frente a ti hay un gran porton con un candado viejo. Detras de ti esta la entrada al parque y un cartel que lee 'Plaza Millenio'.";
	Entrada_Norte.Objects = {};
	Entrada_Norte.First_Visit = true;
	Habitaciones[Entrada_Norte.Name] = Entrada_Norte;

	Rooms Entrada_Oeste;
	Entrada_Oeste.Name = "Calle lado oeste";
	Entrada_Oeste.Description = "";
	Entrada_Oeste.Objects = {};
	Entrada_Oeste.First_Visit = true;
	Habitaciones[Entrada_Oeste.Name] = Parque_Oeste;

	Rooms Entrada_Este;
	Entrada_Este.Name = "Calle lado este";
	Entrada_Este.Description = "";
	Entrada_Este.Objects = {};
	Entrada_Este.First_Visit = true;
	Habitaciones[Entrada_Este.Name] = Entrada_Este;

	Rooms Esquina_Noreste;
	Esquina_Noreste.Name = "Calle interseccion norte con este";
	Esquina_Noreste.Description = "";
	Esquina_Noreste.Objects = {};
	Esquina_Noreste.First_Visit = true;
	Habitaciones[Esquina_Noreste.Name] = Esquina_Noreste;

	Rooms Esquina_Noroeste;
	Esquina_Noroeste.Name = "Calle interseccion norte con oeste";
	Esquina_Noroeste.Description = "";
	Esquina_Noroeste.Objects = {};
	Esquina_Noroeste.First_Visit = true;
	Habitaciones[Esquina_Noroeste.Name] = Esquina_Noroeste;

	Rooms Esquina_Sureste;
	Esquina_Sureste.Name = "Calle interseccion sur con este";
	Esquina_Sureste.Description = "";
	Esquina_Sureste.Objects = {};
	Esquina_Sureste.First_Visit = true;
	Habitaciones[Esquina_Sureste.Name] = Esquina_Sureste;

	Rooms Esquina_Suroeste;
	Esquina_Suroeste.Name = "Calle interseccion sur con oeste";
	Esquina_Suroeste.Description = "";
	Esquina_Suroeste.Objects = {};
	Esquina_Suroeste.First_Visit = true;
	Habitaciones[Esquina_Suroeste.Name] = Esquina_Suroeste;

	//Aqui se anexan los cuartos y a donde puedes ir
	//Desde el Kiosko
	(Habitaciones[Kiosko.Name]).Norte = Parque_Norte.Name;
	(Habitaciones[Kiosko.Name]).Sur = Parque_Sur.Name;
	(Habitaciones[Kiosko.Name]).Este = Parque_Este.Name;
	(Habitaciones[Kiosko.Name]).Oeste = Parque_Oeste.Name;

	//Desde Parque_Norte
	(Habitaciones[Parque_Norte.Name]).Norte = Entrada_Norte.Name;
	(Habitaciones[Parque_Norte.Name]).Sur = Kiosko.Name;
	(Habitaciones[Parque_Norte.Name]).Este = "No";
	(Habitaciones[Parque_Norte.Name]).Oeste = "No";

	//Desde Parque_Sur
	(Habitaciones[Parque_Sur.Name]).Norte = Kiosko.Name;
	(Habitaciones[Parque_Sur.Name]).Sur = Entrada_Sur.Name;
	(Habitaciones[Parque_Sur.Name]).Este = "No";
	(Habitaciones[Parque_Sur.Name]).Oeste = "No";

	//Desde Parque_Este
	(Habitaciones[Parque_Este.Name]).Norte= "No";
	(Habitaciones[Parque_Este.Name]).Sur = "No";
	(Habitaciones[Parque_Este.Name]).Este = Entrada_Este.Name;
	(Habitaciones[Parque_Este.Name]).Oeste = Kiosko.Name;

	//Desde Parque_Oeste
	(Habitaciones[Parque_Oeste.Name]).Norte = "No";
	(Habitaciones[Parque_Oeste.Name]).Sur = "No";
	(Habitaciones[Parque_Oeste.Name]).Este = Kiosko.Name;
	(Habitaciones[Parque_Oeste.Name]).Oeste = Entrada_Oeste.Name;

	//Desde Entrada_Norte
	(Habitaciones[Entrada_Norte.Name]).Norte = "Si"; //Ver como ganar
	(Habitaciones[Entrada_Norte.Name]).Sur = Parque_Norte.Name;
	(Habitaciones[Entrada_Norte.Name]).Este = Esquina_Noreste.Name;
	(Habitaciones[Entrada_Norte.Name]).Oeste = Esquina_Noroeste.Name;

	//Desde Entrada_Sur
	(Habitaciones[Entrada_Sur.Name]).Norte = Parque_Norte.Name;
	(Habitaciones[Entrada_Sur.Name]).Sur = "No";
	(Habitaciones[Entrada_Sur.Name]).Este = Esquina_Sureste.Name;
	(Habitaciones[Entrada_Sur.Name]).Oeste = Esquina_Suroeste.Name;

	//Desde Entrada_Este
	(Habitaciones[Entrada_Este.Name]).Norte = Esquina_Noreste.Name;
	(Habitaciones[Entrada_Este.Name]).Sur = Esquina_Sureste.Name;
	(Habitaciones[Entrada_Este.Name]).Este = "No";
	(Habitaciones[Entrada_Este.Name]).Oeste = Parque_Este.Name;

	//Desde Entrada_Oeste
	(Habitaciones[Entrada_Oeste.Name]).Norte = Esquina_Noroeste.Name;
	(Habitaciones[Entrada_Oeste.Name]).Sur = Esquina_Suroeste.Name;
	(Habitaciones[Entrada_Oeste.Name]).Este = Parque_Oeste.Name;
	(Habitaciones[Entrada_Oeste.Name]).Oeste = "No";

	//Desde Esquina_Noreste
	(Habitaciones[Esquina_Noreste.Name]).Norte = "No";
	(Habitaciones[Esquina_Noreste.Name]).Sur = Entrada_Este.Name;
	(Habitaciones[Esquina_Noreste.Name]).Este = "No";
	(Habitaciones[Esquina_Noreste.Name]).Oeste = Entrada_Norte.Name;

	//Desde Equina_Noroeste
	(Habitaciones[Esquina_Noreste.Name]).Norte = "No";
	(Habitaciones[Esquina_Noreste.Name]).Sur = Entrada_Oeste.Name;
	(Habitaciones[Esquina_Noreste.Name]).Este = Entrada_Norte.Name;
	(Habitaciones[Esquina_Noreste.Name]).Oeste = "No";

	//Desde Esquina_Sureste
	(Habitaciones[Esquina_Noreste.Name]).Norte = Entrada_Este.Name;
	(Habitaciones[Esquina_Noreste.Name]).Sur = "No";
	(Habitaciones[Esquina_Noreste.Name]).Este = "No";
	(Habitaciones[Esquina_Noreste.Name]).Oeste = Entrada_Sur.Name;

	//Desde Esquina_Suroeste
	(Habitaciones[Esquina_Noreste.Name]).Norte = Entrada_Oeste.Name;
	(Habitaciones[Esquina_Noreste.Name]).Sur = "No";
	(Habitaciones[Esquina_Noreste.Name]).Este = Entrada_Sur.Name;
	(Habitaciones[Esquina_Noreste.Name]).Oeste = "No";
}

int main()
{
	/*
	Aqui se les va a dar los valores a los cuartos
	La primera vez que el jugar visite cada lugar, se le dara una descripcion adicional la cual se podra analizar despues
	*/

	//Aqui se acaba la asignacion de los cuartos
	unordered_map<string, Rooms> Habitacion;
	
	//Habitacion["Kiosko"] = Rooms();
	
	//Esto es para probar

	vector<Rooms> Cuartos;
	//string Current_Room = "Kiosko";
	vector <string> Pockets = { "vaso", "llaves", "carro"};
	Player Jugador;

	Assign_Room_Properties(Habitacion);
	//
	//Jugador.Show_Location();
	//Jugador.Show_Inventory();
	//cout << endl;

	//Aqui acaba la prueba

	bool Empezar = true;
	string Input_Usuario;
	vector <string> Union;
	if (Empezar == true);
	{
		Inicio(Empezar, Jugador);
	}

	while (Input_Usuario != "salir")
	{ 
		Input(Input_Usuario, Union);
		Leer_Input(Union, Jugador, Habitacion);
		Input_Usuario = {};
		//cout << Jugador.m_Location << endl;
	}
	

	//cout << Union[0] << ' ' << Union[1] << endl;
	
	cin.get();
	return 0;
}