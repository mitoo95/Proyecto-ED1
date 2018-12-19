#include "MapaBack.h"
#include "MatrizAdy.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;


MapaBack::MapaBack(){

}

void MapaBack::CrearPuntostxt(int id, char *nombre, double latx, double lony){

	ofstream ArchivoPuntos("C:\\Users\\mitoo\\Documents\\Proyecto Mapa\\Puntos.txt", ios::app);

	if (!ArchivoPuntos){
		return;
	}

	ArchivoPuntos << id << "|" << nombre << "|" << latx << "|" << lony << "\n";
	ArchivoPuntos.close();

}

void MapaBack::CrearRutastxt(int idP1, int idP2){

	ofstream ArchivoRutas("C:\\Users\\mitoo\\Documents\\Proyecto Mapa\\Rutas.txt", ios::app);

	if (!ArchivoRutas) {
		return;
	}

	ArchivoRutas << idP1 << "|" << idP2 << "\n";
	ArchivoRutas.close();

}

void MapaBack::LeerPuntostxt(char* buff, int id) {

	ifstream ArchivoPuntos("C:\\Users\\mitoo\\Documents\\Proyecto Mapa\\Puntos.txt", ios::in);

	if (!ArchivoPuntos) {
		return;
	}

	string buffer;
	int i = 0;


	while (getline(ArchivoPuntos, buffer))
	{
		i++;
		if (i == id) {
			break;
		}
	}


	strcpy_s(buff, sizeof buffer, buffer.c_str());
	ArchivoPuntos.close();

}

void MapaBack::LeerRutastxt(char* buff, int id) {

	ifstream ArchivoRutas("C:\\Users\\mitoo\\Documents\\Proyecto Mapa\\Rutas.txt", ios::in);

	if (!ArchivoRutas) {
		return;
	}

	string buffer;
	int i = 0;


	while (getline(ArchivoRutas, buffer))
	{
		i++;
		if (i == id) {
			break;
		}
	}


	strcpy_s(buff, sizeof buffer, buffer.c_str());
	ArchivoRutas.close();

}

int MapaBack::BuscarPunto(int buscando) {

	ifstream ArchivoPuntos("C:\\Users\\mitoo\\Documents\\Proyecto Mapa\\Puntos.txt", ios::in);

	if (!ArchivoPuntos)
	{
		return -1;
	}

	ArchivoPuntos.seekg(0, ios::beg);

	while (ArchivoPuntos >> id)
	{
		if (buscando == id)
		{
			ArchivoPuntos.close();
			return id;
		}
	}

	ArchivoPuntos.close();
	return -1;
}