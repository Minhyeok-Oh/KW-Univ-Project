#pragma once
#include <iostream>
#include "BSTNode.h"
#include "Tree.h"
using namespace std;

class Queue {
private:
	BSTNode* Head;
	int size;
public:
	Queue() {
		Head = NULL;
		size = 0;
	}
	int Getsize() {
		return size;
	}
	bool IsEmpty() {
		if (Head == NULL) return true;
		else return false;
	}
	bool Push(BSTNode* Node) {
		
		if (IsEmpty()) {
			Head = Node;
		}
		else {
			BSTNode* current = Head;
			while (current->GetNext() != NULL) {
				current = current->GetNext();
			}
			current->SetNext(Node);
		}
		size++;
		return true;
	}
	void Pushpreorder(BSTNode* head){
		Push(head);
		if (head->GetLeft() != NULL)
			Pushpreorder(head->GetLeft());
		if (head->GetRight() != NULL)
			Pushpreorder(head->GetRight());
	
	}
	void Pushinorder(BSTNode* head) {
		
		if (head->GetLeft() != NULL)
			Pushinorder(head->GetLeft());
		Push(head);
		if (head->GetRight() != NULL)
			Pushinorder(head->GetRight());

	}
	void Pushpostorder(BSTNode* head) {

		if (head->GetLeft() != NULL)
			Pushpostorder(head->GetLeft());
		if (head->GetRight() != NULL)
			Pushpostorder(head->GetRight());
		Push(head);

	}
	void Pop() {
		
		if (IsEmpty()) {
			cout << "Queue is Empty." << endl;
			return;
		}
		else {
			

			BSTNode* temp = Head;
			

			cout << temp->GetData() << " ";
			if (size == 1) {
				Head = nullptr;
				delete(Head);
			}
			else {
				temp = temp->GetNext();
				delete(Head);
				Head = temp;
			}
		
		}
		size--;
		
		return;
	}

	BSTNode* Front() {
		BSTNode* temp = Head;
		if (Head == NULL) {
			cout << "Queue do not exist." << endl;
			return NULL;
		}
		else
		{
			while (temp->GetNext() != NULL) {
				temp = temp->GetNext();
			}
		}
		return temp;
	}

};