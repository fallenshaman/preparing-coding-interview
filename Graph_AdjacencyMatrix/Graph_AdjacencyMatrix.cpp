#include <iostream>>
#include <stack>
#include <queue>

#include "Graph_AdjacencyMatrix.h"

using namespace std;

void Graph_AdjacencyMatrix::Link(int nodeX, int nodeY)
{
	if (nodeX >= nodeCount || nodeY >= nodeCount)
	{
		cout << "Out of node index" << endl;
		return;
	}

	matrix[(nodeX * nodeCount) + nodeY] = 1;
	matrix[(nodeY * nodeCount) + nodeX] = 1;
}


void Graph_AdjacencyMatrix::DFS_iterative(int node)
{
	clearVisitFlags();

	stack<int> stack;
	stack.push(node);

	while (!stack.empty())
	{
		int currentNode = stack.top();
		stack.pop();

		if (visited[currentNode])
			continue;

		visited[currentNode] = true;
		cout << currentNode << " ";

		for (int i = nodeCount - 1; i >= 0; i--)
		{
			if (matrix[currentNode * nodeCount + i] == 1 && !visited[i])
			{
				stack.push(i);
			}
		}
	}

	cout << endl;
}


void Graph_AdjacencyMatrix::DFS_recusive(int node)
{
	clearVisitFlags();

	impl_DFS_recusive(node);

	cout << endl;
}


void Graph_AdjacencyMatrix::impl_DFS_recusive(int currentNode)
{
	visited[currentNode] = true;

	cout << currentNode << " ";

	for (int i = 0; i < nodeCount; ++i)
	{
		if (matrix[currentNode * nodeCount + i] == 1 && !visited[i])
		{
			impl_DFS_recusive(i);
		}
	}
}

void Graph_AdjacencyMatrix::BFS(int node)
{
	clearVisitFlags();

	queue<int> queue;
	queue.push(node);

	while (!queue.empty())
	{
		int currentNode = queue.front();
		queue.pop();

		if (visited[currentNode])
			continue;

		visited[currentNode] = true;
		cout << currentNode << " ";

		for (int i = 0; i < nodeCount; ++i)
		{
			if (matrix[currentNode * nodeCount + i] == 1 && !visited[i])
			{
				queue.push(i);
			}
		}
	}

	cout << endl;
}

void Graph_AdjacencyMatrix::clearVisitFlags()
{
	for (int i = 0; i < nodeCount; ++i)
	{
		visited[i] = false;
	}
}

void Graph_AdjacencyMatrix::print()
{
	for (int col = 0; col < nodeCount; ++col)
	{
		for (int row = 0; row < nodeCount; ++row)
		{
			cout << matrix[(col * nodeCount) + row] << " ";
		}
		cout << endl;
	}
}
