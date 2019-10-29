#include <iostream>
#include<vector> 
using namespace std;

struct Edge
{
	int source;
	int destination;
};

class Graph
{
public:
	vector<vector<int> > adjacency_matrix;
public:
	Graph(vector<vector<int> > adj)
	{
		adjacency_matrix = adj;
	}
	
	void printAdjacency()
	{
		for (int i = 0; i < adjacency_matrix.size(); ++i)
		{
			for (int j = 0; j < adjacency_matrix[i].size(); j++)
				{
					cout << (adjacency_matrix[i])[j];
				}
			cout << endl;
		}

	}
	
};

void MST(vector<vector<int> > adj, int vertices, int disjoint[])
{
	
}

void union_fun(int x, int y, int disjoint[])
{
	disjoint[x] = disjoint[y];
}


int main(){

	int vertices;
	cin >> vertices;
	vector<vector<int> > adj;
	int disjoint[vertices];
	adj.resize(vertices);

	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++)
		{
			int dummy;
			cin >> dummy;
			adj[i].push_back(dummy);
		}
	}

	Graph G1(adj);
	G1.printAdjacency();

	for (int i = 0; i < vertices; i++)
		disjoint[i] = i;

	MST(G1.adjacency_matrix, vertices, disjoint);




	
}