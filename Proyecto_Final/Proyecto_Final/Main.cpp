#include <fstream>
//#include <vector>
#include <unordered_map>
//#include <string>
//#include <iostream>
#include "Player.h"

/*
	Hacer struct cuartos, o clase
*/


struct Rooms
{
	string Name;
	string Description { "" };
	string Analyze{ "" };
	vector <string> Objects;
	bool First_Visit;
};

//enum Room_List
//{
//	Kiosko = 1,
//	Parque_Norte,
//	Parque_Sur,
//	Parque_Este,
//	Parque_Oeste,
//	Entrada_Sur,
//	Entrada_Norte,
//	Entrada_Este,
//	Entrada_Oeste,
//	Esquina_Noreste,
//	Esquina_Noroeste,
//	Esquina_Sureste,
//	Esquina_Suroeste
//};

//Hacer el mapa :)

void Assign_Room_Properties(unordered_map<string, Rooms>& Habitaciones)
{
	Rooms Kiosko;
	Kiosko.Name = "Kiosko";
	Kiosko.Description = "El centro de la plaza, hay salidas a la calle en las cuatro direcciones cardinales.";
	Kiosko.Analyze = "Es un kiosko grande y muy decorado. En la base hay unos botes de basura que estan rebosando de basura que huele bastante mal."; //Falta especificar los detalles de cada cuarto, aqui van a ir las cosas que se pueden hacer
	Kiosko.Objects = {"Revolver"}; //Falta ver que se le va a agregar
	Kiosko.First_Visit = true;
	//Cuartos->push_back(Kiosko);
	Habitaciones[Kiosko.Name] = Kiosko;
	

	Rooms Parque_Norte;
	Parque_Norte.Name = "Parque entrada norte";
	Parque_Norte.Description = "Estas al norte del parque, detras de ti esta la plaza y frente a ti una calle.";
	Parque_Norte.Analyze = "Es una camino corto rodeado de arbustos que va del kiosko a la calle. Hay algunas bancas a lo largo del camino y una parece tener varias cajas.";
	Parque_Norte.Objects = {"Telefono inteligente","Cuerpo de llave"};
	Parque_Norte.First_Visit = true;

	Rooms Parque_Sur;
	Parque_Sur.Name = "Parque entrada sur";
	Parque_Sur.Description = "Estas al sur del parque, frente a ti esta una calle y detras esta el kiosko.";
	Parque_Sur.Analyze = "El camino hacia la calle esta algo destruido, con hoyos e incluso un auto volteado cerca de la calle. El auto parece tener la cajuela abierta.";
	Parque_Sur.Objects = {"Palanca"};
	Parque_Sur.First_Visit = true;

	Rooms Parque_Este;
	Parque_Este.Name = "Parque entrada este";
	Parque_Este.Description = "Estas al este del parque, a tu izquierda hay una calle y a tu derecha esta el kiosko.";
	Parque_Este.Analyze = "El kiosko se ve quemado desde ese lado, sobre todo en la parte del techo. Hay un arbusto en llamas cerca del kiosko que emite un olor muy fuerte.";
	Parque_Este.Objects = {};
	Parque_Este.First_Visit = true;

	Rooms Parque_Oeste;
	Parque_Oeste.Name = "Parque entrada oeste";
	Parque_Oeste.Description = "Estas al oeste del parque, a tu izquierda esta el kiosko y a tu derecha hay una calle.";
	Parque_Oeste.Analyze = "Parece ser uno de los lados mejor cuidados del parque, aun hay muchos arbustos y pasto. No parece haber mucho de interes que ver.";
	Parque_Oeste.Objects = {"Una bala"};
	Parque_Oeste.First_Visit = true;

	Rooms Entrada_Sur;
	Entrada_Sur.Name = "";
	Entrada_Sur.Description = "";
	Entrada_Sur.Objects = {};
	Entrada_Sur.First_Visit = true;

	Rooms Entrada_Norte;
	Entrada_Norte.Name = "";
	Entrada_Norte.Description = "";
	Entrada_Norte.Analyze = "Frente a ti hay un gran porton con un candado viejo. Detras de ti esta la entrada al parque y un cartel que lee 'Plaza Millenio'.";
	Entrada_Norte.Objects = {};
	Entrada_Norte.First_Visit = true;

	Rooms Entrada_Oeste;
	Entrada_Oeste.Name = "";
	Entrada_Oeste.Description = "";
	Entrada_Oeste.Objects = {};
	Entrada_Oeste.First_Visit = true;

	Rooms Entrada_Este;
	Entrada_Este.Name = "";
	Entrada_Este.Description = "";
	Entrada_Este.Objects = {};
	Entrada_Este.First_Visit = true;

	Rooms Esquina_Noreste;
	Esquina_Noreste.Name = "";
	Esquina_Noreste.Description = "";
	Esquina_Noreste.Objects = {};
	Esquina_Noreste.First_Visit = true;

	Rooms Esquina_Noroeste;
	Esquina_Noroeste.Name = "";
	Esquina_Noroeste.Description = "";
	Esquina_Noroeste.Objects = {};
	Esquina_Noroeste.First_Visit = true;

	Rooms Esquina_Sureste;
	Esquina_Sureste.Name = "";
	Esquina_Sureste.Description = "";
	Esquina_Sureste.Objects = {};
	Esquina_Sureste.First_Visit = true;

	Rooms Esquina_Suroeste;
	Esquina_Suroeste.Name = "";
	Esquina_Suroeste.Description = "";
	Esquina_Suroeste.Objects = {};
	Esquina_Suroeste.First_Visit = true;
}

int main()
{
	/*
	Aqui se les va a dar los valores a los cuartos
	La primera vez que el jugar visite cada lugar, se le dara una descripcion adicional la cual se podra analizar despues

	ToDo:
		Crear descripciones para cada cuarto
		Ver que objetos va a tener cada cuarto
		Ver que interacciones va a tener cada cuarto
	*/

	//Aqui se acaba la asignacion de los cuartos
	unordered_map<string, Rooms> Habitacion;
	Habitacion["Kiosko"] = Rooms();
	
	vector<Rooms> Cuartos;
	string Current_Room = "Kiosko";
	vector <string> Pockets = { "vaso", "llaves", "carro"};
	Player Jugador (Pockets, Current_Room);
	
	Assign_Room_Properties(Habitacion);
	
	Jugador.Show_Location();
	Jugador.Show_Inventory();
	cout << endl;
	
	cout << Habitacion["Kiosko"].Objects[0] << endl;
	
	cin.get();
	return 0;
}