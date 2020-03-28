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
    int totalterms;
};
void initpoly(struct poly *);
void polycreate(struct ploy *,int c,int e);
struct poly addpoly(struct poly,struct poly);
void display(struct poly);

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
    polycreate(&p1,5,2);

    polycreate(&p2,1,4);
    polycreate(&p2,1,3);
    polycreate(&p2,1,2);
    polycreate(&p2,1,1);
    polycreate(&p2,2,0);

    p3 = addpoly(p1,p2);

    printf("\n First polynomial :\n");
    display(p1);

    printf("\n\n Second polynomial:\n");
    display(p2);

    printf("\n\n Resultant polynomial:\n");
    displaY(p3);
    return 0;
}

//Initialize the element of struct poy

void initpoly(struct poly *p)
{
    int i;
    p->totalterms = 0;
    for(i=0;i<MAX;i++)
    {
        p->t[i].coeff = 0;
        p->t[i].exp = 0;
    }
}

//Add the polynomial to the array

void polycreate(struct poly *p,int c,int e)
{
    p->t[p->totalterms].coeff = c;
    p->t[p->totalterms].exp = e;
    p->totalterms++;

}

void display(struct poly p)
{
    int flag = 0,i;
    for(int i=0;i<p.totalterms;i++)
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
//Add two polynomial one and two

struct poly addpoly(struct poly p1,struct poly p2)
{
    int i,j,c;
    struct poly p3;
    initpoly(&p3);

    if(p1.totalterms > p2.totalterms)
        c = p1.totalterms;
    else
        c = p2.totalterms;

    for(i=0,j=0;i<=c;p3.totalterms++)
    {
        if(p1.t[i].coeff == 0 && p2.t[j].coeff == 0)
            break;
        if(p1.t[i].exp >= p2.t[j].exp)
        {
            if(p1.t[i].exp == p2.t[j].exp)
            {
                p3.t[p3.totalterms].coeff = p1.t[i].coeff + p2.t[j].coeff;
                p3.t[p3.totalterms].exp = p1.t[i].exp;
                i++;
                j++;
            }
            else
            {
                p3.t[p3.totalterms].coeff = p1.t[i].coeff;
                p3.t[p3.totalterms].exp = p1.t[i].exp;
                i++;
            }
        }
        else
        {
            p3.t[p3.totalterms].coeff = p2.t[j].coeff;
            p3.t[p3.totalterms].exp = p2.t[j].exp;
            j++;
        }
    }
    return p3;
};
