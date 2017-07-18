#include <iostream>

#include <stack>
#include <queue>

#include "Graph_AdjacencyList.h"


using namespace std;

void Graph_AdjacencyList::Link(int nodeX, int nodeY)
{
	if (nodeX >= graph.size() || nodeY >= graph.size())
	{
		cout << "Out of node index" << endl;
		return;
	}

	graph[nodeX].push_back(nodeY);
	graph[nodeY].push_back(nodeX);
}

void Graph_AdjacencyList::DFS_iterative(int node)
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

		vector<int> adjacencyList = graph[currentNode];

		for (int i = adjacencyList.size() -1 ; i >= 0 ; i--)
		{
			if (!visited[adjacencyList[i]])
			{
				stack.push(adjacencyList[i]);
			}
		}
	}

	cout << endl;	
}

void Graph_AdjacencyList::DFS_recusive(int node)
{
	clearVisitFlags();

	impl_DFS_recusive(node);

	cout << endl;
}


void Graph_AdjacencyList::impl_DFS_recusive(int currentNode)
{
	visited[currentNode] = true;

	cout << currentNode << " ";

	for (int i = 0; i < graph[currentNode].size(); ++i)
	{
		if (!visited[graph[currentNode][i]])
		{
			impl_DFS_recusive(graph[currentNode][i]);
		}
	}
}

void Graph_AdjacencyList::BFS(int node)
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

		vector<int> adjacencyList = graph[currentNode];

		for (int i = 0; i < adjacencyList.size(); ++i)
		{
			if (!visited[adjacencyList[i]])
			{
				queue.push(adjacencyList[i]);
			}
		}
	}

	cout << endl;
}

void Graph_AdjacencyList::print()
{
	for (int i =0; i < graph.size(); ++i)
	{
		cout << "Node [" << i << "] : ";

		for (vector<int>::iterator iter = graph[i].begin(); iter != graph[i].end(); ++iter)
		{
			cout << *iter << " ";
		}
		cout << endl;
	}
}

void Graph_AdjacencyList::clearVisitFlags()
{
	for (int i = 0; i < graph.size(); ++i)
		visited[i] = false;
}
