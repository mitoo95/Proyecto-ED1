#include "MapaBack.h"
#include "Graph.h"

int main() {

	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);

	g.toString();
	_getch();

}