#include "MapaBack.h"
#include "MatrizAdy.h"


int main() {

	int nodes, max_edges, origin, destin;

	cout << "Enter number of nodes: ";

	cin >> nodes;

	MatrizAdy am;

	am.CreateMatriz(nodes);

	max_edges = nodes * (nodes - 1);

	for (int i = 0; i < max_edges; i++)

	{

		cout << "Enter edge (-1 -1 to exit): ";

		cin >> origin >> destin;

		if ((origin == -1) && (destin == -1))

			break;

		am.add_edge(origin, destin);

	}

	am.display();
	_getch();

	return 0;

}