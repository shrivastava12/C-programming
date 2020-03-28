#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(int value,Node *l,Node *r)
    {
        data = value;
        lchild = l;
        rchild = r;
    }
    //constructor for the node class
};
class BinaryTree
{
public:
    Node *Root;
    BinaryTree();
    void insert(int element);
    void find(int element,Node **parent,Node **location);
    void inorder(Node *ptr);
    void preorder(Node *ptr);
    void postorder(Node *ptr);

};
BinaryTree::BinaryTree()
{
    Root = NULL;
}
void BinaryTree::insert(int element) //insert a node in the binary search tree
{
    Node *tmp,*currentNode,*parent;
    find(element,&parent,&currentNode);
    if(currentNode!=NULL)
    {
        cout<<"\nduplicate entry not allowed ";
        return;
    }
    else //if the specific node is not present in the tree
    {
        tmp = new Node(element,NULL,NULL);
        if(parent==NULL)
            Root = tmp;
        else
            if(element<parent->data)
            {
                parent->lchild = tmp;
            }
            else
            {
                parent->rchild = tmp;
            }
    }

}
void BinaryTree::find(int element,Node **parent,Node **currentNode)
{
    *currentNode = Root;
    *parent = NULL;
    while((*currentNode != NULL) && ((*currentNode->data) != element))
    {
        *parent = *currentNode;
        if(element<*currentNode->data)
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
        cout<<ptr->data<<" ";
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
        cout<<ptr->data<<" ";
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
        cout<<ptr->data<<" ";
    }
}
int main()
{
    BinaryTree b;
    char ch;
    int word;
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
