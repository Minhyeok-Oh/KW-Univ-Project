#include "Manager.h"
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <cstdio>
Manager::~Manager()
{
    if (fout.is_open())
        fout.close();

}
void Manager::quickSort(int arr[], int low, int high) {
	if (low < high) {
		int i = low, j = high + 1;
		int pivot = arr[low];
		do {
			do i++; while (arr[i] < pivot);
			do j--; while (arr[j] > pivot);
			if (i < j) swap(arr[i], arr[j]);
		} while (i < j);
		swap(arr[low], arr[j]);
		quickSort(arr, low, j - 1);
		quickSort(arr, j + 1, high);
	}
}
void Manager::Run(const char* filepath)
{
    fout.open(RESULT_LOG_PATH);
	fout.close();
	ifstream fin;
	fin.open(filepath);

	if (!fin.is_open())
	{
		PrintError(CommandFileNotExist);
		fout.open(RESULT_LOG_PATH, ios_base::app);
		fout << "====== SYSTEM ======" << endl << "CommandFileNotExist" << endl << "==================" << endl;
		fout.close();
		return;
	}
	while (!fin.eof())
	{
		char temp[40], inst[30], param1[30], param2[30];
		char * check[1];
		fin.getline(temp, 40);
		if (temp[0] == 0)
			break;
		strcpy(inst, strtok_r(temp, " \n", &check[0]));
		if (!strcmp(inst, "LOAD"))
		{
			strcpy(param1, strtok_r(NULL, "\n", &check[0]));
			PrintError(Load(param1));
		}
		else if (!strcmp(inst, "PRINT"))
		{
			PrintError(Print());
		}
		else if (!strcmp(inst, "DIJKSTRA"))
		{
			int num1 = -1;
			int num2 = -1; // num1,2 are parameter of function
			if (check[0][0] == 0) // if there is no vertexkey
				num1 = num2 = -65535;
			else strcpy(param1, strtok_r(NULL, " \n", &check[0])); // parameter 1 set
			if (check[0][0] == 0) // if there is one vertexkey
				num1 = num2 = -65535;
			else // if there are two vertex keys
			{
				strcpy(param2, strtok_r(NULL, "\n", &check[0])); // parameter 2 set
				num1 = (int)atoi(param1);				// transform word to integer
				num2 = (int)atoi(param2);				// transform word to integer
			}
			PrintError(FindShortestPathDijkstraUsingSet(num1, num2)); // Do Dijkstra function
		}
		else if (!strcmp(inst, "DIJKSTRAMIN"))
		{
			int num1 = -1;
			int num2 = -1; // num1,2 are parameter of function
			if (check[0][0] == 0) // if there is no vertexkey
				num1 = num2 = -65535;
			else strcpy(param1, strtok_r(NULL, " \n", &check[0])); // parameter 1 set
			if (check[0][0] == 0) // if there is one vertexkey
				num1 = num2 = -65535;
			else // if there are two vertex keys
			{
				strcpy(param2, strtok_r(NULL, "\n", &check[0])); // parameter 2 set
				num1 = (int)atoi(param1);				// transform word to integer
				num2 = (int)atoi(param2);				// transform word to integer
			}
			PrintError(FindShortestPathDijkstraUsingMinHeap(num1, num2)); // Do dijkstra min heap function
		}
		else if (!strcmp(inst, "BELLMANFORD"))
		{
			int num1 = -1;
			int num2 = -1; // num1,2 are parameter of function
			if (check[0][0] == 0) // if there is no vertexkey
				num1 = num2 = -65535;
			else strcpy(param1, strtok_r(NULL, " \n", &check[0])); // parameter 1 set
			if (check[0][0] == 0) // if there is one vertexkey
				num1 = num2 = -65535;
			else // if there are two vertex keys
			{
				strcpy(param2, strtok_r(NULL, "\n", &check[0])); // parameter 2 set
				num1 = (int)atoi(param1);				// transform word to integer
				num2 = (int)atoi(param2);				// transform word to integer
			}
			PrintError(FindShortestPathBellmanFord(num1, num2)); // Do bellman ford function
		}
		else if (!strcmp(inst, "FLOYD"))
		{

			PrintError(MyFindShortestPathFloyd());

		}
		else // Wrong instruction entered
		{
			fout.open(RESULT_LOG_PATH, ios_base::app);
			fout << "====== " << inst << " ======" << endl << "NonDefinedCommand" << endl << "==================" << endl;
			fout.close(); // write error message to result log file.
			PrintError(NonDefinedCommand); // Print error 300
		}
	}
	m_graph.Clear();
	return;
}
void Manager::PrintError(Result result)
{
	fout.open(RESULT_LOG_PATH, ios_base::app);
	fout << endl << "=================" << endl << "Error code:" << result << endl << "================" << endl << endl;
	fout.close();
}

