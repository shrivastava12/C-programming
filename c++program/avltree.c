// c program to insert a node in AVL Tree
#include<stdio.h>
#include<stdlib.h>

//An AVL tree node

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
//A utility function to get maximum of two integers

int max(int a,int b);

//A utility  function to get maximum of two elements
int height(struct Node *N)
{
    if(N == NULL)
        return 0;
    return N->height;
}

//A utility function to get  maximum of two integer
int max(int a,int b)
{
    return (a>b)?a:b;
}

struct Node* newNode(int key)
{
       struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height= 1;
    return(node);
};

//A utility function to right subtree rooted with y
struct Node* rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    //Perform rotation
    x->right = y;
    y->left = T2;
    //Update the heights

    y->height = max(height(y->left),height(y->right))+1;
    x->height = max(height(x->left),height(y->right))+1;
    //Return new root

    return x;
};
//A utility function to left rotate subtree rooted with x

struct Node *leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    //Perform rotation
    y->left = x;
    x->right = T2;
    //Update heights

    x->height = max(height(x->left),height(x->right))+1;
    y->height = max(height(y->left),height(y->right))+1;

//Return new root
    return y;
};
//Get balance factor of Node N
int getBalance(struct Node *N)
{
    if(N==NULL)
        return 0;
    return height(N->left)-height(N->right);
}
//Recursive function to insert a key in the subtree rooted
//with Node and return the new root of the subtree

struct Node* insert(struct Node* node,int key)
{
    //Perform normal bst insertion
    if(node == NULL)
        return(newNode(key));
    if(key<node->key)
        node->left =  insert(node->left,key);
    else if(key>node->key)
        node->right = insert(node->right,key);
    else
        return node;
    //Update height of this ancestor node
    node->height = 1+ max(height(node->left),height(node->right));

    //Balance factor of this node
    int balance = getBalance(node);
    //If node is not balance then
    //there are 4 case
    //left left case
    if(balance>1 && key<node->left->key)
        return rightRotate(node);

    //Right right case
    if(balance<-1&&key>node->right->key)
        return leftRotate(node);

    //Left Right case
    if (balance > 1 && key > node->left->key)
    {
        node->left =  leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    /* return the (unchanged) node pointer */
    return node;


}
// A utility function to print preorder traversal
// of the tree.
// The function also prints height of every node
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

/* Drier program to test above function*/
int main()
{
  struct Node *root = NULL;

  /* Constructing tree given in the above figure */
  root = insert(root, 10);
  root = insert(root, 20);
  root = insert(root, 30);
  root = insert(root, 40);
  root = insert(root, 50);
  root = insert(root, 25);

  /* The constructed AVL Tree would be
            30
           /  \
         20   40
        /  \     \
       10  25    50
  */

  printf("Preorder traversal of the constructed AVL"
         " tree is \n");
  preOrder(root);

  return 0;
}
