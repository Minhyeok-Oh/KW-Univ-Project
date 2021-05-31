#include "Vertex.h"

Vertex::Vertex() {
	m_key = 0;
	m_size = 0;
	m_pEHead = NULL;
	m_pNext = NULL;
}
Vertex::Vertex(int key) {
	m_key = key;
	m_size = 0;
	m_pEHead = NULL;
	m_pNext = NULL;
}
Vertex::~Vertex()
{
	m_pEHead = NULL;
	m_pNext = NULL;
	delete m_pEHead;
	delete m_pNext;
}

void Vertex::SetNext(Vertex*pNext)
{
	m_pNext = pNext;
}

int Vertex::GetKey() const
{
	return m_key;
}

Vertex* Vertex::GetNext() const
{
	return m_pNext;
}

int Vertex::Size() const
{
	return m_size;
}

void Vertex::AddEdge(int edgeKey, int weight) {
	Edge * newEdge = new Edge(edgeKey, weight);
	if (m_pEHead == NULL)
		m_pEHead = newEdge;
	else
	{
		Edge * lastEdge = m_pEHead;
		while (lastEdge->GetNext() != NULL)
		{
			lastEdge = lastEdge->GetNext();
		}
		lastEdge->SetNext(newEdge);
	}
	m_size++;
	return;
}

Edge* Vertex::GetHeadOfEdge() const
{
	return m_pEHead;
}

void Vertex::Clear()
{
	Edge * lastEdge = m_pEHead;
	while (lastEdge->GetNext() == NULL)
	{
		Edge * del = lastEdge;
		lastEdge = lastEdge->GetNext();
		delete del;
	}
	return;
}