#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
void push(struct node **top,int item)
{
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL)
        printf("\nstack is empty");
    temp->data = item;
    temp->link = *top;
    *top = temp;
}
//pop the element

int pop(struct node **top)
{
    struct node *temp;
    int item;
    if(*top == NULL)
    {
        printf("\nStack is empty");
        return NULL;
    }
    temp = *top;
    item = temp->data;
    *top = (*top)->link;
    free(temp);
    return item;

}
void delete_stack(struct node **top)
{
    struct node *temp;
    if(*top == NULL)
        return;
    while(*top != NULL)
    {
        temp = *top;
        *top = (*top)->link;
        free(temp);
    }
}
int main()
{
    struct node *s = NULL;
    int i;
    push(&s,12);
    push(&s,3);
    push(&s,5);
    push(&s,23);
    i = pop(&s);
    printf("\n Item is popped: %d",i);
    i = pop(&s);
    printf("\n Item is popped: %d",i);

    delete_stack(&s);
    return 0;
}
