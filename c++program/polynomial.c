#include<stdio.h>
#include<conio.h>
#define MAX 10

struct term
{
    int coeff;
    int exp;
};
struct poly
{
    struct term t[10];
    int totaliterms;
};
void initpoly(struct poly*);
void polycreate(struct poly*,int c,int e);
struct poly addpoly(struct poly,struct poly);
void display(struct poly);

//Main section start here
int main()
{
    struct poly p1,p2,p3;
    initpoly(&p1);
    initpoly(&p2);
    initpoly(&p3);

    polycreate(&p1,1,7);
    polycreate(&p1,2,6);
    polycreate(&p1,3,5);
    polycreate(&p1,4,4);
    polycreate(&p1,5,3);

    polycreate(&p2,1,3);
    polycreate(&p2,3,4);
    polycreate(&p2,5,6);
    polycreate(&p2,3,4);
    polycreate(&p2,1,1);
    polycreate(&p2,3,0);

    p3 = addpoly(p1,p2);

    printf("\n First polynomial:\n");
    display(p1);

    printf("\n\n Second polynomial:\n");
    display(p2);

    printf("\n\n Resultant polynomial:\n");
    display(p3);
    return 0;

}
//initialize elements of struct poly

void intitpoly(struct poly *p)
{
    int i;
    p->totalterms = 0;
    for(i=0;i<MAX;i++)
    {
        p->t[i].coeff = 0;
        p->t[i].exp = 0;
    }
}

void polycreate(struct poly *p,int c,int e)
{
    p->t[p -> totalterms].coeff = c;
    p->t[p ->totalterms].conf = e;
    (p->totalterms)++;
}

void display(struct poly p)
{
    int flag = 0,i;
    for(i=0;i<p.totalterms;i++)
    {
        if(p.t[i].exp != 0)
            printf("%d x^%d + ",p.t[i].coeff,p.t[i].exp);
        else
        {
            printf("%d",p.t[i].coeff);
        }
    }
    if(!flag)
        printf("\b\b");
}
//Add two polynomials one and two

struct poly addpoly(struct poly p1,struct poly p2)
{
    int i,j,c;
    struct poly p3;
    initpoly(&p3);



};
