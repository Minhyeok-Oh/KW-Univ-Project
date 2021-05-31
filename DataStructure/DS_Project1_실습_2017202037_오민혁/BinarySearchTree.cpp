#include "BinarySearchTree.h"

void BinarySearchTree::insert(SoccerPlayerData& data) {
	TreeNode * InsertNode = new TreeNode(data); // insert node 
	TreeNode * CurNode = m_root; // current node
	
	if (!CurNode) {
		m_root = InsertNode; // no exist root node
	}
	else {
		for (;;) { // infinite loop
			if (InsertNode->m_data.m_ability > CurNode->m_data.m_ability) { // case insert node larger than current node
				if (CurNode->getRightNode()!=NULL) // already right node is exist
					CurNode = CurNode->getRightNode(); // move at right
				else {
					CurNode->setRightNode(InsertNode); // if right node is null, curren node insert 
					break;
				}
			}
			else{
				if (CurNode->getLeftNode()!=NULL) // case insert node smaller than currunt node
					CurNode = CurNode->getLeftNode(); // already left node is exist
				else {
					CurNode->setLeftNode(InsertNode); // if left node is null, current node insert
					break;
				}
			}
		}
	}
}

void BinarySearchTree::deletion(int ability) 
{
	TreeNode *Current = m_root, *Prev = NULL;
	//set position of deleting node
	while (Current && ability != Current->m_data.m_ability) { 
		Prev = Current; // prev node
		if (ability < Current->m_data.m_ability) // move at left
			Current = Current->getLeftNode();
		else
			Current = Current->getRightNode(); // move at right
	}

	if (Current == NULL) return; // end

	if (Current->getLeftNode() == NULL && Current->getRightNode() == NULL) { // case 1. no child node
		if (Prev == NULL) // prev node do not exist
			m_root = NULL; // delete root node
		else if (Prev->getRightNode() == Current)
			Prev->setRightNode(NULL); // delete current node
		else
			Prev->setLeftNode(NULL); // delete current node
		delete Current;

		return; // end
	}

	if (Current->getLeftNode() == NULL) { // case 2. no left child node
		if (Prev == NULL) // current node is root
			m_root = Current->getRightNode(); // delete root and right node is root
		else if (Prev->getRightNode() == Current) 
			Prev->setRightNode(Current->getRightNode()); // delete current node
		else
			Prev->setLeftNode(Current->getRightNode()); // delete current node

		delete Current;
		return; // end
	}

	if (Current->getRightNode() == NULL) { // case 3. no right child node
		if (Prev == NULL) // current node is root
			m_root = Current->getLeftNode(); // delete root and left node is root
		else if (Prev->getRightNode() == Current) 
			Prev->setRightNode(Current->getLeftNode()); // delete current node
		else
			Prev->setLeftNode(Current->getLeftNode()); // delete current node

		delete Current;
		return; // end
	}
	// case 4. has left and right child
	TreeNode *pp = Current, *p = Current->getLeftNode();
	TreeNode *curr = Current->getLeftNode()->getRightNode();

	while (curr) {
		pp = p;
		p = curr;
		curr = curr->getRightNode();
	}

	Current->setData(p->m_data);
	if (pp == Current) 
		pp->setLeftNode(p->getRightNode());
	else
		pp->setRightNode(p->getRightNode());
	delete p;
}