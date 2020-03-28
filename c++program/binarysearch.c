#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *left,*right;
};
//A utility function to create a new bst Node
struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node))
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
};
//A utility function to do traversal of BST
void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\",root->key);
        inorder(root->right);
    }
}
//A utility function to insert a new node with given key in bst
struct node* insert(struct node*,int key)
{
    if(node == NULL)
        return newNode
};
