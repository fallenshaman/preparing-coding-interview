#pragma once

#include <vector>
#include <list>

class Graph_AdjacencyList
{
public:
	Graph_AdjacencyList(int nodeCount) 
	{
		graph.resize(nodeCount);
		visited = new bool[nodeCount];
	}

	~Graph_AdjacencyList()
	{
		delete[] visited;
	}

	void Link(int nodeX, int nodeY);

	void DFS_iterative(int node);
	void DFS_recusive(int node);
	//void BFS();

	void BFS(int node);

	void print();



private:
	std::vector<std::vector<int>> graph;
	bool* visited;

	void impl_DFS_recusive(int node);

	void clearVisitFlags();
};
