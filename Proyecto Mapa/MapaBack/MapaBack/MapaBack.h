#pragma once
#include <iostream>
#include <stdlib.h>
#include <conio.h>

class MapaBack {

public:
	
	MapaBack();

	void CrearPuntostxt(int id, char* nombre, double latx, double lony);
	void HolaWorld();
	void CrearRutastxt(int id, int idP1, int idP2);
	void LeerPuntostxt(char* buff, int psc);
	void LeerRutastxt(char* buff, int id);
	void EliminarPuntotxt(int id);
	void EliminarRutatxt(int id);
	void BuscarPunto(int id); // aux de crearruta




private:
	int id;
	char* nombre;
	double x;
	double y;

};