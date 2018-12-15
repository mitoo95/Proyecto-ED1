#pragma once
#include <iostream>
using namespace std;

class Graph {
public:
	Graph(int numVertices);
	void addEdge(int i, int j);
	void removeEdge(int i, int j);
	bool isEdge(int i, int j);
	void toString();
	~Graph();

private:
	bool** adjMatrix;
	int numVertices;
};