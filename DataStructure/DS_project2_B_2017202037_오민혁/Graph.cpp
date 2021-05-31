#include "Graph.h"
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>
// constructor
Graph::Graph(ofstream * flog)
{
	this->flog = flog;
	this->mList =  NULL, this->vertex=NULL;
	this->size = 0;
	this->mstMatrix = NULL;
	this->MST.clear();
}

Graph::~Graph()
{
}

bool Graph::Build(AVLTree * root)
{
	size = GetNodeCount(root->Getroot());
	stack <AVLNode*> s;
	AVLNode * temp = root->Getroot();
	mList = new map<int, int>[size];
	vertex = new CityData*[size];
	int index = 0;
	if (root == NULL) {
		return NULL;
	}
	
	while (1) {
		while (temp) {
			s.push(temp);
			temp = temp->GetLeft();
		}
		if (s.empty()) break;
		temp = s.top();

		s.pop();
		vertex[index] = temp->GetCityData();
		index++;

		temp = temp->GetRight();
	}
	// vertex[node index] <- node data
	for (int i = 0; i < size; i++) { // make mList = graph
		for (int j = 0; j < size; j++) {
			if (i == j)
				continue;
			mList[i].insert(make_pair(j, abs(vertex[j]->GetLocationId() - vertex[i]->GetLocationId()))); // input data at graph(mList)
		}
	}
	
	return false;
}

void Graph::Print_GP()
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	size = mList[0].size();
	// print all data of graph
	for (int i = 0; i < size+1; i++) {
		for (int j = 0; j < size+1; j++) {	
			fout << mList[i][j] << " \t";
		}
		fout << endl;
	}
	return;
}

void Graph::Print_MST()
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	size = mList[0].size();
	int n = 0;
	for (int i = 0; i < size - 1; i++) { // find start node
		if (Print[i] == 1) {
			n = i;
			break;
		}
	}
	
	int m = FindFromNode(n); // find partner of n
	int total = 0; // total weight
	for (int i = 0; i < size - 1; i++) {
		fout <<"( "<< vertex[n]->Getname() << ", "<<vertex[m]->Getname() << " ), " << abs(vertex[n]->GetLocationId()-vertex[m]->GetLocationId()) <<endl;
		total += abs(vertex[n]->GetLocationId() - vertex[m]->GetLocationId());
		n = m; // n = from node
		m = FindFromNode(n); // m = to node
	}
	fout << "Total: " << (total) << endl;
	
}

bool Graph::Kruskal()
{

	size = mList[0].size(); // MST size
	Print = new int[size - 1];
	for (int i = 0; i < size - 1; i++) // the number of weight
		Print[i] = 0;

	map <int, Edge> v; // mst data
	mstMatrix = new int[size];
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (i == j||(i==0&&j==0)) continue; // diagonal exception
			v.insert(make_pair(mList[i].find(j)->second,Edge(i, j, mList[i].find(j)->second))); // store weight with inorder
		}
	}
	map <int, Edge>::iterator vit; // iterator for loop
	make_set(); // mstMatrix initializing
	for (vit = v.begin(); vit != v.end();vit++) { // make MST
		if (!find(vit->second.node[0],vit->second.node[1])) {
			MST.push_back(Edge(vit->second.node[0], vit->second.node[1], vit->second.weight));
			
			union_set(vit->second.node[0], vit->second.node[1]);
		}	
	}
	for (int i = 0; i < MST.size(); i++) { // store the number of link
		Print[MST[i].node[0]]++;
		Print[MST[i].node[1]]++;
	}
	return false;
}

void Graph::make_set() // initializing
{
	size = mList[0].size();
	mstMatrix = new int[size];
	for (int i = 0; i < size; i++) {
		mstMatrix[i] = i;
	}
}

void Graph::union_set(int x, int y) // node union
{
	x = GetParent(x);
	y = GetParent(y);
	if (x < y) mstMatrix[y] = x;
	else mstMatrix[x] = y;
}

int Graph::find(int x, int y) // find parent
{
	x = GetParent(x);
	y = GetParent(y);
	if (x == y) return 1;
	else return 0;
}

