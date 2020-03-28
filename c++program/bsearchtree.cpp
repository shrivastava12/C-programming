#include<iostream>
#include<string.h>
using namespace std;
class Node
{
public:

    char info[50];
    Node *lchild;
    Node *rchild;
    Node(char i[20],Node *l,Node *r) //Constructor for the node class
    {
        strcpy(info,i);
        lchild = l;
        rchild = r;
    }
};
class BinaryTree
{
public:
    Node *ROOT;
    BinaryTree();
    void insert(char element[20]);
    void find(char element[20],Node **parent,Node **location);
    void inorder(Node *ptr);
    void preorder(Node *ptr);
    void postorder(Node *ptr);
};
BinaryTree::BinaryTree()
{
    ROOT = NULL;
}
void BinaryTree::insert(char element[50])
{
    Node *tmp,*parent,*currentNode;
    find(element,&parent,&currentNode);
    if(currentNode!=NULL)
    {
        cout<<"Duplicate words not allowed";
        return;
    }
    else
    {
        tmp = new Node(element,NULL,NULL);
        if(parent == NULL)
        {
            ROOT =tmp;
        }
        else
        {
            if(strcmp(element,parent->info)<0)
                parent->lchild=tmp;
            else
                parent->rchild=tmp;

        }
    }
}

void BinaryTree::find(char element[50],Node **parent,Node **currentNode)
{
    *currentNode = ROOT;
    *parent = NULL;
    while((*currentNode != NULL) &&(strcmp((*currentNode)->info,element)!=0))
    {
        *parent = *currentNode;
        if(strcmp(element,(*currentNode)->info)<0)
            *currentNode = (*currentNode)->lchild;
        else
            *currentNode = (*currentNode)->rchild;
    }
}
void BinaryTree :: inorder(Node *ptr) //Perform the inorder traversal of the tree
{
    if(ROOT == NULL)
    {
        cout<<"Tree is empty";
        return;
    }
    if(ptr!=NULL)
    {
        inorder(ptr->lchild);
        cout<<ptr->info<<" ";
        inorder(ptr->rchild);
    }

}
void BinaryTree ::preorder(Node *ptr) //perform the preorder traversal of the tree
{
    if(ROOT==NULL)
    {
        cout<<"Tree is empty";
        return;
    }
    if(ptr!=NULL)
    {
        cout<<ptr->info<<" ";
        preorder(ptr->lchild);
        preorder(ptr->rchild);
    }

}
void BinaryTree::postorder(Node *ptr) //Perform the Postorder traversal of the tree
{
    if(ROOT==NULL)
    {
        cout<<"Tree is empty";
        return;
    }
    if(ptr!=NULL)
    {
        postorder(ptr->lchild);
        postorder(ptr->rchild);
        cout<<ptr->info<<" ";
    }

}
int main()
{
    BinaryTree b;
    char ch,word[50];
    int num;
    while(1)
    {
        cout<<"\Menu";
        cout<<"\n1. implement insert operation"<<endl;
        cout<<"\n2. perform inorder traversal"<<endl;
        cout<<"\n3. perform preorder traversal"<<endl;
        cout<<"\n4. perform postorder traversal"<<endl;
        cout<<"Exit"<<endl;

        cout<<"Enter your choice(1-5):";
        cin>>ch;
        switch(ch)
        {
        case '1':
            {
                cout<<"\nEnter a word:";
                cin>>word;
                b.insert(word);
            }
            break;
        case '2':
            {
                cout<<"\n";
                b.inorder(b.ROOT);
                cout <<"\n";
            }
            break;
        case '3':
            {
                cout<<"\n";
                b.preorder(b.ROOT);
                cout<<"\n";
            }
            break;
        case '4':
            {
                cout<<"\n";
                b.postorder(b.ROOT);
                cout<<"\n";
            }
            break;
        case '5':
            {
                exit(0);
            }
            break;
        default:
            {
                cout<<"Invalid option"<<endl;
                break;
            }
        }
    }
    return 0;
}
