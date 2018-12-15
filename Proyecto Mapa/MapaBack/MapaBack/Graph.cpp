#include "Graph.h"

Graph::Graph(int numVertices){
	
	this->numVertices = numVertices;
	adjMatrix = new bool*[numVertices];
	for (int i = 0; i < numVertices; i++) {
		adjMatrix[i] = new bool[numVertices];
		for (int j = 0; j < numVertices; j++)
			adjMatrix[i][j] = false;

	}

}

void Graph::addEdge(int i, int j){

	adjMatrix[i][j] = true;
	adjMatrix[j][i] = true;

}

void Graph::removeEdge(int i, int j){

	adjMatrix[i][j] = false;
	adjMatrix[j][i] = false;

}

bool Graph::isEdge(int i, int j){

	return adjMatrix[i][j];

}

void Graph::toString(){

	for (int i = 0; i < numVertices; i++) {
		cout << i << " : ";
		for (int j = 0; j < numVertices; j++)
			cout << adjMatrix[i][j] << " ";
		cout << "\n";
	}

}

Graph::~Graph(){

	for (int i = 0; i < numVertices; i++)
		delete[] adjMatrix[i];
	delete[] adjMatrix;

}