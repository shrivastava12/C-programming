#include<iostream>
using namespace std;
class Stack
{
private:
    int stack_array[5];
    int top;
public:
    Stack()
    {
        top = -1;
    }
    int full()
    {
        if(top==4)
            return 1;
        else
            return 0;
    }
    int Empty()
    {
        if(top==-1)
            return 1;
        else
            return 0;

    }
    void Push(int passed_value)
    {
        top++;
        stack_array[top] = passed_value;
        cout << endl << passed_value << "Pushed"<<endl;
    }
    void pop()
    {
        cout << "\n The topped value is "<<stack_array[top]<<"\n";
        top--;
    }
    void display()
    {
        if(Empty())
        {
            cout << endl << "Stack is empty"<<endl;
        }
        else
        {
            cout << endl <<"\n The content of the stack are:\n"<<endl;
            for(int i=top;i>=0;i--)
            {
                cout << stack_array[i]<<"\n";
            }
        }
    }

};
int main()
{
    int choice;
    Stack mystack;
    while(1)
    {
        cout << "\n\n Stack menu\n\n";
        cout << "1. Push\n";
        cout << "2.Pop\n";
        cout << "3. Display\n";
        cout <<"4.Exit\n";
        cout <<"\n Enter your choice";
        cin >> choice;
        switch(choice)
        {
        case 1:
            if(mystack.full())
            {
                cout << "\n Stack is full";
                break;
            }
            cout << "\n Enter your number";
            cin >> choice;
            mystack.Push(choice);
            break;
        case 2:
            if(mystack.Empty())
            {
                cout << "My stack is empty";
                break;
            }
            mystack.pop();
            break;
        case 3:
            mystack.display();
            break;
        case 4:
            exit(0);
        default:
            cout << "\n Invalid choice .try again\n";

        }
    }
    return 0;
}
