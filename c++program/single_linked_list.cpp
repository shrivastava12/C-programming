#include<iostream>
#include<string.h>
using namespace std;
class Node
{
public:
    int rollNumber;
    char name[20];
    Node *next;
};
class List
{
    Node *START;
public:
    List();
    void addNode();
    bool Search(int rollNo,Node **current,Node **previous);
    bool listEmpty();
    bool delNode(int element);
    void traverse();
};
List::List()
{
    START = NULL;

}
void List::addNode()
{
    int rollNo;
    char nm[20];
    cout << "\n Enter the roll number of student:";
    cin >>rollNo;
    cout << "\n Enter the name of the student:";
    cin >> nm;
    Node  *newnode = new Node;
    newnode->rollNumber = rollNo;
    strcpy(newnode->name,nm);


    //If the node to be inserted at the first node
    if(START == NULL || rollNo<=START->rollNumber)
    {
        if((START != NULL) && (rollNo == START->rollNumber))
        {
            cout << "\n Duplicate roll number are not allowed\n";
            return;
        }
        newnode->next = START;
        START=newnode;
        return;
    }
    Node *previous,*current;
    previous = START;
    current = START;
    while((current!=NULL) && (rollNo>=current->rollNumber))
    {
        if(rollNo == current->rollNumber)
        {
            cout << "\n Duplicate Roll number not allowed";
            return;
        }
        previous = current;
        current=current->next;

    }
    //once the preceding for loop  is executed ,previous and current are positioned in a such manner that the position for the new node is in between them

    newnode->next = current;
    previous->next = newnode;

}
bool List :: listEmpty()
{
    if(START == NULL)
    {
        return true;

    }
    else
    {
        return false;
    }
}
//delete the specific node from the list
bool List :: delNode(int rollNo)
{
    Node *current,*previous;
    if(Search(rollNo,&previous,&current)==false)
    {
        return true;
    }
    previous->next = current->next;
    if(current==START)
    {
        START = START->next;
    }

    delete current;
    return true;

}
bool List :: Search(int rollNo,Node **previous ,Node **current)
{
    *previous = START;
    *current = START;
    while((*current !=NULL) && (rollNo!=(*current)->rollNumber))
    {
        *previous = *current;
        *current = (*current)->next;

    }
    return (*current!=NULL);

}
void List :: traverse()
{
    if(listEmpty())
    {
        cout << "\n List is empty\n";
    }
    else
    {
        cout <<endl<<"The record in the list are:"<<endl;
        Node *currentNode;
        for(currentNode=START;currentNode!=NULL;currentNode=currentNode->next)
        {
            cout << currentNode->rollNumber<<""<<currentNode->name<<"\n";

        }
        cout<<endl;
    }
}
int main()
{
    List obj;
    int rollNo;
    char ch;
    while(1)
    {
        cout << endl<<"Menu";
        cout << endl<<"1. Add a record in the list:"<<endl;
        cout << endl <<"2. Delete a record from the list "<<endl;
        cout << endl<<"3.View all the record in the list"<<endl;
        cout << endl <<"4. Search all the record in the list"<<endl;
        cout << endl <<"5.Exit "<<endl;
        cout << endl <<"Enter your choice (1-5):";
        cin >>ch;
        switch(ch)
        {
        case '1':
            {
                obj.addNode();
            }


         break;
        case '2':
            {
                if(obj.listEmpty())
                {
                    cout << endl<<"List is empty"<<endl;
                    break;
                }
                cout << endl <<"\n Enter the roll number of student whose record is to be deleted";
                cin >> rollNo;
                if(obj.delNode(rollNo)==false)
                {
                    cout << endl << "Record is not found"<<endl;
                }
                else
                {
                    cout << endl << "Record with roll number "<<rollNo <<"deleted"<<endl;
                }
            }

            break;

            case  '3':
            {
                obj.traverse();
            }
            break;
            case '4':
                {
                    if(obj.listEmpty()==true)
                    {
                        cout <<"\n List is empty";
                        break;
                    }
                    Node *previous,*current;
                    cout <<endl<<"Enter the roll number of the student whose record is to be searched";
                    cin >> rollNo;
                    if(obj.Search(rollNo,&previous,&current)==false)
                    {
                        cout << endl<<"Record not found"<<endl;

                    }
                    else
                    {
                        cout << endl << "Record found" <<endl;
                        cout << "\n Roll Number:" <<current->rollNumber;
                        cout << "\n\n Name :"<<current->name;
                        cout << "\n";
                    }
                }
                break;
            case '5':
                {
                    exit(0);
                }
                break;
            default:
                {
                    cout << "Invalid option"<<endl;
                }
                break;
        }
    }

   return 0;

}
