#ifndef STACK_H
#define STACK_H

#ifndef NULL
#define NULL    0
#endif

template <typename T>
class Stack
{
private:
    class StackNode
    {
    public:
        T Data;
        StackNode* pNext;

        StackNode(T data) : Data(data), pNext(NULL) {}
    };

private:
    // the head pointer of the stack
    StackNode* m_pTop;

public:
	Stack()
	{
		m_pTop = NULL;
	}
	~Stack()
	{
		StackNode* finder = m_pTop;
		while (finder)
		{
			StackNode* deleter = finder;
			finder = finder->pNext;
			deleter->pNext = NULL;
			delete deleter; // delete all nodes in stack
		}
	}

    /// <summary>
    /// push the data into this stack
    /// </summary>
    ///
    /// <param name="data">
    /// a data to push into this stack
    /// </param>
	void Push(T data)
	{
		StackNode* newdata = new StackNode(data); // new StackNode newdata is created
		newdata->Data = data;
		newdata->pNext = m_pTop; // original Top element is next of newdata
		m_pTop = newdata; // newdata is top element

	}
    /// <summary>
    /// pop(remove) the last-in data from this stack
    /// </summary>
	void Pop() {
		StackNode* popper = m_pTop;
		m_pTop = m_pTop->pNext; // top element is next element of top element
		delete popper; // delete original top element
	}
    /// <summary>
    /// get the last-in data of this stack
    /// </summary>
    /// 
    /// <returns>
    /// the last-in data of this stack
    /// </returns>
	T Top()
	{
		return m_pTop->Data;
	}
    /// <summary>
    /// check whether this stack is empty or not.
    /// </summary>
    ///
    /// <returns>
    /// true if this stack is empty.
    /// false otherwise.
    /// </returns>
	bool IsEmpty()
	{
		if (m_pTop == NULL) // if top is NULL, stack is empty.
			return true;
		else
			return false;
	}
};

#endif
