#include<stdio.h>
#include<stdlib.h>
#define MAX 10
// #define LEFTCHILD(k) 2K-1
// #define RiGHTCHILD(K) 2k

struct node
{
    int data;
    struct node *next;
};

void insertbeg(struct node **head_ref,int num)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->data = num;
    temp->next = (*head_ref);
    (*head_ref) = temp;
}
void insertafter(struct node *pre,int num)
{
    if(pre == NULL)
    {
        printf("The given previous node can not be null");
        return;
    }
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = pre->next;
    pre->next = new_node;
}

void insertend(struct node **head_ref,int num)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    struct node* last = *head_ref;
    new_node->data = num;
    new_node->next = NULL;

    if(head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    //Else traverse the list till the last node

    while(last->next != NULL )
        last = last->next;

    //change the next of last node
    last->next = new_node;
    return;
}

void deletenode(struct node** head_ref,int key)
{
    //store head node
    struct node* temp = *head_ref,*prev;

    //If head node itself holds the key to be deleted
    if(temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    //Search for the key to be deleted ,keep track of the
    //previous node as we need to change 'prev->next'

    while(temp !=NULL && temp->data !=key)
    {
        prev = temp;
        temp->next;
    }

    //If key was not present in linked list

    if(temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);

}

void display(struct node *Node)
{
    while(Node != NULL)
    {
        printf("%d",Node->data);
        Node->next;

    }
}

int main()
{
    //started with the empty list

    struct node* head = NULL;
    insertbeg(&head,7);



    display(head);
    return 0;




}
