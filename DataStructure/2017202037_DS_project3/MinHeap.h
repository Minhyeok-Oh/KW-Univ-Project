#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <utility>
#include <vector>

template<typename TKey, typename TValue>
class MinHeap
{
private:
    // array for the elements which should be heap-sorted
    std::vector<std::pair<TKey, TValue>> m_vec;

public:
    MinHeap() {}

    /// <summary>
    /// insert key-value pair
    /// </summary>
    ///
    /// <param name="key">
    /// the key that is used for sorting
    /// </param>
    ///
    /// <param name="value">
    /// the value that is managed in this heap
    /// </param>
	void Push(TKey key, TValue value) {
		std::pair<TKey, TValue>a; // new element
		std::pair<TKey, TValue>finder; // place finder
		a.first = key;
		a.second = value;
		if (IsEmpty() == true) // if heap is empty, new element is head of heap.
		{
			m_vec.push_back(std::make_pair(-1, 0)); // m_vec[0] is not used.
			m_vec.push_back(a); // m_vec[1] is a
			return;
		}
		m_vec.push_back(a); // if heap isn't empty, new element is pushed at tail.
		finder = m_vec.back(); // finder starts at tail element
		int current = m_vec.size() - 1; // current is the last key of heap.
		while (current != 1 && m_vec.at(current / 2).second >= value) // if current is not the head and new element's value is smaller than parent
		{
			finder = a;
			std::pair<TKey, TValue> temp;
			temp = m_vec[current / 2];
			m_vec[current / 2] = a;
			m_vec[current] = temp; // swap parent and new element's place
			current = current / 2; // current goes up.
		}
		return;
	}
    /// <summary>
    /// remove the minimum element
    /// </summary>
	void Pop()
	{
		if (m_vec.size() == 0) // if heap is empty, return.
			return;
		std::pair<TKey, TValue> temp;
		temp = m_vec.back(); // temp is the last element of heap
		m_vec[1] = temp; // last element is the root of heap.
		m_vec.resize(m_vec.size() - 1); // heap size decreased
		Heapify(1); // reorder the heap.
	}
    /// <summary>
    /// get the minimum element
    /// </summary>
    ///
    /// <returns>
    /// the minimum element
    /// </returns>
	std::pair<TKey, TValue> Top() {
		return m_vec[1];
	}
    /// <summary>
    /// get the key-value pair which the value is the same as the target
    /// </summary>
    ///
    /// <returns>
    /// the key-value pair which the value is the same as the target
    /// </returns>
	std::pair<TKey, TValue> Get(TValue target)
	{
		for (int i = 0; i < m_vec.size(); i++)
		{
			if (m_vec[i].second == target)
				return m_vec[i];
		}
	}
    /// <summary>
    /// check whether this heap is empty or not
    /// </summary>
    ///
    /// <returns>
    /// true if this heap is empty
    /// </returns>
	bool IsEmpty()
	{
		if (m_vec.empty()) // if vector is empty, return true.
			return true;
		return false;
	}
    /// <summary>
    /// change the key of the node which the value is the target.<para/>
    /// In general, the newKey should be smaller than the old key.<para/>
    /// </summary>
    ///
    /// <parma name="target">
    /// the target to change the key
    /// </param>
    ///
    /// <param name="newKey">
    /// new key for the target
    /// </param>
	void DecKey(TValue target, TKey newKey) {}

private:
    /// <summary>
    /// heap-sort, heapify.<para/>
    /// this function can be called recursively
    /// </summary>
	void Heapify(int index)
	{
		int i = index * 2; // i is the left child of index
		int r = index * 2 + 1; // r is right child of index
		int smallest = index; // the smallest key in heap
		if (i < m_vec.size() && m_vec[i] < m_vec[index])smallest = i; // compare i'th node and index'th node, smallest updated
		if (r < m_vec.size() && m_vec[r] < m_vec[smallest])smallest = r; // compare r'th node and index'th node, smallest updated.
		if (smallest != index) // if smallest changed,
		{
			std::swap(m_vec[smallest], m_vec[index]); // swap two nodes in heap
			Heapify(smallest); // recursive heapify
		}
		return;
	}
};

#endif
