#include<iostream>
#include<string.h>
using namespace std;
class Node
{
public:
    char info[50];
    Node *lchild;
    Node *rchild;
    Node(char i[20],Node *l,Node *r)
    {
        strcpy(info,i);
        lchild = l;
        rchild = r;
    }
};
class BinaryTree
{
public:
    Node *Root;
    BinaryTree();
    void Insert(char element[20]);
    void Find(char element[20],Node **parent,Node **location);
    void inorder(Node *ptr);
    void preorder(Node *ptr);
    void postorder(Node *ptr);
};
BinaryTree::BinaryTree()
{
    Root = NULL;
}
void BinaryTree::Insert(char element[50])
{
    Node *tmp,*parent,*currentNode;
    Find(element,&parent,&currentNode);
    if(currentNode!=NULL)//checks if the node to be inserted is already present or not
    {
        cout<<"\n Duplicate words not allowed";
        return;
    }
    else
    {
        tmp = new Node(element,NULL,NULL);
        if(parent==NULL)
            Root = NULL;
        else
            if(strcmp(element,parent->info)<0)
                parent->lchild=tmp;
            else
                parent->rchild=tmp;
    }
}
void BinaryTree::Find(char element[50],Node **parent,Node **currentNode)
{
    *currentNode = Root;
    *parent = NULL;
    while((*currentNode!=NULL)&&(strcmp((*currentNode)->info,element)!=0))
    {
        *parent = *currentNode;
        if(strcmp(element,(*currentNode)->info)<0)
            *currentNode = (*currentNode)->lchild;
        else
            *currentNode = (*currentNode)->rchild;
    }
}
void BinaryTree::inorder(Node *ptr) //performs the inorder traversal of the tree
{
    if(Root=NULL)
    {
        cout <<"Tree is empty";
        return;
    }
    if(ptr!=NULL)
    {
        inorder(ptr->lchild);
        cout<<ptr->info<<" ";
        inorder(ptr->rchild);
    }
}
void BinaryTree::preorder(Node *ptr)
{
    if(Root==NULL)
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
void BinaryTree::postorder(Node *ptr)
{
    if(Root==NULL)
    {
        cout <<"Tree is empty";
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
        cout<<"\nMenu";
        cout<<"\n1. Implemented insert operation"<<endl;
        cout<<"\2. perform inorder traversal"<<endl;
        cout<<"\3. perform preorder traversal"<<endl;
        cout<<"\4. perform postorder traversal"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"\n Enter your choice(1-5):";
        cin>>ch;
        switch(ch)
        {
        case '1':
            {
                cout<<"\nEnter a word:";
                cin>>word;
                b.Insert(word);
            }
            break;
        case '2':
            {
                cout<<"\n";
                b.inorder(b.Root);
                cout<<"\n";
            }
            break;
        case '3':
            {
                cout <<"\n";
                b.preorder(b.Root);
                cout<<"\n";
            }
            break;
        case '4':
            {
                cout<<"\n";
                b.postorder(b.Root);
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
}
