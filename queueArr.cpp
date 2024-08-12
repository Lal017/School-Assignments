#include <iostream>
using namespace std;

struct queue
{
    int queue_arr[10];
    int count, offset;
    
    queue(){ count = 0; offset = 0; }
};

void enqueue(queue &q, int val)
{
    int start = q.count + q.offset % 10;
    q.queue_arr[start] = val;
    q.count++;   
}

int dequeue(queue &q)
{
    int ret = q.queue_arr[q.offset];
    q.queue_arr[q.offset] = 0;
    if(q.offset != 9)
        q.offset++;
    else
        q.offset = 0;
    q.count--;
    return ret;
}

bool empty(queue &q)
{
    if(q.count == 0)
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