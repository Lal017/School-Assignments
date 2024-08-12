#include <iostream>
using namespace std;

struct queue
{
    struct node
    {
        int val;
        node *next, *prev;
    };

    node *first_node, *last_node;

    queue()
    {
        first_node = new node();
        first_node->next = NULL;
        first_node->val = 0;
        last_node = first_node;
    }
};

void enqueue(queue &q, int a)
{
    queue::node *new_node = new queue::node();
    new_node->val = a;
    new_node->next = NULL;
    new_node->prev = q.last_node;
    q.last_node->next = new_node;
    q.last_node = new_node;
}

int dequeue(queue &q)
{
    queue::node *temp = new queue::node();
    temp = q.first_node->next;
    int ret = q.first_node->next->val;
    q.first_node->next = q.first_node->next->next;
    q.first_node->next->prev = q.first_node;
    delete temp;
    return ret;
}

bool empty(queue &q)
{
    if(q.first_node->next == NULL)
        return true;
    return false;
}

int main()
{
    queue q;

    enqueue(q, 5);
    enqueue(q, 7);
    enqueue(q, -3);
    cout << dequeue(q) << endl;
    enqueue(q, 9);
    while(!empty(q))
        cout << dequeue(q) << endl;

    return 0;
}