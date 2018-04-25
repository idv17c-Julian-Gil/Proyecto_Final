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
	//ofstream* Partida = new ofstream;
	//Partida->open ("Partida.txt");
}

void Win(Player& player, unordered_map<string, Rooms> Habitaciones, vector <string> unir, bool ganar)
{
	bool Chequeo = false;
	if (ganar == true)
	{
		Chequeo = true;
	}
	int x;
	if (Habitaciones[player.m_Location].Name == "Calle lado norte" &&  Chequeo == true && unir[0]=="abrir")
	{
		x = 1;
	}
	if (Habitaciones[player.m_Location].Name == "Calle lado norte" && Chequeo == true && unir[0]=="disparar")
	{
		x = 2;
	}

	switch (x)
	{
	case 1:
		cout << "Con las partes que encontraste logras formar una llave y puedes abrir el porton que te evitaba salir." << endl
			<< "Ahora puedes ir a terminar tu proyecto antes de que te reprueben." << endl;
		player.m_Ganar = true;
		break;
	case 2:
		cout << "Decides cargar la bala en el revolver y le disparas al candado. Como estaba muy viejo se hace pedazos al instante y logras escapar." << endl
			<< "Una forma poco ortodoxa de lograr lo que querias, pero funciona. Ahora corre a casa a terminar el trabajo." << endl;
		player.m_Ganar = true;
		break;
	default:
		cout << "No puedes hacer eso..." << endl;
		break;
	}
}

