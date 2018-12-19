#include <stdio.h>
#include "C:\Users\mitoo\Documents\Proyecto Mapa\MapaBack\MapaBack\MapaBack.h"
#include "C:\Users\mitoo\Documents\Proyecto Mapa\MapaBack\MapaBack\MapaBack.cpp"
#include "C:\Users\mitoo\Documents\Proyecto Mapa\MapaBack\MapaBack\Graph.h"
#include "C:\Users\mitoo\Documents\Proyecto Mapa\MapaBack\MapaBack\Graph.cpp"

MapaBack gm;

extern "C" {

	__declspec(dllexport) void CrearPuntosDLL(int id, char* nombre, double latx, double lony) {
		
		gm.CrearPuntostxt(id, nombre, latx, lony);
	
	}

	__declspec(dllexport) void CrearRutasDLL(int idP1, int idP2) {

		gm.CrearRutastxt(idP1, idP2);

	}

	__declspec(dllexport) void LeerPuntosDLL(char* buff, int id) {

		gm.LeerPuntostxt(buff, id);

	}
	
	__declspec(dllexport) void LeerRutasDLL(char* buff, int id) {

		gm.LeerRutastxt(buff, id);

	}

	__declspec(dllexport) bool BuscarPuntoDLL() {

		

	}
	
}