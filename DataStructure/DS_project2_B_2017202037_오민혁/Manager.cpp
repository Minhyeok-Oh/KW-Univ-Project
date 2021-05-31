#define _CRT_SECURE_NO_WARNINGS
#include "Manager.h"
#include <stdlib.h>
#include <fstream>
using namespace std;

Manager::Manager()
{
	flog.open("log.txt", ios::app);
	flog.setf(ios::fixed);

	avl = new AVLTree(&flog);
	gp = new Graph(&flog);
	iter = 0;
	cmd = NULL;
}

Manager::~Manager()
{
	flog.close();
}

void Manager::run(const char * command)
{

	fin.open(command);
	char * str = new char[40];
	while (!fin.eof())
	{
		iter = iter + 1;
		cmd = new char[40];
		fin.getline(cmd, 40);
		str = cmd;
		char * one = strtok(cmd, " \t");
		
		if (!strcmp(one, "LOAD")) {
			if (LOAD()) printSuccessCode("LOAD");
			else printErrorCode(100, "LOAD");
		}
		else if (!strcmp(one, "INSERT")) {
			CityData * AVLNode = new CityData(); // set node with insert data
			one = strtok(NULL, " \t"); // string tokenizing
			AVLNode->SetLocationId(atoi(one));
			one = strtok(NULL, " \t");
			AVLNode->Setname(one);
			one = strtok(NULL, " \t");
			AVLNode->Setcountry(one);
			flog << "==> command " << iter << ") " << "INSERT" << endl;
			if (!INSERT(AVLNode)||avl->root==NULL) flog << "Error code : 200" << endl;
		}
		else if (!strcmp(one, "PRINT_AVL")) { // print avl
			flog << "==> command " << iter << ") " << "PRINT_AVL" << endl;
			if (avl->root == NULL) {
				flog << "Error code : 300" << endl; 
				continue; 
			}
			if (!PRINT_AVL()) flog << "Error code : 300" << endl;
		}
		else if (!strcmp(one, "SEARCH_AVL")) { // search node of avl
			one = strtok(NULL, " ");
			int num = atoi(one);
			if (num == 0) {
				printErrorCode(500, "SEARCH_AVL");
				continue;
			}
			flog << "==> command " << iter << ") " << "SEARCH_AVL" << endl;
			if (!SEARCH_AVL(num)) flog << "Error code : 500" << endl;
		}
		else if (!strcmp(one, "DELETE_AVL")) { // delete node of avl
			one = strtok(NULL, " ");
			int num = atoi(one);
			if (num == 0) {
				printErrorCode(400, "DELETE_AVL");
				continue;
			}
			flog << "==> command " << iter << ") " << "DELETE_AVL" << endl;
			if (!DELETE_AVL(num)) flog << "Error code : 400" << endl;
			else flog << "Success" << endl;

		}
		else if (!strcmp(one, "BUILD_GP")) { // make graph
			if (BUILD_GP()) printSuccessCode("BUILD_GP");
			else if(avl->root==NULL)printErrorCode(600, "BUILD_GP");
		}
		else if (!strcmp(one, "PRINT_GP")) { // print graph
			flog << "==> command " << iter << ") " << "PRINT_GP" << endl;
			if(!PRINT_GP()||gp->mList==NULL) flog << "Error code : 700" << endl;
			//call function()
		}
		else if (!strcmp(one, "BUILD_MST")) { // make MST
			if (BUILD_MST()) printSuccessCode("BUILD_MST");
			else if(gp->mList==NULL)printErrorCode(800, "BUILD_MST");
		}
		else if (!strcmp(one, "PRINT_MST")) { // print MST
			flog << "==> command " << iter << ") " << "PRINT_MST" << endl;
			if(!PRINT_MST()||gp->mList==NULL) flog<< "Error code : 900" <<endl;
		}		
		else if (!strcmp(one, "EXIT")) { // program ending
			printSuccessCode("EXIT"); EXIT();
		}
		else {
			printErrorCode(0,"Unknown");
		}
	}
	fin.close();
	return;
}

bool Manager::LOAD()
{
	ifstream fin("city_list.txt");
	
	if (!fin||avl->Getroot()!=NULL)
		return false;
	while (!fin.eof()) // make AVLTree with city_list.txt
	{
		char * city = new char[100];
		CityData * iNode = new CityData();
		fin.getline(city, 100);
		char * token = strtok(city, " \t");
		iNode->SetLocationId(atoi(token));
		token = strtok(NULL, " \t");
		iNode->Setname(token);
		token = strtok(NULL, " \t");
		iNode->Setcountry(token);
		avl->Insert(iNode);
	}

	return true;
	
}

bool Manager::INSERT(CityData * AVLNode) // INSERT node at AVL Tree
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	avl->Insert(AVLNode);
	fout << "( " << AVLNode->GetLocationId() << ", " << AVLNode->Getname() << ", " << AVLNode->Getcountry() << " )" << endl;
	if (avl->Getroot() == NULL)
		return false;
	return true;
}

bool Manager::PRINT_AVL() // Print AVL Tree
{
	avl->Print();
	return true;
}

bool Manager::SEARCH_AVL(int num) // Search node with num
{
	CityData * res = avl->Search(num);
	ofstream fout;
	fout.open("log.txt", ios::app);
	fout << "( " << res->GetLocationId() << ", " << res->Getname() << ", " << res->Getcountry() << " )" << endl;
	return true;
}

bool Manager::DELETE_AVL(int num) // Delete node with num
{
	avl->Delete(num);
	ofstream fout;
	fout.open("log.txt", ios::app);	
	return true;
}

bool Manager::BUILD_GP() // make Graph
{
	gp->Build(avl);
	return true;
}

bool Manager::PRINT_GP() // print graph
{
	gp->Print_GP();
	return true;
}

bool Manager::BUILD_MST() // make MST
{
	gp->Kruskal();
	return true;
}

bool Manager::PRINT_MST() // print MST
{
	gp->Print_MST();
	return true;
}

void Manager::EXIT()
{
	exit(1);
}

void Manager::printErrorCode(int n, const char * cmdname) {//ERROR CODE PRINNT FUNCTION
	flog << "==> command " << iter << ") " << cmdname << endl;
	flog << "Error code: " << n << endl;
}

void Manager::printSuccessCode(const char * cmdname) {//SUCCESS CODE PRINNT FUNCTION
	flog << "==> command " << iter << ") " << cmdname << endl;
	flog << "Success" << endl;
}
