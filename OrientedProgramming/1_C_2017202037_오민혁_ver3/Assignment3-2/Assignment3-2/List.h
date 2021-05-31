#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
	Node * next;
	Node * prev;
	char name[100];
	char professor[100];
	int grade = 0;
};

class List {
private:
	Node * head;
	Node* tail;
	int count = 0;
public:
	List()
	{
		head = NULL;
		tail = NULL;
		count = 0;
	}
	~List() {}

	void InsertAtBeginning(char* name, char* professor, int grade) {
		//////// ** NODE SETTING ** ///////////
		Node* newNode = new Node;
		strcpy(newNode->name, name);
		strcpy(newNode->professor, professor);
		newNode->grade = grade;
		////////////////////////////////////


		if (head == NULL) { // list do not exist.
			head = newNode;
			tail = newNode;
			head->prev = tail;
			tail->next = head;
			count++;
		}
		else {
			Node* temp = head;
			for (int i = 0; i < count; i++) {
				if (!_stricmp(temp->name, name)) {
					cout << temp->name << " is duplicate lecture" << endl;
					return;
				}
				temp = temp->next;
			}
			/// insert node at head
			temp->prev = newNode;
			newNode->next = temp;
			newNode->prev = head;
			head = newNode;
			tail->next = head;
			

			count++;


		}
	
	}
	void InsertAtLast(char* name, char* professor, int grade) {
		/////////////// ** NODE SETTING ** ///////////////////
		Node* newNode = new Node;
		strcpy(newNode->name, name);
		strcpy(newNode->professor, professor);
		newNode->grade = grade;
		/////////////////////////////////////////////////////

		if (head == NULL) {
			head = newNode;
			tail = newNode;
			head->prev = tail;
			tail->next = head;
			count++;
		}
		else {
			Node* temp = head;
			for (int i = 0; i < count; i++) {
				if (!_stricmp(temp->name, name)) {
					cout << temp->name << " is duplicate lecture" << endl;
					return;
				}
				temp = temp->next;
			}
			// insert node at tail
			tail->next = newNode;
			newNode->prev = tail;
			tail = newNode;
			newNode->next = head;
			head->prev = newNode;
			count++;


		}

	}
	void InsertAtPosition(char* name, char* professor, int grade, int position) {
		/////////////// ** NODE SETTING ** ///////////////////
		Node* newNode = new Node;
		strcpy(newNode->name, name);
		strcpy(newNode->professor, professor);
		newNode->grade = grade;
		/////////////////////////////////////////////////////
		Node* temp = head;
		if (temp != NULL) {
			for (int i = 0; i < count; i++) {
				if (!_stricmp(temp->name, name)) {
					cout << temp->name << " is duplicate lecture" << endl;
					return;
				}
				temp = temp->next;
			}
		}

		
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			head->prev = tail;
			tail->next = head;
			count++;
		}
		else if (position == 1) { // position = head
			head->prev = newNode;
			newNode->next = head;

			newNode->prev = tail;
			tail->next = newNode;
			head = newNode;
			count++;
		}
		else if (position == count + 1) { // position == tail
			tail->next = newNode;
			newNode->prev = tail;
			
			newNode->next = head;
			head->prev = newNode;
			tail = newNode;
			count++;
		}
		else { // insert at input position
			Node* temp = tail;
			for (int i = 0; i < position - 1; i++) {
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;
			newNode->prev = temp;
			newNode->next->prev = newNode;
			count++;
		}

	}
	void DELETE(char * name) {
		Node* temp = head;
		if (temp == NULL) {
			cout << "list do not exist" << endl;
			return;
		}
		
		for (int i = 0; i < count; i++) {
			if (!_stricmp(temp->name, name)) {
				
				Node* del = temp;
				if (del == head) { // del = head
					
					head = del->next;
					tail->next = head;
					head->prev = del->prev;
					count--;
					cout << "**" << del->name << " has been deleted from position" << i+1 << "**" << endl;
					return;
				}
				else if (del == tail) {// del == tail

					tail = del->prev;
					head->prev = tail;



					tail->next = del->prev;
					count--;
					cout << "**" << del->name << " has been deleted from position" << i+1 << "**" << endl;
					return;
				}
				// node deletion
				temp->prev->next = del->next;
				del->next->prev = temp->prev;
				cout << "**" << del->name << " has been deleted from position" << i+1 << "**" << endl;
				count--;
				
				
				delete del;
				return;
			}
			
			temp = temp->next;
		}
		cout << name << " do not exist" << endl;
	}
	// NOT REVERSE PRINT
	void PRINT() {
		Node* temp = head;
		for(int i=0; i<count; i++) {
			cout << "lecture name: " << temp->name << endl;
			cout << "lecture professor: " << temp->professor << endl;
			cout << "lecture grade: " << temp->grade << endl;
			temp = temp->next;
		}
	}
	// REVERSE PRINT
	void RePrint() {
		Node* temp = tail;
		for (int i = 0; i < count; i++) {
			cout << "lecture name: " << temp->name << endl;
			cout << "lecture professor: " << temp->professor << endl;
			cout << "lecture grade: " << temp->grade << endl;
			temp = temp->prev;
		}
	}
	void UPDATE(char * name) { // NODE DATA UPDATING
		
		Node* temp = head;
		if (temp == NULL) {
			cout << "list do not exist." << endl;
			return;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (!_stricmp(temp->name, name)) {
					cout << "->Enter the new lecture name: ";
					cin >> temp->name;
					cout << "->Enter the new lecture professor: ";
					cin >> temp->professor;
					cout << "->Enter the new lecture grade: ";
					cin >> temp->grade;
					
				}
				temp = temp->next;
			}
			return;
		}
		cout << "No information to update" << endl;
	}
	//SEARCH LECTURE
	void Searchlecture(char*name) {
		Node* temp = head;
		int no = 0;
		if (temp == NULL) {
			cout << "list do not exist." << endl;
			return;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (!_stricmp(temp->name, name)) {
					cout << "*At position " << i + 1 << "*" << endl;
					cout << "lecture name: " << temp->name << endl;
					cout << "lecture professor: " << temp->professor << endl;
					cout << "lecture grade: " << temp->grade << endl;
					no = 1;
				}
				temp = temp->next;
			}
			
		}
		if(no!=1)
			cout << "No information to search" << endl;
		return;
	}
	//SEARCH PROFESSOR
	void Searchprofessor(char*professor) {
		Node* temp = head;
		int no = 0;
		if (temp == NULL) {
			cout << "list do not exist." << endl;
			return;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (!_stricmp(temp->professor, professor)) {
					cout << "*At position " << i + 1 << "*" << endl;
					cout << "lecture name: " << temp->name << endl;
					cout << "lecture professor: " << temp->professor << endl;
					cout << "ecture grade: " << temp->grade << endl;
					no = 1;
				}
				temp = temp->next;
			}
			
		}
		if (no != 1)
			cout << "No information to search" << endl;
		return;
	}
	//SEARCH GRADE
	void Searchgrade(int grade) {
		int no = 0;
		Node* temp = head;
		if (temp == NULL) {
			cout << "list do not exist." << endl;
			return;
		}
		else {
			for (int i = 0; i < count; i++) {
				if (temp->grade==grade) {
					cout << "*At position " << i + 1 << "*" << endl;
					cout << "lecture name: " << temp->name << endl;
					cout << "lecture professor: " << temp->professor << endl;
					cout << "lecture grade: " << temp->grade << endl;
					no = 1;
				}
				temp = temp->next;
			}
			
		}
		if (no != 1)
			cout << "No information to search" << endl;
		return;
	}
	// SORTING ascending of grade
	void sorting() {
		Node* temp = head;
		if (head == NULL){
			cout << "list do not exist." << endl;
			return;
		}
		else if (head->next == NULL) {
			cout << "list have only one node." << endl;
			return;
		}
		else {
			
			for(int i=0; i<count-1; i++) {
				
				Node* move = temp->next;

				for (int j = i+1; j < count; j++) {
					
					if (temp->grade > move->grade) {
						Node* ttemp = new Node;

						strcpy(ttemp->name, temp->name);
						strcpy(ttemp->professor, temp->professor);
						ttemp->grade = temp->grade;

						strcpy(temp->name, move->name);
						strcpy(temp->professor, move->professor);
						temp->grade = move->grade;

						strcpy(move->name, ttemp->name);
						strcpy(move->professor, ttemp->professor);
						move->grade = ttemp->grade;
						
						
					}
					move = move->next;
					
				}
				temp = temp->next;
			}
		}
		
		
	}
	

};