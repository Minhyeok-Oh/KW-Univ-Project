#include "Graph.h"
#include "Stack.h"
#include "MinHeap.h"
#include <set>

#define DFS_FIRST_PATH

Graph::Graph()
{
	m_pVHead = NULL;
	m_vSize = 0;
    // TODO: implement
}
Graph::~Graph()
{
	m_pVHead = NULL;
	m_vSize = 0;
    // TODO: implement
}
void Graph::AddVertex(int vertexKey) {
	Vertex * newVertex = new Vertex(vertexKey);
	if (m_pVHead == NULL)
		m_pVHead = newVertex;
	else
	{
		Vertex * lastVertex = m_pVHead;
		while (lastVertex->GetNext() != NULL)
			lastVertex = lastVertex->GetNext();
		lastVertex->SetNext(newVertex);
	}
	m_vSize++;
}

void Graph::AddEdge(int startVertexKey, int endVertexKey, int weight)
{
	Vertex * startVertex = FindVertex(startVertexKey);
	if (weight == 0)
		return;
	startVertex->AddEdge(endVertexKey, weight);
}

Vertex* Graph::FindVertex(int key) {
	Vertex * Ver = m_pVHead;
	while (Ver->GetKey() != key && Ver != NULL)
	{
		Ver = Ver->GetNext();
	}
	return Ver;
}

int Graph::Size() const {
	return m_vSize;
}

void Graph::Clear() {
	Vertex * parent = m_pVHead;
	Vertex * child;
	while (parent != NULL)
	{
		child = parent;
		parent = parent->GetNext();
		child->Clear();
		delete child;
	}
}

void Graph::Print(std::ofstream& fout)
{
	fout << "====== PRINT ======" << endl;
	for (int i = 0; i < this->Size(); i++) {
		Edge * iterator = this->FindVertex(i)->GetHeadOfEdge();
		for (int j = 0; j < this->Size(); j++) {
			if (iterator == NULL)
				fout << "0" << " ";
			if (iterator != NULL) {
				if (iterator->GetKey() != j)
					fout << "0" << " ";
				if (iterator->GetKey() == j)
				{
					fout << iterator->GetWeight() << " ";
					iterator = iterator->GetNext();
				}
			}
		}
		fout << endl;
	}
	fout << "=================" << endl;
	fout.close();
}

bool Graph::IsNegativeEdge()
{
	Vertex * Check = m_pVHead;
	for (int i = 0; i < m_vSize; i++)
	{
		Edge * Negative = Check->GetHeadOfEdge();
		while (Negative != NULL)
		{
			if (Negative->GetWeight() < 0)
				return true;
			Negative = Negative->GetNext();
		}
		Check = Check->GetNext();
	}
	return false;
}


