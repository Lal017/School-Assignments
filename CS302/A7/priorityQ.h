#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

template <class t1, class t2>
class priorityQ
{
public:
    priorityQ();
    void push_back(const t1&, const t2&);
    void pop_front();
    void increaseKey(const t1&, const t2&);
    t2 get_front_priority() const;
    t1 get_front_key() const;
    bool isEmpty() const;
private:
    struct priorityType
    {
        priorityType(t1 key, t2 priority)
        {
            this->key = key;
            this->priority = priority;
        }

        t1 key;
        t2 priority;
    };

    void bubbleUp(size_t);
    void bubbleDown(size_t);

    vector<priorityType> heapArray;
    unordered_map<t1, size_t> itemToPQ;
};

template <class t1, class t2>
priorityQ<t1, t2>::priorityQ()
{

}

template <class t1, class t2>
void priorityQ<t1, t2>::push_back(const t1& key, const t2& value)
{
    priorityType temp(key, value);
    heapArray.push_back(temp);
    bubbleUp(heapArray.size() - 1);
}

template <class t1, class t2>
void priorityQ<t1, t2>::pop_front()
{
    swap(heapArray[0], heapArray[heapArray.size()-1]);                          // swap root and last index
    itemToPQ.erase(heapArray[heapArray.size()-1].key);
    heapArray.pop_back();                                                       // delete last index
    itemToPQ[heapArray[0].key] = 0;                                             // update unordered map
    bubbleDown(0);                                                              // percolate down
}

template <class t1, class t2>
void priorityQ<t1, t2>::increaseKey(const t1& key, const t2& value)
{
    heapArray[itemToPQ[key]].priority += value;
    bubbleUp(itemToPQ[key]);
}

template <class t1, class t2>
t2 priorityQ<t1, t2>::get_front_priority() const
{
    return heapArray[0].priority;
}

template <class t1, class t2>
t1 priorityQ<t1, t2>::get_front_key() const
{
    return heapArray[0].key;
}

template <class t1, class t2>
bool priorityQ<t1, t2>::isEmpty() const
{
    if(heapArray.size() == 0)
        return true;
    
    return false;
}

template <class t1, class t2>
void priorityQ<t1, t2>::bubbleUp(size_t index)
{    
    size_t parent;

    while(index > 0)
    {
        parent = floor((index-1) / 2);                                                      // computes parent index

        if(heapArray[index].priority > heapArray[parent].priority)
        {
            swap(heapArray[index], heapArray[parent]);
            itemToPQ[heapArray[index].key] = index;
            itemToPQ[heapArray[parent].key] = parent;
            index = parent;
        }
        else
            break;
    }
    itemToPQ[heapArray[index].key] = index;
}

template <class t1, class t2>
void priorityQ<t1, t2>::bubbleDown(size_t index)
{
    size_t left_child, right_child, compare;

    while(index < heapArray.size())
    {
        left_child = index * 2 + 1;
        right_child = index * 2 + 2;

        if(heapArray.size() == 2)
        {
            if(heapArray[1].priority > heapArray[0].priority)
                swap(heapArray[0],heapArray[1]);                                            // swap if child is larger
            break;
        }
        if(left_child >= heapArray.size() || right_child >= heapArray.size())
            break;

        if(heapArray[left_child].priority > heapArray[right_child].priority)                // if left child is larger
            compare = left_child;
        else                                                                                // if right child is larger
            compare = right_child;

        if(heapArray[compare].priority > heapArray[index].priority)                         // if child is larger
        {
            swap(heapArray[index], heapArray[compare]);
            itemToPQ[heapArray[index].key] = index;
            itemToPQ[heapArray[compare].key] = compare;
            index = compare;
        }
        else
            break;
    }
}