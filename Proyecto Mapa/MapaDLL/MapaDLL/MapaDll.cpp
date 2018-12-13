#include <stdio.h>
#include "C:\Users\mitoo\Documents\Proyecto Mapa\MapaBack\MapaBack\MapaBack.h"
#include "C:\Users\mitoo\Documents\Proyecto Mapa\MapaBack\MapaBack\MapaBack.cpp"

extern "C" {

	__declspec(dllexport) void DisplayHelloFromDLL(int id, char* nombre, double latx, double lony) {
		
		MapaBack gm;
		gm.CrearPuntostxt(id, nombre, latx, lony);
	
	}

}