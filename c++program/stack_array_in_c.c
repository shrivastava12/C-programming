#include<stdio.h>
#include<stdlib.h>
#define arr 10
struct Stack
{
    int top;
    int a[arr];
};

void init_stack(struct Stack* s)
{
    s->top = -1;
}
void push(struct Stack* s,int data)
{
    if(s->top == arr-1)
    {
        printf("\n Stack is full");
        return;
    }
    s->top++;
    s->a[s->top] = data;
}
int pop(struct Stack* s)
{
    int data;
    if(s->top == -1)
    {
        printf("\nStack is empty");
        return;
    }
    data = s->a[s->top];
    s->top--;
    return data;
}

int main()
{
    struct Stack s;
    int i;
    init_stack(&s);
    push(&s,8);
    push(&s,5);
    push(&s,12);
    push(&s,23);

    i = pop(&s);
    printf("\n\n Item popped: %d",i);
    i = pop(&s);
    printf("\n\n Item popped: %d",i);
    return 0;
}
