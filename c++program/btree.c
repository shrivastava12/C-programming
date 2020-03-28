#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *left,*right;
};
struct node *newnode(int item)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
};
//A utility function to traverse the tree

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\n",root->key);
        inorder(root->right);
    }
}
//A utility function to insert a new node with a given key value

struct node *insert(struct node *node,int key)
{
    //If the node to be empty return a new node
    if(node == NULL)
        printf("node is empty");
    //down the tree
    if(key<node->key)
        node->left = insert(node->left,key);
    else
        node->right = insert(node->right,key);
    return node;
};
int main()
{
    struct node *root = NULL;
    root = insert(root,40);
    insert(root,59);
    inorder(root);
    return 0;
}
