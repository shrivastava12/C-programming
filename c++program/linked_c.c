#include<stdio.h>
#include<stdlib.h>
struct Node

{
    int data;
    struct Node *next;

};
/* Given a reference (pointer to pointer ) to the head of a list and an int , insert a new Node on the front of the list*/

void Push(struct Node **head_ref,int new_data)

{
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/*Given a node prev_node ,insert s new node after the given previous node */
void inserafter(struct Node* prev_node,int new_data)
{
   //check if the given prev_node is NULL

   if(prev_node ==  NULL)
   {
       printf("The given previous node can not be Null");
       strcut Node *new_node = (struct Node *)malloc(sizeof(struct Node));
       new_node->data =  new_data;
       new_node->next =  prev_node->next;
       prev_node = new_node;

   }
}

void display(struct Node *node)
{
    while(node != NULL)
    {
        printf("%d",node->data);
        node = node->next;
    }
}
int main()
{
    struct Node *head = NULL;
    Push(&head,7);
    display(head);
    return 0;
}
