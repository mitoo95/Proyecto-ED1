#include <stdio.h>
#include "C:\Users\mitoo\Documents\Proyecto Mapa\MapaBack\MapaBack\MapaBack.h"
#include "C:\Users\mitoo\Documents\Proyecto Mapa\MapaBack\MapaBack\MapaBack.cpp"

MapaBack gm;

extern "C" {

	__declspec(dllexport) void __stdcall CrearPuntosDLL(char* id, char* nombre, double latx, double lony) {
		
		gm.CrearPuntostxt(id, nombre, latx, lony);
	
	}

	__declspec(dllexport) void __stdcall CrearRutasDLL(char* origen, char* destino) {

		gm.CrearRutastxt(origen, destino);

	}

	__declspec(dllexport) void __stdcall LeerPuntosDLL(char* buff, int id) {

		gm.LeerPuntostxt(buff, id);

	}
	
	__declspec(dllexport) void __stdcall LeerRutasDLL(char* buff, int id) {

		gm.LeerRutastxt(buff, id);

	}

	__declspec(dllexport) bool __stdcall BuscarPuntoDLL(int buscando) {

		return gm.BuscarPunto(buscando);

	}
}