#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 20

class MatrizAdy {

	private:
		int n;
		int **adj;
		bool *visited;

public:
	
	MatrizAdy(int n);
	void add_edge(int origen, int destino);
	void display();

};