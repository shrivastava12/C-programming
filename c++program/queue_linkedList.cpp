#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class QueueLink
{
    Node *FRONT,REAR;
public:
    QueueLink()
    {
        FRONT = Null;
        REAR = Null;
    }
    void Insert(int element){}
    void Remove()
    {

    }
    void Display(){}
};
void QueueLink :: Insert(int element)
{
    Node *newnode = new Node;
    newnode->data = element;
    newnode->next = NULL;
    if(FRONT == NULL)
    {
        FRONT = newnode;
        REAR =  newnode;
    }
    REAR->next = newnode;
    REAR = newnode;
    REAR->next = NULL;
}
void QueueLink :: Remove()
{
    Node *current new Node;
    if(FRONT == NULL)
    {
        cout << "Queue is Empty" <<endl;
    }
    current = FRONT;
    FRONT = FRONT->next;
    delete(current);
}
void QueueLink :: Display()
{
    Node *temp = new Node;
    if((FRONT == NULL) && (REAR == NULL))
    {
        cout << "Queue is Empty" <<endl;
        return;
    }
    cout << "Queue element is :"
    while(temp!=NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    QueueLink obj;
    int num;
    char ch;
    while(1){

    cout << "Menu\n";
    cout <<" 1. Insert element"<<endl;
    cout <<" 2. Delete element" <<endl;
    cout <<" 3. Display "<<endl;
    cout <<" 4. Exit "<<endl;
    cout << "Select option form (1-4)";
    cin >>ch<<endl;
    switch(ch)
    {
    case '1':
        cout << "Enter element to insert: ";
        cin >> num;
        obj.Insert(num);
        break;
    case '2':
        obj.Delete();
        break;
    case '3':
        obj.Display();
        break;
    case '4':
        exit(0);
        break;
    default:
        cout << "Invalid option"
    }
    }
    return 0;
}
