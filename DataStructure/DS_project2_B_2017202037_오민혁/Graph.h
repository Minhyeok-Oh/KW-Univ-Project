#include "AVLTree.h"
#include <iostream>
#include <fstream>// header file declare
#include <map>
#include <vector>
using namespace std;
class Edge { // Edge class
public:
	int node[2]; // node[0] = from node , node[1] = to node
	int weight;
	Edge(int x, int y, int weight) {
		this->node[0] = x;
		this->node[1] = y;
		this->weight = weight;
	}
	bool operator < (Edge &edge) {
		return this->weight < edge.weight; // for sorting
	}
};

class Graph
{
public:
	map<int, int> * mList;	// mList[from vertex] = map<to vertex, weight>
	CityData * * vertex;			// vertex[index] = CityData * 
	int size;					// AVLTree size
	int * mstMatrix;			// MST
	ofstream * flog;
	vector <Edge> MST;
	int * Print;
public:
	Graph(ofstream * flog);
	~Graph();

	bool	Build(AVLTree * root);
	void 	Print_GP();
	void	Print_MST();

	/*for Kruskal union_set*/
	bool	Kruskal();
	void 	make_set();
	void 	union_set(int x, int y);
	int		find(int x, int y);
	int		GetParent(int x) {
		if (mstMatrix[x] == x) return x;
		return mstMatrix[x] = GetParent(mstMatrix[x]); // find parent of x
	}
	int GetNodeCount(AVLNode * root) { // size of avl tree
		if (root == NULL)
			return 0;
		else
			return GetNodeCount(root->GetLeft()) + GetNodeCount(root->GetRight()) + 1;
	}
	int FindFromNode(int num) { // for finding partner node
		int a;
		for (int i = 0; i < MST.size(); i++) {
			if (MST[i].node[0] == num) {
				a = MST[i].node[1];
				MST.erase(MST.begin() + i);
				return a;
			}
			else if (MST[i].node[1] == num) {
				a = MST[i].node[0];
				MST.erase(MST.begin() + i);
				return a;
			}
			else
				continue;
		}
	}
};




