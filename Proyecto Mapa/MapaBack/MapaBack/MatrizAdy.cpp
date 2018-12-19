#include "MatrizAdy.h"

MatrizAdy::MatrizAdy(int n) {

	this->n = n;
	visited = new bool[n];
	adj = new int*[n];

	for (int i = 0; i < n; i++) {

		adj[i] = new int[n];
		for (int j = 0; j < n; j++) {
			adj[i][j] = 0;
		}

	}

}

void MatrizAdy::add_edge(int origen, int destino) {

	if (origen > n || destino > n || origen < 0 || destino < 0) {
		cout << "Invalid edge!\n";
	}

	else {
		adj[origen - 1][destino - 1] = 1;
	}

}

void MatrizAdy::display() {

	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; i++) {
			cout << adj[i][j] << "	";
		}
		cout << endl;
	}

}