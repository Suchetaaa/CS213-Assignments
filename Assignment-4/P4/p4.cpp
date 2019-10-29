#include <iostream>
#include <vector> 
using namespace std;

struct Edge
{
	int source;
	int destination;
};

class Graph
{
public:
	vector<vector<int> > adjacency_list;
public:
	Graph(vector<Edge> &edges, int vertices)
	{
		adjacency_list.resize(vertices);

		for (int i = 0; i < edges.size(); i++)
		{
			adjacency_list[edges[i].source].push_back(edges[i].destination);
		}
	}

	void printAdjacency()
	{
		for (int i = 0; i < adjacency_list.size(); ++i)
		{
			for (int j = 0; j < adjacency_list[i].size(); j++)
				{
					cout << (adjacency_list[i])[j];
				}
			cout << endl;
		}

	}
	
};

bool loopfind(int query, int vertex, vector<vector<int> > adjacency_list, vector<int> &visited_array, bool root)
{

	//cout << vertex << endl;
	if (vertex == query and root == 0) 
		return true;

	int j = 0;
	for (j = 0; j < visited_array.size(); j++)
	{
		if (visited_array[j] == 0)
			break;
	}
	if (j == visited_array.size())
		return false;

	bool b = 0;

	for (int i = 0; i < adjacency_list[vertex].size(); i++)
	{
		int new_vertex = adjacency_list[vertex][i];
		if (visited_array[new_vertex] == 0)
		{
			//cout << i << endl;
			visited_array[new_vertex] = 1;
			b = loopfind(query, new_vertex, adjacency_list, visited_array, 0);
			if (b)
				return true;
		}
	}

	return false;
}


int main(){

	int vertices;
	int num_edges;
	cin >> vertices >> num_edges;

	vector<Edge> edges;

	for (int i = 0; i < num_edges; i++)
	{
		Edge dummy;
		cin >> dummy.source;
		cin >> dummy.destination;
		edges.push_back(dummy);
	}

	Graph G1(edges, vertices);
	//G1.printAdjacency();
	vector<int> visited_array;

	for (int i = 0; i < vertices; i++) 
		visited_array.push_back(0);

	int query; 
	cin >> query;

	bool a;
	a = loopfind(query, query, G1.adjacency_list, visited_array, 1);
	if (a)
		cout << "1";
	else
		cout << "0";


	
}