#pragma once

class Graph_AdjacencyMatrix
{
public:
	Graph_AdjacencyMatrix(int count)
	{
		nodeCount = count;
		matrix = new int[nodeCount * nodeCount]{ 0, };
		visited = new bool[nodeCount];
	}

	~Graph_AdjacencyMatrix()
	{
		delete[] matrix;
		delete[] visited;
	}

	void Link(int nodeX, int nodeY);

	void DFS_iterative(int node);
	void DFS_recusive(int node);
	
	void BFS(int node);

	void print();

private:
	int nodeCount;
	int* matrix;
	bool* visited;

	void impl_DFS_recusive(int node);
	void clearVisitFlags();
};
