#include<iostream>
#include<string.h>
using namespace std;

class Node
{
public:
    int rollNumber;
    char name[20];
    Node * next;
    Node * pre;
};
class doubleLinkedlist
{
    Node *START;
public:
    doubleLinkedlist();
    void addNode();
    bool Search(int rollNo,Node **previous,Node **current);
    bool listEmpty();
    bool traverse();
    bool retraverse();


};

doubleLinkedlist :: doubleLinkedlist()
{
    START = NULL;
}
void doubleLinkedlist ::  addNode()
{
    int rollNo;
    char nm[20];
    cout << "Enter the roll Number of the student\n";
    cin >> rollNo;
    cout << "\n Enter the name of the student\n";
    cin >> nm;
    Node *newNode = new Node;
    newNode->rollNumber = rollNo;
    strcpy(newNode->name,nm);


    if(listEmpty())
    {

        newNode->next = NULL;
        newNode->pre =  NULL;
        START = newNode;
        return;
    }
    else
    {
        //if node to be inserted at the beginning of the list


        newNode->next = START;
        START->pre = newNode;
        newNode->pre = NULL;
        START =  newNode;

    }

}

bool doubleLinkedlist :: Search(int rollNo,Node **previous,Node **current)
{
    *previous = START;
    *current = START;
    while((*current!=NULL) && rollNo != (*current)->rollNumber)
    {
        *previous = *current;
        *current = (*current)->next;
    }
    return (*current!=NULL);
}

bool doubleLinkedlist :: listEmpty()
{
    if(START == NULL)
        return true;
    else
        return false;

}
bool doubleLinkedlist :: traverse()
{
    if(listEmpty())
    {
        cout << "\n List is empty\n";
    }
    else
    {
        cout << "Record in the acceding order of roll Numbers are:\n"<<endl;
        Node *currentNode;
        currentNode = START;
        while(currentNode != NULL)
        {
            cout << currentNode->rollNumber<<endl;
            cout << currentNode->name<<endl;

            currentNode=currentNode->next;
        }

    }
}
bool doubleLinkedlist :: retraverse()
{
    if(listEmpty())
    {
        cout << "List is Empty\n";
    }
    else
    {
        cout << "Record in the descending order of the list are: \n"<<endl;
        Node *currentNode;
        currentNode = START;
        while(currentNode->next!=NULL)
        {
            currentNode =  currentNode->next;
        }
        while(currentNode!= NULL)
        {
            cout << currentNode->rollNumber << " " <<currentNode->name << "\n";
            currentNode = currentNode->pre;
        }
    }
}
int main()
{
    doubleLinkedlist obj;
    int rollNo;
    char ch;
    while(1)
    {
        cout << endl << "Menu";

        cout << "\n1. View all record in the ascending order of roll numbers" << endl;
        cout << "\n2. View all record in the descending order of roll number" << endl;
        cout << "\n3. Search for a record in the list" <<endl;
        cout << "\n4. Insert data into node:" <<endl;
        cout << "\n5. Exit" <<endl;
        cout << "Enter your choice(1-5):"<< endl;
        cin >> ch;
        switch(ch)
        {
        case '1':
            {
                obj.traverse();
            }
            break;
        case '2':
            {
                obj.retraverse();
            }
            break;
        case '3':
            {
                if(obj.listEmpty() == true)
                {
                    cout << "List is empty\n";
                    break;
                }
                Node *pre,*current;
                cout << "Enter the roll number of the student whose record you want to search:";
                cin >>rollNo;
                if(obj.Search(rollNo,&pre,&current) == false)
                    cout <<"\n Record not found\n";
                else
                {
                    cout << "\n Record found "<<endl;
                    cout << "\n Roll number" <<current->rollNumber;
                    cout << "\n\n Name" <<current->name;
                    cout <<"\n";

                }
                break;

            }
        case '5':
            {
                exit(0);
            }
            break;
        case '4':
            {
                cout << "Enter data to insert:"<<endl;
                obj.addNode();
                break;
            }
        default:
            {
                cout << "\n invalid option\n";
            }
            break;
        }
    }
    return 0;
}
