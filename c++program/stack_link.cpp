#include<iostream>
using namespace std;
class Node
{
public:
    int info;
    Node *next;
};
class Stack
{
private:
    Node * top;
public:
    Stack()
    {
        top = NULL;
    }
    int Empty()
    {
        if(top == NULL)
            return 1;
        else
            return 0;
    }
    void Push(int passed_value)
    {
        Node * temp;
        if(top==NULL)
        {
            top = new Node;
            top->info = passed_value;
            top->next = NULL;
        }
        else
        {
            temp =  new Node;
            temp->info = passed_value;
            temp->next = top;
            top = temp;
        }
        cout << endl << passed_value << "Pushed" << endl;
    }
    int Pop()
    {
        Node *tmp;
        tmp = top;
        top = top->next;
        int x = tmp->info;
        delete(tmp);
        return (x);

    }
    void display()
    {
        if(top == NULL)
            cout << endl << "Stack is Empty" <<endl;
        else
        {
            Node *currentNode;
            cout << endl << "The content of the stack are:" <<endl;
            for(currentNode = top;currentNode!=NULL;currentNode=currentNode->next)
            {
                cout << currentNode->info<<"\n";
            }
        }
    }
};
int main()
{
    int choice,x;
    Stack mystack;
    while(1)
    {
        cout << "\n ***Stack Menu***\n\n";
        cout << "1. PUSH\n";
        cout << "2. POP\n";
        cout << "3.Display\n";
        cout << "4.Exit\n";
        cout << "Enter your choice:";
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter a number:";
            cin >> choice;
            mystack.Push(choice);
            break;

        case 2:
            if(mystack.Empty())
            {
                cout << endl << "Stack is Empty"<<endl;
                break;
            }
            x =  mystack.Pop();
            cout << endl << "The poped value is:"<<x <<endl;
            break;
        case 3:
            mystack.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "\n Invalid choice try again\n";
        }
    }
    return 0;
}
