#include<iostream>
using namespace std;
class Stack
{
public:
    char stack_array[50];
    int top;
    Stack()
    {
        top = -1;
    }
    void Push(char symbol)
    {
        if(full())
        {
            cout << "\n stack overflow"<<endl;
        }
        else
        {
            top = top+1;
            stack_array[top] = symbol;
        }
    }
    char Pop()
    {
        if(empty())
            return ("#");
        else
            return (stack_array[top--]);


    }
    int empty()
    {
        if(top == -1)
            return 1;
        else
            return 0;
    }
    int full()
    {
        if(top == 49)
            return 1;
        else
            return -1;
    }
};
