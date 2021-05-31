#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class MenuNode {
public:
	char MENU[100];
	int price;
	MenuNode* nextNode;
};

class CategoryNode {
public:
	char CATEGORY[100];
	CategoryNode* nextNode;
	MenuNode* Menu;
};

class List {
private:
	CategoryNode* head = new CategoryNode;
public:
	List() { // constructor
		head->nextNode = nullptr;
	}
	~List() {}
	bool INSERT(char *category, char *menu, int price) {
		if (Duplicate(menu)) {
			cout << menu << " already exists!" << endl;
			return false;
		}
		//////////// *** NODE SETTING *** //////////////		
		CategoryNode* NEW = new CategoryNode; // new Category
		MenuNode* MNEW = new MenuNode; // new Menu
		strcpy(NEW->CATEGORY,category);
		
		strcpy(MNEW->MENU,menu);
		
		MNEW->price = price;
		NEW->nextNode = nullptr;
		MNEW->nextNode = nullptr;
		////////////////////////////////////////////////
		
		if (head->nextNode == nullptr) { // first Node is NULL
			NEW->Menu = MNEW;
			head->nextNode = NEW;
		}
		else {
			CategoryNode* temp = head;
			while (temp->nextNode != nullptr) {
				temp = temp->nextNode; // CategoryNode Moving 
				MenuNode* ttemp = temp->Menu; // Menu Node Moving
				if (!_stricmp(temp->CATEGORY, category)) { // string compare
					MenuNode* tmp = new MenuNode;
					MenuNode* parent = ttemp;
					tmp->nextNode = nullptr;
					strcpy(tmp->MENU, menu);
					tmp->price = price;
					////////////// **checking duplication** ////////////////
					int check = 0;
					if (ttemp->price > tmp->price) {
						
						tmp->nextNode = ttemp;
						temp->Menu = tmp;
						return true;
					}
					else if (ttemp->price == tmp->price) {
						if (_stricmp(tmp->MENU, ttemp->MENU) < 0) {
							tmp->nextNode = ttemp;
							temp->Menu = tmp;
							return true;
						}
					}
					while (ttemp->nextNode!=nullptr) {
						check++;
						if (ttemp->nextNode->price > tmp->price) {

							break;
						}
						else if (ttemp->nextNode->price == tmp->price) {
							if (_stricmp(tmp->MENU, ttemp->nextNode->MENU)<0)
								break;
						}
						parent = ttemp;
						ttemp = ttemp->nextNode;

					}
					
					///////////////////////////////////////////////////////
					tmp->nextNode = ttemp->nextNode;
					ttemp->nextNode = tmp; // Insert Menu Node
					
					return true;
				}
				
				
			}
			NEW->Menu = MNEW; // NEW MENU
			temp->nextNode = NEW; // NEW CATEGORY
			
		}
		
		return true;
	}
	
	void PRINT() {
		CategoryNode* temp = head;
		if (temp->nextNode == nullptr) //  linked list do not exist.
		{
			cout << "The data does not exist!" << endl;
			return;
		}
		while (temp->nextNode != nullptr) { // all print
			temp = temp->nextNode;
			MenuNode* tmp = temp->Menu;
			cout << "===========" << temp->CATEGORY << "============" << endl << endl;
			while (tmp != nullptr) {
				cout << tmp->MENU << " " << tmp->price << endl;
				tmp = tmp->nextNode;
			}
			cout << endl;
		}
		return;
	}
	void LOAD() {
		ifstream fin("input.txt"); // file open.
		char buf[100] = { 0, };
		fin.getline(buf, 100);
		while (!fin.eof()) {
			char buf[100] = { 0, };
			
			fin.getline(buf, 100);
			int price = 0;
			///////////////////** String tokenizing **//////////////////
			char* category = strtok(buf, " \t"); // CATEGORY
			if (category == nullptr) { // exception handling
				cout <<"Invalid Input" << endl << endl;
				continue;
			}
			char* menu = strtok(NULL, " \t"); // MENU
			if (menu == nullptr) { // exception handling
				cout <<" Invalid Input" << endl << endl;
				continue;
			}
			char* ptr = strtok(NULL, " \t"); // PRICE
			///////////////////////////////////////////////////////////
			if (ptr == nullptr) { // exception handling
				cout << menu << " Invalid Input" << endl << endl;
				continue;
			}
			price = atoi(ptr);
			INSERT(category, menu, price);
		}
		cout << "LOAD Success!" << endl;
		fin.close();
	}
	void CategorySEARCH(char * category) {
		CategoryNode* temp = head;
		if (temp->nextNode == NULL) // exception handling
			cout << "Category do not exist" << endl;
		else {
			while (temp->nextNode != NULL) {
				temp = temp->nextNode;
				if (!_stricmp(temp->CATEGORY, category)) { // string compare
					MenuNode* ttemp = temp->Menu;
					
					cout << temp->CATEGORY << endl;
					while (ttemp != NULL) {
						
						
						cout << ttemp->MENU << " " << ttemp->price << endl;
						ttemp = ttemp->nextNode;
					}
					cout << endl;
					return;
				}					
			}
			cout << category << " is category that do not exist" << endl << endl;
		}
	}
	void MenuSEARCH(char * menu) {
		CategoryNode* temp = head;
		if (temp->nextNode == NULL)
			cout << "Menu do not exist" << endl << endl;
		else { ///////// SEARCH LINKED LIST ////////////
			while (temp->nextNode != NULL) { 
				temp = temp->nextNode;
				MenuNode* ttemp = temp->Menu;
				while (ttemp != NULL) {
					if (!_stricmp(ttemp->MENU, menu)) {
						cout << ttemp->MENU << " " << ttemp->price << endl << endl;
						return;
					}
					ttemp = ttemp->nextNode;
				}
				
			}
			cout << menu << " is menu that do not exist" << endl << endl;
		}
	}
	void DELETE(char * menu) { // DELETE
		CategoryNode* temp = head;
		CategoryNode* parent = temp;
		if (temp->nextNode == NULL)
			cout << "List do not exist" << endl << endl;
		else {
			while (temp->nextNode != NULL) {
				parent = temp;
				temp = temp->nextNode;
				MenuNode* ttemp = nullptr;
				MenuNode* del = temp->Menu;
				/// if DELETE NODE is first node
				if (!_stricmp(del->MENU, menu)) { // if del is first menu node
					if (del->nextNode == NULL) {  
						parent->nextNode = temp->nextNode;
						delete temp;
						cout << "Delete Success!" << endl;
						return;
					}
					
					temp->Menu = del->nextNode;
					delete del;
					cout << "Delete Success!" << endl;
					return;
				}
				while (del->nextNode != NULL) {
					
					if (!_stricmp(del->nextNode->MENU, menu)) {
						ttemp = del;
						del = del->nextNode;
						ttemp->nextNode = del->nextNode;
						delete del;
						cout << "Delete Success!" << endl;
						return;
					}
					
					del = del->nextNode;
					
				}

			}
			cout << menu << " is category that do not exist" << endl << endl;
		}
	}
	bool Duplicate(char* menu) {
		CategoryNode* temp = head;
		
		while (temp->nextNode != nullptr) { // all print
			temp = temp->nextNode;
			MenuNode* tmp = temp->Menu;
			
			while (tmp != nullptr) {
				if (!_stricmp(tmp->MENU, menu))
					return true;
				tmp = tmp->nextNode;
			}
		}
		return false;
	}

};