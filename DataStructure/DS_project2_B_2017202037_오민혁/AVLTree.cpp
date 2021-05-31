#include "AVLTree.h"

AVLTree::AVLTree(ofstream * flog)
{
	this->flog = flog;
	this->root = NULL;
}

AVLTree::~AVLTree()
{
}

AVLNode * AVLTree::Getroot()
{
	return this->root;
}

void AVLTree::Setroot(AVLNode * node)
{
	this->root = node;
}
// insertion of AVLTree
bool AVLTree::Insert(CityData * node)
{
	AVLNode *y = new AVLNode;
	y->SetCityData(node); //set the node's citydata

	if (root == NULL) {
		root = y;
		return true;
	}//AVLTree is empty. make the new node is header.

	AVLNode *a = root;
	AVLNode *pa = NULL;
	AVLNode *p = root;
	AVLNode *pp = NULL;
	AVLNode *rootSub = NULL;

	while (p != NULL) { //data check and setting
		if (p->GetmBF() != 0) { a = p; pa = pp; }
		if (strcmp(node->Getname(), p->GetCityData()->Getname()) < 0) { pp = p; p = p->GetLeft(); }
		else if (strcmp(node->Getname(), p->GetCityData()->Getname()) > 0) { pp = p; p = p->GetRight(); }
	}
	
	if (strcmp(node->Getname(), pp->GetCityData()->Getname()) < 0)
		pp->SetLeft(y);
	else
		pp->SetRight(y);
	/* for balance checking and rotation */
	int d;
	AVLNode *b, *c;

	if (strcmp(node->Getname(), a->GetCityData()->Getname()) > 0) { // right
		b = p = a->GetRight();
		d = -1;
	}
	else {
		b = p = a->GetLeft(); // left
		d = 1;
	}

	while (p != y) { //height changing
		if (strcmp(node->Getname(), p->GetCityData()->Getname()) > 0) {
			p->SetmBF(-1);
			p = p->GetRight();
		}
		else {
			p->SetmBF(1);
			p = p->GetLeft();
		}
	}
	if (a->GetmBF() == 0 || a->GetmBF() + d == 0) { //tree unbalancing check.
		a->SetmBF(a->GetmBF() + d);
		return true;
	}

	//tree unbalancing. rotation occur.
	
	if (d == 1) { // LL and LR	
		if (b->GetmBF() == 1) { //LL rotation.
			a->SetLeft(b->GetRight());
			b->SetRight(a);
			a->SetmBF(0);
			b->SetmBF(0);
			rootSub = b;
		}
		else { //LR rotation
			c = b->GetRight();
			b->SetRight(c->GetLeft());
			a->SetLeft(c->GetRight());
			c->SetLeft(b);
			c->SetRight(a);

			switch (c->GetmBF()) {//change the form and change the mBF.
			case 0:
				b->SetmBF(0);
				a->SetmBF(0);
				break;
			case 1:
				a->SetmBF(-1);
				b->SetmBF(0);
				break;
			case -1:
				b->SetmBF(1);
				a->SetmBF(0);
				break;
			}
			c->SetmBF(0);
			rootSub = c; //c is the root of subtree. left is b, right is a.				
		}
	}
	else { // RL and RR rotation.
		if (b->GetmBF() == -1) { // RR start.
			a->SetRight(b->GetLeft());
			b->SetLeft(a);
			a->SetmBF(0);
			b->SetmBF(0);
			rootSub = b;
		}
		else {
			c = b->GetLeft();
			b->SetLeft(c->GetRight());
			a->SetRight(c->GetLeft());
			c->SetRight(b);
			c->SetLeft(a);
			switch (c->GetmBF()) {
			case 0:
				b->SetmBF(0);
				a->SetmBF(0);
				break;
			case 1:
				b->SetmBF(-1);
				a->SetmBF(0);
				break;
			case -1:
				a->SetmBF(1);
				b->SetmBF(0);
				break;
			}
			c->SetmBF(0);
			rootSub = c;
		}
	}

	if (pa == NULL)
		root = rootSub;
	else if (a == pa->GetLeft())
		pa->SetLeft(rootSub);
	else
		pa->SetRight(rootSub);
	
	return true;

}