/// <summary>
/// make a graph
/// </summary>
///
/// <param name="filepath">
/// the filepath to read to make the graph
/// </param>
///
/// <returns>
/// Result::Success if load is successful.
/// Result::LoadFileNotExist if file is not exist.
/// </returns>
Result Manager::Load(const char* filepath)
{
	ifstream fin;
	fin.open(filepath);
	ofstream fout;
	fout.open(RESULT_LOG_PATH, ios_base::app);

	if (!fin.is_open())
	{
		fout << "====== LOAD ======" << endl << "LoadFileNotExist" << endl << "==================" << endl;
		fout.close();
		return LoadFileNotExist;
	}
	char temp[40];
	int num, weight;

	fin >> temp;
	num = (int)atoi(temp);

	for (int i = 0; i < num; i++)
		m_graph.AddVertex(i);

	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			fin >> temp;
			weight = (int)atoi(temp);
			m_graph.AddEdge(i, j, weight);
		}
	}
	fout << "====== LOAD ======" << endl << "Success" << endl << "===================" << endl;
	return Success;
}
/// <summary>
/// print out the graph as matrix form
/// </summary>
///
/// <returns>
/// Result::Success if the printing is successful
/// Result::GraphNotExist if there is no graph
/// </returns>
Result Manager::Print()
{
	ofstream fout;
	fout.open(RESULT_LOG_PATH, ios_base::app);
	if (m_graph.Size() == 0) {
		fout << "====== PRINT ======" << endl << "GraphNotExist" << endl << "==================" << endl;
		fout.close();
		return GraphNotExist;
	}
	m_graph.Print(fout);
	fout.close();
	return Success;
}
/// <summary>
/// find the path from startVertexKey to endVertexKey with DFS (stack)
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::InvalidAlgorithm if an exception has occurred.
/// Result::Success otherwise.
/// </returns>


