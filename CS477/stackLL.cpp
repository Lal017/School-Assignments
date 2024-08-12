#include <iostream>
using namespace std;

struct stack
{
    struct node
    {
        int val;
        node *next, *prev;
    };

    node *first_node, *last_node;
    
    stack()
    {
        first_node = new node();
        first_node->next = NULL;
        first_node->val = 0;
        last_node = first_node;
    }
};

void push(stack &s, int a)
{
    stack::node *new_node = new stack::node();
    new_node->val = a;
    new_node->next = NULL;
    new_node->prev = s.last_node;
    s.last_node->next = new_node;
    s.last_node = new_node;
}

int pop(stack &s)
{
    int ret = s.last_node->val;
    s.last_node = s.last_node->prev;
    delete s.last_node->next;
    s.last_node->next = NULL;

    return ret;
}

bool empty(stack &s)
{
    if(s.first_node->next == NULL)
        return true;
    return false;
}

int main()
{
    stack s;

    push(s, 5);
    push(s, 7);
    push(s, -3);
    cout << pop(s) << endl;
    push(s, 9);
    while (!empty(s))
        cout << pop(s) << endl;
    
    return 0;
}