AVLNode * AVLTree::Delete(int num)
{
	// find node with num
	stack <AVLNode*> s;
	AVLNode * temp = root;
	if (root == NULL) { // root empty
		return NULL;
	}
	while (1) { // search delete node
		while (temp) {
			s.push(temp);
			temp = temp->GetLeft();
		}
		if (s.empty()) return NULL;
		temp = s.top();

		s.pop();
		if (temp->GetCityData()->GetLocationId() == num) {
			break;
		}
		temp = temp->GetRight();
	}
	
	AVLNode* p = root, *q = 0;

	while (p != NULL) { // set deleting position
		if (strcmp(temp->GetCityData()->Getname(), p->GetCityData()->Getname()) < 0) { q = p; p = p->GetLeft(); }
		else if (strcmp(temp->GetCityData()->Getname(), p->GetCityData()->Getname()) > 0) { q = p; p = p->GetRight(); }
		else break;
	}
	if (p->GetLeft() == 0 && p->GetRight() == 0) // no child
	{
		if (q == 0)root = 0;
		else if (q->GetLeft() == p) q->SetLeft(0);
		else q->SetRight(0);
	}
	else if (p->GetLeft() == 0) // no left child
	{
		if (q == 0)root = p->GetRight();
		else if (q->GetLeft() == p) q->SetLeft(p->GetRight());
		else q->SetRight(p->GetRight());
	}
	else if (p->GetRight() == 0) // no right child
	{
		if (q == 0)root = p->GetLeft();
		else if (q->GetLeft() == p)q->SetLeft(p->GetLeft());
		else q->SetRight(p->GetLeft());
	}
	else {
		AVLNode *prevprev = p, *prev = p->GetRight(), *curr = p->GetRight()->GetLeft();
		while (curr) {
			prevprev = prev;
			prev = curr;
			curr = curr->GetLeft();
		}
		p->SetCityData(prev->GetCityData());
		if (prevprev == p)prevprev->SetRight(prev->GetRight());
		else prevprev->SetLeft(prev->GetRight());
		delete prev;
	}
	RenewmBF(root); // renew all mBF
	/* for balance checking and rotation */
	AVLNode * rt = root;
	stack <AVLNode*> t;
	// inorder travelsal
	while (1) {
		while (rt) {
			t.push(rt);
			rt = rt->GetLeft();
		}
		if (t.empty()) return NULL;
		rt = t.top();

		t.pop();
		if (rt->GetmBF() > 1 || rt->GetmBF() < -1) {
			break; // unbalance node position store
		}
		rt = rt->GetRight();
	}
	
	AVLNode *pa = NULL, *a = root;
	while (a != NULL) { // set deleting position
		if (strcmp(rt->GetCityData()->Getname(), a->GetCityData()->Getname()) < 0) { pa = a; a = a->GetLeft(); }
		
		else if (strcmp(rt->GetCityData()->Getname(), a->GetCityData()->Getname()) > 0) { pa = a; a = a->GetRight(); }
		else {
			break;
		}
	}
	AVLNode * tq = CheckBalance(rt); // rotation node store
	if (pa == NULL) { // root empty.
		Setroot(tq);
		return NULL;
	}

	if (strcmp(tq->GetCityData()->Getname(), pa->GetCityData()->Getname()) < 0) { // left child
		pa->SetLeft(tq); 
	}
	else if(strcmp(tq->GetCityData()->Getname(), pa->GetCityData()->Getname())>0) // right child
	{
		pa->SetRight(tq);
	}
	
	RenewmBF(root); // renew all mBF
	
	return NULL;
}

CityData * AVLTree::Search(int num)
{
	stack <AVLNode*> s;
	AVLNode* pCur = root;

	if (root == NULL) { // root empty
		return NULL;
	}
	while (1) { // inorder traversal
		while (pCur) {
			s.push(pCur);
			pCur = pCur->GetLeft();
		}
		
		if (s.empty()) return NULL;
		pCur = s.top();

		s.pop();
		if (pCur->GetCityData()->GetLocationId() == num) {
			return pCur->GetCityData();
		}
		pCur = pCur->GetRight();

	}
	
	return NULL;
}
//print avl tree all
bool AVLTree::Print()
{
	stack <AVLNode*> s;
	AVLNode * pCur = root;
	ofstream fout;
	fout.open("log.txt", ios::app);

	if (root == NULL) {
		return false;
	}
	while (1) { // inorder traversal
		while (pCur) {
			s.push(pCur);
			pCur = pCur->GetLeft();
		}
		if (s.empty()) return true;
		pCur = s.top();
		s.pop();
		fout << "( " << pCur->GetCityData()->GetLocationId() << ", " << pCur->GetCityData()->Getname() << ", " << pCur->GetCityData()->Getcountry() << " )" << endl;
		pCur = pCur->GetRight();
	}
	
	return true;
}
