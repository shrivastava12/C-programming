#include<stdio.h>
#include<stdlib.h>
int main()
{
    int *p,n,i;
    printf("Enter the number of integer to be searched:");
    scanf("%d",&n);
    p=(int *)malloc(n*sizeof(int));
    if(p==NULL)
    {
        printf("Memory not available\n");
        exit(1);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter an integer:");
        scanf("%d",p+i);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\t",*(p+i));
    }
    return 0;
}
