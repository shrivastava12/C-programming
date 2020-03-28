#include<stdio.h>
#include<stdlib.h>
struct node
{
    int key;
    struct node *left,*right;
};

//A utility function to create a new bst

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
};

//A utility function to do inorder traversal of BST

void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d\n",root->key);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{

    if(root != NULL)
    {

        postorder(root->left);
        postorder(root->right);
        printf("%d\n",root->key);
    }
}
void preorder(struct node *root)
{

    if(root != NULL)
    {
        printf("%d\n",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

//A utility function to insert a new node with given key in bst
struct node* insert(struct node* node,int key)
{
    //if the tree is empty return a new node
    if(node == NULL)
        return newNode(key);

    //Otherwise recur down the tree

    if(key < node->key)
        node->left = insert(node->left,key);
    else if(key > node->key)
        node->right = insert(node->right,key);

    //return the unchanged node pointer

    return node;

};
//Given a non-empty binary search  tree,return the node with minimum key value found in that tree

struct node *minValueNode(struct node* node)
{
    struct node* current = node;

    //loop to found leftmost tree
    while(current && current->left != NULL)
        current = current->left;
    return current;
};

//Given a binary search tree and a key ,This function deletes the key and return the new root
struct node* deleteNode(struct node* root,int key)
{
    //base case

    if(root == NULL)
        return root;
    //If the key to be deleted is smaller than the roots key,
    //Then is lies in left subtree
    if(key < root->key)
        root->left = deleteNode(root->left,key);
    //If the key to be deleted is greater than the roots key
    //then it lies in right subtree

    else if(key > root->key)
        root->right = deleteNode(root->right,key);

    //If key is same as root's key,then this is the node
    //to be deleted

    else
    {
        //node with only one child or no child
        if(root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        //node with two children
        //Get the inorder successor(smallest in the right subtree)

        struct node* temp = minValueNode(root->right);
        //copy the inorder successor's content to this code
        root->key =  temp->key;
        //Delete the inorder successor
        root->right = deleteNode(root->right,temp->key);

    }
    return root;

};
int main()
{
    struct node *root = NULL;
    root = insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    //Print inorder traversal of the Bst

    inorder(root);
    printf("Preorder traversal\n");
    preorder(root);
    printf("Post order traversal\n");
    postorder(root);
    printf("\n Delete 20 \n");
    root =  deleteNode(root,20);
    printf("Inorder traversal of the modified tree\n");
    inorder(root);

    return 0;
}
