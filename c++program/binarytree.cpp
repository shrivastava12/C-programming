#include<iostream>
#include<string.h>
using namespace std;
class Node
{
public:
    char info[50];
    Node * lchild;
    Node *rchild;
    Node(char i[20],Node*l,Node *r)
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
    Root =NULL; //Initializing the root node to null
}
void BinaryTree::Insert(char element[50])
{
    Node *temp,*parent,*currentNode;
    Find(element,&parent,&currentNode);
    if(currentNode!=NULL) //check if the node to be inserted is already present or not
    {
        cout<<"\n Duplicate word not allowed";
        return;
    }
    else //if the specified not is not present
    {
        temp = new Node(element,NULL,NULL);
        if(parent==NULL) //if the tree is empty
        {
            Root =temp;
        }
        else
        {
            if(strcmp(element,parent->info)<0)
                parent->lchild=temp;
            else
                parent->rchild=temp;
        }

    }
}
void BinaryTree :: Find(char element[50],Node **parent,Node **currentNode)
{
    /*This function finds a given element in the tree and returns a variable containing the address
    of the corresponding node.It also returns a variable containing the address of the parent of the node*/
    *currentNode = Root;
    *parent = NULL;
    while((*currentNode != NULL)&&(strcmp((*currentNode)->info,element)!=0))
    {
        *parent = *currentNode;
        if(strcmp(element,(*currentNode)->info)<0)
            *currentNode = (*currentNode)->lchild;
        else
            *currentNode = (*currentNode)->rchild;
    }
}
void BinaryTree ::inorder(Node *ptr) //Perform the inorder traversal of the tree
{
    if(Root == NULL)
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
void BinaryTree::preorder(Node *ptr) //Perform the preorder traversal of the tree
{
    if(Root == NULL)
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
void BinaryTree::postorder(Node *ptr) //Perform the postorder traversal of the tree
{
    if(Root==NULL)
    {
        cout<<"Tree is empty";
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
        cout<<"\n1. Implement insert operation"<<endl;
        cout<<"\n2. perform inorder traversal"<<endl;
        cout<<"\n3. perform preorder traversal"<<endl;
        cout<<"\n4. perform postorder traversal"<<endl;
        cout<<"\n5. Exit"<<endl;
        cout<<"Enter your choice(1-5):";
        cin>>ch;
        switch(ch)
        {
        case '1':
            {
            cout<<"\n Enter a word";
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
                cout<<"\n";
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
                cout<<"Invalid Option"<<endl;
                break;
            }
        }


    }
    return 0;
}
