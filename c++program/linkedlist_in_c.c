#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void addbeg(struct node **head_ref,int new_data)
{
    struct node *temp;
    temp =(struct node*)malloc(sizeof(struct node));
    temp->data = new_data;
    temp->next = *head_ref;
    *head_ref = temp;
}
void insert_after(struct node *pre,int new_data)
{
    if(pre == NULL)
    {
        printf("The given previous node can not be null");
        return;
    }
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = new_data;
    newnode->next = pre->next;
    pre->next = newnode;
}

void append(struct node **head_ref,int new_data)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    struct node *last =  *head_ref;

    newnode->data = new_data;
    newnode->next = NULL;
    if(*head_ref == NULL)
    {
        *head_ref = newnode;
        return;
    }
    while(last->next != NULL)
    {
        last = last->next;
        last->next = newnode;
        return;
    }
}
void deletenode(struct node **head_ref,int key)
{
    struct node *temp = *head_ref;
    struct node *pre;
    if(temp!=NULL && temp->data == key)
    {
        head_ref = temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key)
    {
        pre = temp;
        temp = temp->next;
    }
    //If the key was not present in the list

    if(temp == NULL)
    {
        pre->next = temp->next;
        free(temp);
    }
}
void printlist(struct node *node)
{
    while(node!=NULL)
    {
        printf("%d",node->data);
        node->next;
    }
}










