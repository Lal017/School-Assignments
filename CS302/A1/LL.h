#include <cstddef>
template <typename T>
class LL 
{
    //contents of each node
    struct node 
    {
        T data;
        node* prev;
        node* next;
    };
    //iterator class to allow access of each node in main
   public:
    class Iterator 
    {
       public:
        friend class LL;
        Iterator();
        Iterator(node*);
        T operator*() const;
        Iterator operator++(int);
        Iterator operator++();
        Iterator operator--(int);
        Iterator operator--();
        bool operator==(const Iterator&) const;
        bool operator!=(const Iterator&) const;

       private:
        node* current;
    };

    LL();
    LL(const LL<T>&);
    const LL<T>& operator=(const LL<T>&);
    ~LL();
    void headInsert(const T&);
    void tailInsert(const T&);
    void headRemove();
    bool isEmpty() const;
    std::size_t size() const;
    Iterator begin() const;
    Iterator end() const;

   private:
    node * portal;
};

//iterator class implementation
template <typename T>
LL<T>::Iterator::Iterator() 
{
    current = nullptr;
}

template <typename T>
LL<T>::Iterator::Iterator(node* ptr) 
{
    current = ptr;
}

template <typename T>
T LL<T>::Iterator::operator*() const 
{
    return current->data;
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator++(int) 
{
   this->current = this->current->next;
   return this->current;
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator++() 
{
    this->current = this->current->next;
    return this->current->prev;
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator--(int) 
{
    this->current = this->current->prev;
    return this->current;
}

template <typename T>
typename LL<T>::Iterator LL<T>::Iterator::operator--() 
{
    this->current = this->current->prev;
    return this->current->next;
}

template <typename T>
bool LL<T>::Iterator::operator==(const Iterator& rhs) const 
{
    if(current == rhs.current)
        return true;
    
    return false;
}

template <typename T>
bool LL<T>::Iterator::operator!=(const Iterator& rhs) const 
{
    if(current == rhs.current)
        return false;

    return true;
}

//Linked list class implementation
template <typename T>
LL<T>::LL() 
{
    portal = new node;
    portal->next = portal;
    portal->prev = portal;
}

//copy constructor
template <typename T>
LL<T>::LL(const LL<T>& copy) 
{
    portal = new node;
    portal->next = portal;
    portal->prev = portal;
    node* next = copy.portal->next;
    while(next != copy.portal){
        tailInsert(next->data);
        next = next->next;
    }
}

template <typename T>
const LL<T>& LL<T>::operator=(const LL<T>& rhs) 
{
    node* temp = portal->next;
    while(temp != portal){
        node* next = temp->next;
        delete temp;
        temp = next;
    }
    delete portal;
    portal = new node;
    portal->next = portal;
    portal->prev = portal;
    node* next = rhs.portal->next;
    while(next != rhs.portal){
        this->tailInsert(next->data);
        next = next->next;
    }

    return *this;
}

//destructor
template <typename T>
LL<T>::~LL() 
{
    node* temp = portal->next;
    while(temp != portal){
        node* next = temp->next;
        delete temp;
        temp = next;
    }
    delete portal;
}

//head insert
template <typename T>
void LL<T>::headInsert(const T& item) 
{
    node* new_Node = new node;
    new_Node->data = item;

    if(portal->next == portal)
    {
        new_Node->prev = portal;
        new_Node->next = portal;
        portal->prev = new_Node;
        portal->next = new_Node;
    }
    else
    {
        node* head_node = portal->next; //a head node
        head_node->prev = new_Node; // portal=temp;
        portal->next = new_Node;
        new_Node->next = head_node;
        new_Node->prev = portal;
    }
}

//tail insert
template <typename T>
void LL<T>::tailInsert(const T& item) 
{
    node* new_Node = new node;
    new_Node->data = item;

    if(portal->next==portal)
    {
        new_Node->prev = portal;
        new_Node->next = portal;
        portal->prev = new_Node;
        portal->next = new_Node;
    }
    else
    {
        node* prev_node = portal->prev;
        portal->prev = new_Node;
        new_Node->prev = prev_node;
        new_Node->next = portal;
        prev_node->next = new_Node;
    }
}

template <typename T>
void LL<T>::headRemove()
{
    if(!isEmpty()){
        node* temp = portal->next;
        portal->next = temp->next;
        temp->next->prev = portal;
        temp->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }
} 

template <typename T>
bool LL<T>::isEmpty() const
{
    if(portal->next == portal)
        return true;

    return false;
}

template <typename T>
std::size_t LL<T>::size() const
{
    std::size_t count = 0;
    node* temp = portal->next;
    while(temp != portal){
        count++;
        temp = temp->next;
    }
    return count;
}

template <typename T>
typename LL<T>::Iterator LL<T>::begin() const 
{
    return Iterator(portal->next);
}

template <typename T>
typename LL<T>::Iterator LL<T>::end() const 
{
    return Iterator(portal);
}

