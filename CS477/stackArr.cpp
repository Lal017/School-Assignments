#include <iostream>
using namespace std;

struct stack
{
    int stack_arr[10];
    int count;
    
    // Constructor
    stack(){ count = 0; }
};

// Push and Pop functions
void push(stack &s, int val)
{
    s.stack_arr[s.count] = val;
    s.count++;
}
int pop(stack &s)
{
    s.count--;
    int temp = s.stack_arr[s.count];
    s.stack_arr[s.count] = 0;
    return temp;
}
bool empty(stack &s)
{
    if(s.count == 0)
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