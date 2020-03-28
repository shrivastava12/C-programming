#include<iostream>
using namespace std;
class Stack{
    int stack1[5];
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
    int empty()
    {
        if(top==-1)
            return 1;
        else
            return 0;
    }
    void Push(int passed_value)
    {
        top++;
        stack1[top] = passed_value;
        cout<<endl<<passed_value<<"Pushed"<<endl;
    }
    void pop()
    {
        cout<<"\n The popped value is"<<stack1[top]<<"\n";
        top--;
    }
    void display()
    {
        if (empty())
            cout<<endl<<"Stack empty"<<endl;
        else
        {
            cout<<endl<<"\n The content of the stack are:\n"<<endl;
            for(int i=top;i>=0;i--)
                cout<<stack1[i]<<"\n";
        }
    }
};
int main()
{
    int choice;
    Stack mystack;
    while(1)
    {
        cout<<"\n\n ********Stack menu********";
        cout<<"1. Push\n";
        cout<<"2. Pop\n";
        cout<<"3. Display\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice:";
        cin>>choice;
        switch(choice)
        {
        case 1:
            if(mystack.full())
            {
                cout<<"Stack is full"<<endl;
                break;
            }
            cout<<"\n Enter a number";
            cin>>choice;
            mystack.Push(choice);
            break;
        case 2:
            if(mystack.empty())
            {
                cout<<"\nStack is empty";
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
            cout<<"\n Invalid choice.try again\n";
        }


    }
    return 0;
}