bool In_Llave(Player player, vector <string> unir)
{
	if (find(player.m_Inventory.begin(), player.m_Inventory.end(), "Cuerpo de llave") != player.m_Inventory.end() && find(player.m_Inventory.begin(), player.m_Inventory.end(), "Cabeza de llave") != player.m_Inventory.end() && find(player.m_Inventory.begin(), player.m_Inventory.end(), "Dientes de llave") != player.m_Inventory.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool In_Disparo(Player player, vector <string> unir)
{
	if (find(player.m_Inventory.begin(), player.m_Inventory.end(), "Revolver") != player.m_Inventory.end()&& find(player.m_Inventory.begin(), player.m_Inventory.end(), "Una bala") != player.m_Inventory.end())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Objetivo()
{
	string Mensaje = "Tu objetivo es escapar de la plaza y llegar a casa a tiempo para acabar tu proyecto de programacion";
	int x = 0;
	while (Mensaje[x] != '\0')
	{
		cout << Mensaje[x];
		Sleep(60);
		x++;
	}
	cout << '\n' << endl;
}

void Ayuda()
{
	cout << "Acciones: Ir (seguido por un punto cardinal), Analizar, Agarrar, Guardar, Inventario" << '\n' << endl;
}

void Input(string& palabras, vector<string>& unir)
{
	unir = {};
	cout << "==================================================" << endl;
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

void Ir(vector<string> unir, Player& player, unordered_map<string, Rooms>& Habitaciones)
{
	int i = 0;
	if (unir[1] == "norte")
		i = 1;
	if (unir[1] == "sur")
		i = 2;
	if (unir[1] == "este")
		i = 3;
	if (unir[1] == "oeste")
		i = 4;
	switch (i)
	{
	case 1:
		if (Habitaciones[player.m_Location].Norte != "No")
		{
			player.m_Location = Habitaciones[player.m_Location].Norte;
			int x = 0;
			string Mensaje = "Estas en " + player.m_Location;
			while (Mensaje[x] != '\0')
			{
				cout << Mensaje[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
			if (Habitaciones[player.m_Location].First_Visit == true)
				Habitaciones[player.m_Location].First_Visit = false;
		}
		else
		{
			string Mensaje = "Ya no puedes ir mas al " + unir[1] + '\n' + "Te quedas en " + player.m_Location + '\n';
			int x = 0;
			while (Mensaje[x] != '\0')
			{
				cout << Mensaje[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
		}
		break;
	case 2:
		if (Habitaciones[player.m_Location].Sur != "No")
		{
			player.m_Location = Habitaciones[player.m_Location].Sur;
			int x = 0;
			string Mensaje = "Estas en " + player.m_Location;
			while (Mensaje[x] != '\0')
			{
				cout << Mensaje[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
			if (Habitaciones[player.m_Location].First_Visit == true)
				Habitaciones[player.m_Location].First_Visit = false;

		}
		else
		{
			string Mensaje = "Ya no puedes ir mas al " + unir[1] + '\n' + "Te quedas en " + player.m_Location + '\n';
			int x = 0;
			while (Mensaje[x] != '\0')
			{
				cout << Mensaje[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
		}
		break;
	case 3:
		if (Habitaciones[player.m_Location].Este != "No")
		{
			player.m_Location = Habitaciones[player.m_Location].Este;
			int x = 0;
			string Mensaje = "Estas en " + player.m_Location;
			while (Mensaje[x] != '\0')
			{
				cout << Mensaje[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
			if (Habitaciones[player.m_Location].First_Visit == true)
				Habitaciones[player.m_Location].First_Visit = false;
		}
		else
		{
			string Mensaje = "Ya no puedes ir mas al " + unir[1] + '\n' + "Te quedas en " + player.m_Location + '\n';
			int x = 0;
			while (Mensaje[x] != '\0')
			{
				cout << Mensaje[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
		}
		break;
	case 4:
		if (Habitaciones[player.m_Location].Oeste != "No")
		{
			player.m_Location = Habitaciones[player.m_Location].Oeste;
			int x = 0;
			string Mensaje = "Estas en " + player.m_Location;
			while (Mensaje[x] != '\0')
			{
				cout << Mensaje[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
			if (Habitaciones[player.m_Location].First_Visit == true)
				Habitaciones[player.m_Location].First_Visit = false;
		}
		else
		{
			string Mensaje = "Ya no puedes ir mas al " + unir[1] + '\n' + "Te quedas en " + player.m_Location + '\n';
			int x = 0;
			while (Mensaje[x] != '\0')
			{
				cout << Mensaje[x];
				Sleep(60);
				x++;
			}
			cout << '\n' << endl;
		}
		break;
	default:
		cout << "No se puede ir a " << unir[1] << ", intente otravez..." << endl;
		cout << "Te quedas en " << player.m_Location << endl << endl;
		break;
	}
} //Ya camina el wey :)

void Analizar(Player& player, unordered_map<string,Rooms>& Habitaciones)
{
	cout << Habitaciones[player.m_Location].Analyze << '\n' << endl;
}

void Cargar_Partida(unordered_map<string,Rooms>& Habitaciones)
{
	int Nombre[13] = { 1,5,9,13,17,21,25,29,33,37,41,45,49 };
	int Visitado[13] = { 2,6,10,14,18,22,26,30,34,38,42,46,50 };
	int Objetos[13] = { 3,7,11,15,19,23,27,31,35,39,43,47,51 };
	string Word;
	int x = 1;
	Rooms temporal;
	string F_Name = "Mapa.txt";
	ifstream(Cargar);
	cout << "Cargando..." << '\n' << endl;
	Cargar.open(F_Name.c_str(), ios::in);
	bool N = false;
	bool FV = false;
	bool O = false;
	if (Cargar.fail())
	{
		cout << "Hubo un error cargando tu partida..." << endl;
	}
	while (!Cargar.eof())
	{
		if (Word == " ")
			x++;
		if (any_of(begin(Nombre), end(Nombre), [=](int n) {return n == x; }))
		{
			getline(Cargar, Word);
			temporal.Name = Word;
		}
		else if (any_of(begin(Visitado), end(Visitado), [=](int n) {return n == x; }))
		{
			getline(Cargar, Word);
			if (Word == "0")
				temporal.First_Visit = false;
			else
				temporal.First_Visit = true;
		}
		else if (any_of(begin(Objetos), end(Objetos), [=](int n) {return n == x; }))
		{
			getline(Cargar, Word);
			temporal.Objects.push_back(Word);
		}
		Habitaciones[temporal.Name].Name = temporal.Name;
		Habitaciones[temporal.Name].First_Visit = temporal.First_Visit;
		Habitaciones[temporal.Name].Objects = temporal.Objects;
		x++;
		if (x > 13)
			break;
	}
}

void Cargar_Jugador(Player& player)
{
	string Nombre = "Jugador.txt";
	ifstream(Cargar);
	int x = 1;
	string Word;
	Cargar.open(Nombre.c_str(), ios::in);
	if (Cargar.fail())
	{
		cout << "Hubo un error cargando tu partida..." << endl;
	}
	while (!Cargar.eof())
	{
		if (x == 1)
		{
			getline(Cargar, Word);
			player.m_Location = Word;
		}
		if (x == 2)
		{
			getline(Cargar, Word);
			if (Word == "0")
				player.m_Ganar = false;
			else
				player.m_Ganar = true;
		}
		if (x == 3)
		{
			getline(Cargar, Word);
			player.m_Inventory.push_back(Word);
		}
		x++;
		if (x > 3)
			break;
	}
}

void Coger(Player& player, unordered_map<string, Rooms>& Habitaciones)
{
	if ((Habitaciones[player.m_Location].Objects.size()) == 0)
	{
		cout << "No hay nada que tomar" << endl;
	}
	else
	{
		cout << "Despues de investigar el area, agarraste:" << " ";
		for (int i = 0; i < Habitaciones[player.m_Location].Objects.size(); i++)
		{
			cout << Habitaciones[player.m_Location].Objects[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < Habitaciones[player.m_Location].Objects.size(); i++)
		{
			int x = (Habitaciones[player.m_Location].Objects.size()) - 1;
			player.m_Inventory.push_back(Habitaciones[player.m_Location].Objects[x]);
		}
		Habitaciones[player.m_Location].Objects.clear();
	}
	cout << endl;
}

ofstream& operator<<(ofstream* ofst, unordered_map<string, Rooms>& Habitaciones)
{
	for (auto iter = Habitaciones.begin(); iter != Habitaciones.end(); iter++)
	{
		*ofst << iter->second.Name << endl;
		auto guia = iter->second.Name;
		//Poner el resto
		//*ofst << iter->second.Description << endl;
		//*ofst << iter->second.Analyze << endl;
		*ofst << iter->second.First_Visit << endl;
		//*ofst << iter->second.Norte << endl;
		//*ofst << iter->second.Sur << endl;
		//*ofst << iter->second.Este << endl;
		//*ofst << iter->second.Oeste << endl;
		for (int i = 0; i < iter->second.Objects.size(); i++) //Ya le puse parentesis
		{
			if (iter->second.Name==guia)
			{
				*ofst << iter->second.Objects[i] << '\n';
			}
		}
		*ofst << endl;
	}
	return *ofst;
}

ofstream& operator<<(ofstream* ofst, Player& player)
{
	*ofst << player.m_Location << endl;
	*ofst << player.m_Ganar << endl;
	for (int i = 0; i < player.m_Inventory.size(); i++)
	{
		*ofst << player.m_Inventory[i] << endl;
	}
	return *ofst;
}

void Guardar_Partida(unordered_map<string,Rooms>& Habitaciones)
{
	ofstream *Mapa = new ofstream;
	Mapa->open("Mapa.txt");
	Mapa << Habitaciones;
	if (Mapa!=nullptr)
		delete Mapa;
}

void Guardar_Jugador(Player player)
{
	ofstream *Jugador = new ofstream;
	Jugador->open("Jugador.txt");
	Jugador << player << endl;
	if (Jugador != nullptr)
		delete Jugador;
	cout << "Partida guardada con exito!!" << '\n' << endl;
}

void Leer_Input(vector<string> unir, Player& player, unordered_map<string,Rooms> &Habitaciones, bool& ganar)
{
	if (unir[0] == "ir")
		Ir(unir, player, Habitaciones);
	if (unir[0] == "analizar")
		Analizar(player,Habitaciones);
	if (unir[0] == "agarrar" || unir[0] == "desvirgar")
		Coger(player,Habitaciones);
	if (unir[0] == "salir" || unir[0] == "guardar")
	{
		Guardar_Partida(Habitaciones);
		Guardar_Jugador(player);
		if (unir[0] == "salir")
		{
			Sleep(200);
			exit(0);
		}
	}
	if (unir[0] == "inventario")
		player.Show_Inventory();
	if (unir[0] == "ayuda" || unir[0] == "?")
		Ayuda();
	if (unir[0] == "disparar" || unir[0] == "abrir")
		Win(player, Habitaciones, unir, ganar);
}

void Assign_Room_Properties(unordered_map<string, Rooms>& Habitaciones)
{
	Rooms Kiosko;
	Kiosko.Name = "Kiosko";
	Kiosko.Description = "El centro de la plaza, hay salidas a la calle en las cuatro direcciones cardinales.";
	Kiosko.Analyze = "Es un kiosko grande y muy decorado. En la base hay unos botes de basura que estan rebosando de basura que huele bastante mal."; //Falta especificar los detalles de cada cuarto, aqui van a ir las cosas que se pueden hacer
	Kiosko.Objects = {"Revolver"};
	Kiosko.First_Visit = false;
	Habitaciones[Kiosko.Name] = Kiosko;
	

	Rooms Parque_Norte;
	Parque_Norte.Name = "Parque entrada norte";
	Parque_Norte.Description = "Estas al norte del parque, detras de ti esta la plaza y frente a ti una calle.";
	Parque_Norte.Analyze = "Es una camino corto rodeado de arbustos que va del kiosko a la calle. Hay algunas bancas a lo largo del camino y una parece tener varias cajas.";
	Parque_Norte.Objects = {"Telefono inteligente"};
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
	Entrada_Sur.Description = "Estas sobre una calle al sur del parque, frente a ti esta el parque y a ambos lados hay mas calle.";
	Entrada_Sur.Analyze = "Parece ser una calle en buenas condiciones con lamparas encendidas, no parece haber nada de interes aqui.";
	Entrada_Sur.Objects = { "Cuerpo de llave" };
	Entrada_Sur.First_Visit = true;
	Habitaciones[Entrada_Sur.Name] = Entrada_Sur;

	Rooms Entrada_Norte;
	Entrada_Norte.Name = "Calle lado norte";
	Entrada_Norte.Description = "Estas sobre una calle al sur del parque, detras de ti esta el parque y a ambos lados hay mas calle.";
	Entrada_Norte.Analyze = "Frente a ti hay un gran porton con un candado viejo. Detras de ti esta un cartel que lee 'Plaza Millenio'.";
	Entrada_Norte.Objects = {"Cabeza de llave"};
	Entrada_Norte.First_Visit = true;
	Habitaciones[Entrada_Norte.Name] = Entrada_Norte;

	Rooms Entrada_Oeste;
	Entrada_Oeste.Name = "Calle lado oeste";
	Entrada_Oeste.Description = "Estas sobre una calle al oeste del parque, a tu derecha se encuentra una de las entradas y tanto enfrente como atras de ti hay mas calle.";
	Entrada_Oeste.Analyze = "Es una calle en buenas condiciones con algunas lamparas apagadas. Parece haber un cofre chico pegado a la pared.";
	Entrada_Oeste.Objects = {"Dientes de llave"};
	Entrada_Oeste.First_Visit = true;
	Habitaciones[Entrada_Oeste.Name] = Parque_Oeste;

	Rooms Entrada_Este;
	Entrada_Este.Name = "Calle lado este";
	Entrada_Este.Description = "Estas sobre una calle al este del parque, a tu izquierda se encuentra una de la entradas y tanto enfrente como detras de ti hay mas calle.";
	Entrada_Este.Analyze = "La calle se ve algo maltratada, no se ve nada mas de interes.";
	Entrada_Este.Objects = {};
	Entrada_Este.First_Visit = true;
	Habitaciones[Entrada_Este.Name] = Entrada_Este;

	Rooms Esquina_Noreste;
	Esquina_Noreste.Name = "Calle interseccion norte con este";
	Esquina_Noreste.Description = "Estas en el cruce de calles del norte y este.";
	Esquina_Noreste.Analyze = "A lo largo de la calle hay unas barricadas, aparte de eso no hay mucho mas que ver.";
	Esquina_Noreste.Objects = {};
	Esquina_Noreste.First_Visit = true;
	Habitaciones[Esquina_Noreste.Name] = Esquina_Noreste;

	Rooms Esquina_Noroeste;
	Esquina_Noroeste.Name = "Calle interseccion norte con oeste";
	Esquina_Noroeste.Description = "Estas en el cruce de calles del norte y oeste";
	Esquina_Noroeste.Analyze = "Hay un monton de chasis de autos apilados en una esquina. A lo mejor hay algo ahi.";
	Esquina_Noroeste.Objects = { "Palanca" };
	Esquina_Noroeste.First_Visit = true;
	Habitaciones[Esquina_Noroeste.Name] = Esquina_Noroeste;

	Rooms Esquina_Sureste;
	Esquina_Sureste.Name = "Calle interseccion sur con este";
	Esquina_Sureste.Description = "Estas en el cruce de las calles del sur y este.";
	Esquina_Sureste.Analyze = "Es una calle en buenas condiciones con lamparas encendidas.";
	Esquina_Sureste.Objects = {};
	Esquina_Sureste.First_Visit = true;
	Habitaciones[Esquina_Sureste.Name] = Esquina_Sureste;

	Rooms Esquina_Suroeste;
	Esquina_Suroeste.Name = "Calle interseccion sur con oeste";
	Esquina_Suroeste.Description = "Estas en el cruce de las calles del sur y oeste";
	Esquina_Suroeste.Analyze = "La calle esta cubierta por muchas plantas y arboles, parece que no le han dado mucho mantenimiento.";
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
	(Habitaciones[Entrada_Norte.Name]).Norte = "No"; //Ver como ganar
	(Habitaciones[Entrada_Norte.Name]).Sur = Parque_Norte.Name;
	(Habitaciones[Entrada_Norte.Name]).Este = Esquina_Noreste.Name;
	(Habitaciones[Entrada_Norte.Name]).Oeste = Esquina_Noroeste.Name;

	//Desde Entrada_Sur
	(Habitaciones[Entrada_Sur.Name]).Norte = Parque_Sur.Name;
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
	(Habitaciones[Esquina_Noroeste.Name]).Norte = "No";
	(Habitaciones[Esquina_Noroeste.Name]).Sur = Entrada_Oeste.Name;
	(Habitaciones[Esquina_Noroeste.Name]).Este = Entrada_Norte.Name;
	(Habitaciones[Esquina_Noroeste.Name]).Oeste = "No";

	//Desde Esquina_Sureste
	(Habitaciones[Esquina_Sureste.Name]).Norte = Entrada_Este.Name;
	(Habitaciones[Esquina_Sureste.Name]).Sur = "No";
	(Habitaciones[Esquina_Sureste.Name]).Este = "No";
	(Habitaciones[Esquina_Sureste.Name]).Oeste = Entrada_Sur.Name;

	//Desde Esquina_Suroeste
	(Habitaciones[Esquina_Suroeste.Name]).Norte = Entrada_Oeste.Name;
	(Habitaciones[Esquina_Suroeste.Name]).Sur = "No";
	(Habitaciones[Esquina_Suroeste.Name]).Este = Entrada_Sur.Name;
	(Habitaciones[Esquina_Suroeste.Name]).Oeste = "No";
}

int main()
{
	/*
	Aqui se les va a dar los valores a los cuartos y se declara al jugador
	La primera vez que el jugar visite cada lugar, se le dara una descripcion adicional la cual se podra analizar despues
	*/

	unordered_map<string, Rooms> Habitacion;
	Player Jugador;
	Assign_Room_Properties(Habitacion);
	
	//Aqui se acaba la asignacion
	
	bool ganar = false;
	bool Empezar = true;
	string Input_Usuario;
	vector <string> Union;

	
	string Carga;
	while (true)
	{
		cout << "Quieres cargar una partida? ";
		cin >> Carga;
		if (Carga == "si")
		{
			Cargar_Partida(Habitacion);
			Cargar_Jugador(Jugador);
			Empezar = false;
			break;
		}
		else if (Carga == "no")
		{
			Empezar = true;
			break;
		}
		else
		{
			cout << "Escribe solo 'si' o 'no'" << '\n' << endl;
		}

	}
	cin.ignore();


	if (Empezar == true)
	{
		Inicio(Empezar, Jugador);
	}

	Objetivo();

	while (Input_Usuario != "salir" && Jugador.m_Ganar!=true)
	{ 
		Input(Input_Usuario, Union);
		In_Disparo(Jugador, Union);
		if (In_Disparo(Jugador, Union) == true && Union[0] == "disparar")
		{
			Jugador.m_Ganar = true;
			ganar = true;
			//break;
		}
		In_Llave(Jugador, Union);
		if (In_Llave(Jugador, Union) == true && Union[0] == "abrir")
		{
			Jugador.m_Ganar = true;
			ganar = true;
			//break;
		}
		Leer_Input(Union, Jugador, Habitacion, ganar);
		Input_Usuario = {};
	}

	if (Jugador.m_Ganar == true)
	{
		cout << "Gracias por jugar!" << endl;
	}
	
	cin.get();
	return 0;
}