/// <summary>
/// find the shortest path from startVertexKey to endVertexKey with Dijkstra using std::set
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::InvalidAlgorithm if an exception has occurred.
/// Result::Success otherwise.
/// </returns>
Result Manager::FindShortestPathDijkstraUsingSet(int startVertexKey, int endVertexKey)
{
	ofstream fout;
	fout.open(RESULT_LOG_PATH, ios_base::app);
	Vertex* Finder = m_graph.GetHead();
	if (startVertexKey == -65535 && endVertexKey == -65535) // if -65535 are entered
	{
		fout << "====== DIJKSTRA ======" << endl << "VertexKeyNotExist" << endl << "==================" << endl;
		return VertexKeyNotExist; // it means VertexKeyNotExist, return error 200 // it means VertexKeyNotExist, return error 200
	}
	bool find1 = false; // find if there is start or endvertexkey in graph
	bool find2 = false;
	while (Finder)
	{
		if (Finder->GetKey() == startVertexKey)
			find1 = 1;
		if (Finder->GetKey() == endVertexKey)
			find2 = 1;
		Finder = Finder->GetNext();
	}
	if ((find1&&find2) == false) // at least one key is missing
	{
		fout << "====== DIJKSTRA ======" << endl << "InvalidVertexKey" << endl << "==================" << endl;
		return InvalidVertexKey; // return error 200
	}
	if (m_graph.Size() == 0) // if graph is empty
	{
		fout << "====== DIJKSTRA ======" << endl << "GraphNotExist" << endl << "==================" << endl;
		return GraphNotExist; // return error 202
	}
	if (m_graph.IsNegativeEdge() == true) // if there is negativeedge in graph
	{
		fout << "====== DIJKSTRA ======" << endl << "InvalidAlgorithm" << endl << "==================" << endl;
		return InvalidAlgorithm; // return error 203
	}
	vector<int> a = m_graph.FindShortestPathDijkstraUsingSet(startVertexKey, endVertexKey); // save path and weight in vector a
	fout << "====== DIJKSTRA ======" << endl;
	fout << "shortest path: " << flush;

	for (int i = 0; i < a.size() - 1; i++) {
		fout << a.at(i) << " " << flush;
	}

	int* SortedArray = new int[a.size() - 1];

	for (int i = 0; i < a.size() - 1; i++)
		SortedArray[i] = a.at(i);

	fout << endl;
	fout << "sorted nodes: " << flush;
	quickSort(SortedArray, 0, a.size() - 2);
	for (int i = 0; i < a.size() - 1; i++)
		fout << SortedArray[i] << " ";
	fout << endl << "path length: " << a.at(a.size() - 1);
	fout << endl << "==================" << endl;
	fout.close();
	return Success; // return error 0s
					// TODO: implement
}
/// <summary>
/// find the shortest path from startVertexKey to endVertexKey with Dijkstra using MinHeap
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::InvalidAlgorithm if an exception has occurred.
/// Result::Success otherwise.
/// </returns>
Result Manager::FindShortestPathDijkstraUsingMinHeap(int startVertexKey, int endVertexKey)
{
	ofstream fout;
	fout.open(RESULT_LOG_PATH, ios_base::app);
	Vertex* Finder = m_graph.GetHead();
	if (startVertexKey == -65535 && endVertexKey == -65535) // if -65535 are entered // if -65535 are entered
	{
		fout << "====== DIJKSTRAMIN ======" << endl << "VertexKeyNotExist" << endl << "==================" << endl;
		return VertexKeyNotExist; // it means VertexKeyNotExist, return error 200
	}
	bool find1 = false; // find if there is start or endvertexkey in graph
	bool find2 = false;
	while (Finder)
	{
		if (Finder->GetKey() == startVertexKey)
			find1 = 1;
		if (Finder->GetKey() == endVertexKey)
			find2 = 1;
		Finder = Finder->GetNext();
	}
	if ((find1&&find2) == false) // at least one key is missing
	{
		fout << "====== DIJKSTRAMIN ======" << endl << "InvalidVertexKey" << endl << "==================" << endl;
		return InvalidVertexKey; // return error 200 // return error 201
	}
	if (m_graph.Size() == 0) // if graph is empty
	{
		fout << "====== DIJKSTRAMIN ======" << endl << "GraphNotExist" << endl << "==================" << endl;
		return GraphNotExist; // return error 202
	}
	if (m_graph.IsNegativeEdge() == true) // if there is negativeedge in graph
	{
		fout << "====== DIJKSTRAMIN ======" << endl << "InvalidAlgorithm" << endl << "==================" << endl;
		return InvalidAlgorithm; // return error 203
	}
	vector<int> a = m_graph.FindShortestPathDijkstraUsingMinHeap(startVertexKey, endVertexKey); // save path and weight in vector a
	fout << "====== DIJKSTRAMIN ======" << endl;
	fout << "shortest path: " << flush;

	for (int i = 0; i < a.size() - 1; i++) {
		fout << a.at(i) << " " << flush;
	}

	int* SortedArray = new int[a.size() - 1];

	for (int i = 0; i < a.size() - 1; i++)
		SortedArray[i] = a.at(i);

	fout << endl;
	fout << "sorted nodes: " << flush;
	quickSort(SortedArray, 0, a.size() - 2);
	for (int i = 0; i < a.size() - 1; i++)
		fout << SortedArray[i] << " ";
	fout << endl << "path length: " << a.at(a.size() - 1);
	fout << endl << "==================" << endl;
	fout.close();
	return Success; // return error 0s
					// TODO: implement
}
/// <summary>
/// find the shortest path from startVertexKey to endVertexKey with Bellman-Ford
/// </summary>
///
/// <param name="startVertexKey">
/// the start vertex key
/// </param>
/// <param name="endVertexKey">
/// the end vertex key
/// </param>
///
/// <returns>
/// Result::InvalidVertexKey or Result::GraphNotExist or Result::NegativeCycleDetected if exception has occurred.
/// Result::Success otherwise.
/// </returns>
Result Manager::FindShortestPathBellmanFord(int startVertexKey, int endVertexKey)
{
	std::ofstream fout;
	fout.open(RESULT_LOG_PATH, std::ios_base::app);
	Vertex* Finder = m_graph.GetHead();
	if (startVertexKey == -65535 && endVertexKey == -65535) // if -65535 are entered // if -65535 are entered
	{
		fout << "====== BELLMANFORD ======" << std::endl << "VertexKeyNotExist" << std::endl << "==================" << std::endl; // save path and weight in vector a
		return VertexKeyNotExist; // it means VertexKeyNotExist, return error 200 // it means VertexKeyNotExist, return error 200
	}
	bool find1 = false; // find if there is start or endvertexkey in graph
	bool find2 = false;
	while (Finder)
	{
		if (Finder->GetKey() == startVertexKey)
			find1 = 1;
		if (Finder->GetKey() == endVertexKey)
			find2 = 1;
		Finder = Finder->GetNext();
	}
	if ((find1&&find2) == false) // at least one key is missing
	{
		fout << "====== BELLMANFORD ======" << std::endl << "InvalidVertexKey" << std::endl << "==================" << std::endl;
		return InvalidVertexKey; // return error 200
	}
	 if (m_graph.Size() == 0) // if graph is empty
	{
		fout << "====== BELLMANFORD ======" << std::endl << "GraphNotExist" << std::endl << "==================" << std::endl;
		return GraphNotExist; // return error 202
	}
	if (m_graph.IsNegativeEdge() == true) // if there is negativeedge in graph
	{
		fout << "====== BELLMANFORD ======" << std::endl << "InvalidAlgorithm" << std::endl << "==================" << std::endl;
		return InvalidAlgorithm; // return error 203
	}
	std::vector<int> a = m_graph.FindShortestPathBellmanFord(startVertexKey, endVertexKey);
	if (a.size() == 1 && a[0] == -1)
	{
		fout << "====== BELLMANFORD ======" << std::endl << "NegativeCycleDetected" << std::endl << "==================" << std::endl;
		return NegativeCycleDetected;
	}
	fout << "====== BELLMANFORD ======" << std::endl;
	fout << "shortest path: ";
	for (int i = 0; i < a.size()-1;i++)
		fout << a.at(i) << " "; // print all element of vector
	int* SortedArray = new int[a.size() - 1];
	for (int i = 0; i < a.size() - 1; i++)
		SortedArray[i] = a.at(i);
	
	quickSort(SortedArray, 0, a.size() - 2);
	fout << endl;
	fout << "sorted nodes: " << flush;
	for (int i = 0; i < a.size() - 1; i++)
		fout << SortedArray[i] << " ";

	fout << endl << "path length: " << a.at(a.size() - 1);
	fout << endl << "==================" << endl;
	fout.close();
	return Success; // return error 0
}

Result Manager::MyFindShortestPathFloyd()
{
	ofstream fout;
	fout.open(RESULT_LOG_PATH, ios_base::app);
	m_graph.MyFindShortestPathFloyd();
	return Success;
}