#include<iostream>
using namespace std;

class Node
{
public:
    int info;
    Node * next;
};
class Stack
{
 private:
    Node * top;
 public:
    Stack()
    {
        top == NULL;
    }
    int empty()
    {
        if(top == NULL)
            return 1;
        else
            return 0;

    }
    void Push(int paased_value)
    {
        Node * temp;
        if(top == NULL)
        {
            top = new Node;
            top->info = passed_value;
            top->next = NULL;
        }
        else
        {
            temp = new Node;
            temp->info = passed_value;
            temp->next = top;
            top = temp;
        }
        cout << endl << passed_value << "Pushed" << endl;
    }
};