std::vector<int> Graph::FindShortestPathDijkstraUsingSet(int startVertexKey, int endVertexKey)
{
	std::vector<int>a; // path and distance vector
	bool* visited = new bool[Size()]; // visited array
	for (int i = 0; i < Size(); i++)
		visited[i] = false;
	int* path = new int[Size()]; // path array
	for (int i = 0; i < Size(); i++)
		path[i] = -1;
	int* distance = new int[Size()]; // distance array
	for (int i = 0; i < Size(); i++)
		distance[i] = 9999; // initialize large number.
	Vertex* start = FindVertex(startVertexKey); // start vertex
	Edge* startedge = start->GetHeadOfEdge(); // head edge
	distance[start->GetKey()] = 0; // start vertex's distance set to 0
	std::set<std::pair<Vertex*, int> > s; // set to save information
	std::pair<Vertex*, int> temp; // pair saver
	temp.first = start;
	temp.second = distance[start->GetKey()];
	s.insert(temp); // push pair information to set
	visited[start->GetKey()] = true; // visit start vertex
	while (!s.empty()) // do until set is empty
	{
		if (start->GetKey() == endVertexKey) // if endvertex path founded
			break; // break the loop
		start = s.begin()->first; // start set to set root
		int cost = s.begin()->second;
		startedge = start->GetHeadOfEdge(); // startedge set to head of start edge linked list
		s.erase(s.begin()); // pop set root
		while (startedge) // check all edge of start vertex
		{
			if (distance[startedge->GetKey()] > (cost + startedge->GetWeight())) // if new distance is shorter than previous distance
			{
				distance[startedge->GetKey()] = (cost + startedge->GetWeight()); // distance modify to new distance
				path[startedge->GetKey()] = start->GetKey(); // path changed
			}
			startedge = startedge->GetNext(); // go to next edge
		}
		Vertex* min = FindVertex(endVertexKey); // nearest vertex
		for (int i = 0; i < Size(); i++)
		{
			if (distance[i] < distance[min->GetKey()] && visited[i] == false)
				min = FindVertex(i); // find the nearest vertex that unvisited
		}
		temp.first = min;
		temp.second = distance[min->GetKey()];
		s.insert(temp); // insert nearest vertex and distance
		visited[min->GetKey()] = true; // change visit status
	}
	int key = endVertexKey; // finding path
	std::vector<int> stack; // temporary stack to save reversed path
	while (key != startVertexKey) // do until find start vertex
	{
		stack.push_back(key); // push vertex that have key
		key = path[key]; // go to previous path
	}
	a.push_back(FindVertex(startVertexKey)->GetKey()); // push startvertex to a
	while (!stack.empty()) // reversing stack
	{
		key = stack.back();
		stack.pop_back();
		a.push_back(key); // push all element in stack to a upside down
	}
	a.push_back(distance[endVertexKey]); // push final distance to a
	return a;
}
std::vector<int> Graph::FindShortestPathDijkstraUsingMinHeap(int startVertexKey, int endVertexKey)
{
	std::vector<int> a; // result path and distance
	MinHeap<int, int> MH; // MinHeap
	bool* visited = new bool[Size()]; // visited array
	for (int i = 0; i < Size(); i++)
		visited[i] = false;
	int* path = new int[Size()]; // path array
	for (int i = 0; i < Size(); i++)
		path[i] = -1;
	int* distance = new int[Size()]; // distance array
	for (int i = 0; i < Size(); i++)
		distance[i] = 9999; // initialize large number.
	MH.Push(FindVertex(startVertexKey)->GetKey(), 0); // push start vertexkey and distance 0
	distance[FindVertex(startVertexKey)->GetKey()] = 0; // distance startpoint is 0
	visited[FindVertex(startVertexKey)->GetKey()] = 1; // visit startpoint
	Vertex* finder = FindVertex(startVertexKey)->GetNext(); // finder is next node of startvertex
	while (!MH.IsEmpty()) // do until min heap is empty
	{
		if (finder->GetKey() == endVertexKey) // if endVertex found, loop break
			break;
		finder = FindVertex(MH.Top().first); // finder is root of min heap
		visited[finder->GetKey()] = true; // visit finder
		Edge* Efinder = finder->GetHeadOfEdge(); // Efinder starts at head of edge linked list
		MH.Pop(); // pop min heap root and re-arrangement
		while (Efinder) // loop all edges
		{
			if (distance[Efinder->GetKey()] > (distance[finder->GetKey()] + Efinder->GetWeight()) && visited[Efinder->GetKey()] == false) // if new distance is shorter than previous distance and not visited
			{
				distance[Efinder->GetKey()] = (distance[finder->GetKey()] + Efinder->GetWeight()); // distance is changed
				path[Efinder->GetKey()] = finder->GetKey(); // path modify
				MH.Push(Efinder->GetKey(), distance[Efinder->GetKey()]); // push new vertexkey and distance
			}
			Efinder = Efinder->GetNext(); // go to next edge
		}
	}
	int key = endVertexKey; // finding path
	std::vector<int> stack; // temporary stack to save reversed path
	while (key != startVertexKey) // do until find start vertex
	{
		stack.push_back(key); // push vertex that have key
		key = path[key]; // go to previous path
	}
	a.push_back(FindVertex(startVertexKey)->GetKey()); // push startvertex to a
	while (!stack.empty()) // reversing stack
	{
		key = stack.back();
		stack.pop_back();
		a.push_back(key); // push all element in stack to a upside down
	}
	a.push_back(distance[endVertexKey]); // push final distance to a
	return a;
}
std::vector<int> Graph::FindShortestPathBellmanFord(int startVertexKey, int endVertexKey)
{
	std::vector<int> a; // result path and distance
	int* path = new int[Size()]; // path array
	for (int i = 0; i < Size(); i++)
		path[i] = -1;
	int* distance = new int[Size()]; // distance array
	for (int i = 0; i < Size(); i++)
		distance[i] = 9999; // initialize large number
	distance[FindVertex(startVertexKey)->GetKey()] = 0; // distance of startpoint set 0
	Vertex* finder = FindVertex(startVertexKey); // finder starts at start vertex
	for (int i = 0; i < m_vSize; i++) // loop vertex count
	{
		for (int j = 0; j < m_vSize; j++) // check all vertices
		{
			if (finder == NULL)
				finder = m_pVHead;
			if (finder->GetKey() == endVertexKey) // if finder found end vertex
				break; // break the loop
			Edge* Efinder = finder->GetHeadOfEdge(); // Efinder starts at edge linked list head
			while (Efinder) // check all edges
			{
				if (distance[Efinder->GetKey()] > (distance[finder->GetKey()] + Efinder->GetWeight())) // if new distance is shorter than previous distance
				{
					distance[Efinder->GetKey()] = (distance[finder->GetKey()] + Efinder->GetWeight()); // distance changed
					path[Efinder->GetKey()] = finder->GetKey(); // path modify
				}
				Efinder = Efinder->GetNext(); // go to next edge
			}
			finder = finder->GetNext(); // go to next vertex
		}
	}

	//negative cycle check
	finder = FindVertex(startVertexKey); // finder set to start vertex
	for (int j = 0; j < m_vSize; j++) // check all vertices
	{
		if (finder == NULL)
			finder = m_pVHead;
		if (finder->GetKey() == endVertexKey) // if finder found end vertex
			break; // break the loop
		Edge* Efinder = finder->GetHeadOfEdge(); // Efinder starts at edge linked list head
		while (Efinder) // check all edges
		{
			if (distance[Efinder->GetKey()] > (distance[finder->GetKey()] + Efinder->GetWeight())) // if there is shorter route after previous operation
			{ // negative cycle found
				a.push_back(-1); // a's head is -1
				return a; // return a, means negative cycle
			}
			Efinder = Efinder->GetNext(); // go to next edge
		}
		finder = finder->GetNext(); // go to next vertex
	}
	int key = endVertexKey; // finding path
	std::vector<int> stack; // temporary stack to save reversed path
	while (key != startVertexKey) // do until find start vertex
	{
		stack.push_back(key); // push vertex that have key
		key = path[key]; // go to previous path
	}
	a.push_back(FindVertex(startVertexKey)->GetKey()); // push startvertex to a
	while (!stack.empty()) // reversing stack
	{
		key = stack.back();
		stack.pop_back();
		a.push_back(key); // push all element in stack to a upside down
	}
	a.push_back(distance[endVertexKey]); // push final distance to a
	return a;
}
std::vector<int> Graph::FindShortestPathUsingFloyd(int startVertexKey, int endVertexKey)
{
	std::vector<int>a; // path and distance vector
	bool* visited = new bool[Size()]; // visited array
	for (int i = 0; i < Size(); i++)
		visited[i] = false;
	int* path = new int[Size()]; // path array
	for (int i = 0; i < Size(); i++)
		path[i] = -1;
	int* distance = new int[Size()]; // distance array
	for (int i = 0; i < Size(); i++)
		distance[i] = 9999; // initialize large number.
	Vertex* start = FindVertex(startVertexKey); // start vertex
	Edge* startedge = start->GetHeadOfEdge(); // head edge
	distance[start->GetKey()] = 0; // start vertex's distance set to 0
	std::set<std::pair<Vertex*, int> > s; // set to save information
	std::pair<Vertex*, int> temp; // pair saver
	temp.first = start;
	temp.second = distance[start->GetKey()];
	s.insert(temp); // push pair information to set
	visited[start->GetKey()] = true; // visit start vertex
	while (!s.empty()) // do until set is empty
	{
		if (start->GetKey() == endVertexKey) // if endvertex path founded
			break; // break the loop
		start = s.begin()->first; // start set to set root
		int cost = s.begin()->second;
		startedge = start->GetHeadOfEdge(); // startedge set to head of start edge linked list
		s.erase(s.begin()); // pop set root
		while (startedge) // check all edge of start vertex
		{
			if (distance[startedge->GetKey()] > (cost + startedge->GetWeight())) // if new distance is shorter than previous distance
			{
				distance[startedge->GetKey()] = (cost + startedge->GetWeight()); // distance modify to new distance
				path[startedge->GetKey()] = start->GetKey(); // path changed
			}
			startedge = startedge->GetNext(); // go to next edge
		}
		Vertex* min = FindVertex(endVertexKey); // nearest vertex
		for (int i = 0; i < Size(); i++)
		{
			if (distance[i] < distance[min->GetKey()] && visited[i] == false)
				min = FindVertex(i); // find the nearest vertex that unvisited
		}
		temp.first = min;
		temp.second = distance[min->GetKey()];
		s.insert(temp); // insert nearest vertex and distance
		visited[min->GetKey()] = true; // change visit status
	}
	int key = endVertexKey; // finding path
	std::vector<int> stack; // temporary stack to save reversed path
	while (key != startVertexKey) // do until find start vertex
	{
		stack.push_back(key); // push vertex that have key
		key = path[key]; // go to previous path
	}
	a.push_back(FindVertex(startVertexKey)->GetKey()); // push startvertex to a
	while (!stack.empty()) // reversing stack
	{
		key = stack.back();
		stack.pop_back();
		a.push_back(key); // push all element in stack to a upside down
	}
	a.push_back(distance[endVertexKey]); // push final distance to a
	return a;
}

void Graph::MyFindShortestPathFloyd() {
	FindShortestPathDijkstraUsingMinHeap(1, Size()-1);
	std::ofstream fout;
	fout.open("log.txt", std::ios_base::app);
	fout << "===== FLOYD =====" << endl;
	for (int i = 0; i < Size(); i++) {
		for (int j = 0; j < Size(); j++) {
			fout << FindShortestPathUsingFloyd(i, j).at(FindShortestPathUsingFloyd(i, j).size() - 1) << " ";

		}fout << endl;
	}
	fout << "================" << endl;
}

