
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */
 //#include "heap.h"
#include <cmath>

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    // @TODO Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the left child.

    return 2*currentIdx;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the right child.
    return 2*currentIdx+1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    // @TODO Update to return the index of the parent.
    return currentIdx/2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    // @TODO Update to return whether the given node has a child
    if(2*currentIdx<_elems.size()) return true;
    return false;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    if(2*currentIdx ==_elems.size()-1) return 2*currentIdx;
    if(_elems[leftChild(currentIdx)]<_elems[rightChild(currentIdx)]) return leftChild(currentIdx);
    return rightChild(currentIdx);
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    // @TODO Implement the heapifyDown algorithm.
    if (!hasAChild(currentIdx))
        return;
    size_t ChildIdx = maxPriorityChild(currentIdx);

    if (_elems[ChildIdx]< _elems[currentIdx]) {
        std::swap(_elems[ChildIdx], _elems[currentIdx]);
        heapifyDown(ChildIdx);
    }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    // @TODO Depending on your implementation, this function may or may
    ///   not need modifying

    T inf = std::numeric_limits<T>::min();
    _elems.push_back(inf);
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
    // @TODO Construct a heap using the buildHeap algorithm
  T inf = std::numeric_limits<T>::min();
    _elems.push_back(inf);
    _elems.insert(_elems.end(), elems.begin(), elems.end());
    for (size_t i = _elems.size()-1; i > 0; i--) heapifyDown(i);

}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    // @TODO Remove, and return, the element with highest priority
    T deleted=peek();
    std::swap(_elems[root()],_elems[_elems.size()-1]);
    _elems.pop_back();
    heapifyDown(root());
    return deleted;
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    // @TODO Return, but do not remove, the element with highest priority
    return _elems[root()];
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
_elems.push_back(elem);
  heapifyUp(_elems.size()-1);
    // @TODO Add elem to the heap
}

template <class T, class Compare>
void heap<T, Compare>::updateElem(const size_t & idx, const T& elem)
{
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
    _elems[idx]=elem;
    size_t ChildIdx = maxPriorityChild(idx);
    size_t parentIdx = parent(idx);
    if (higherPriority(elem, _elems[parentIdx])) heapifyUp(idx);
    if (higherPriority(_elems[ChildIdx], elem)) heapifyDown(idx);

}


template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    // @TODO Determine if the heap is empty
    return  (_elems.size() < =1);

}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
