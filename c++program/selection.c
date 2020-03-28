#include<stdio.h>
int main()
{
    int n,i,j,min_i,arr[20],temp;
    printf("Enter no:");
    scanf("%d",&n);
    printf("Enter element in array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++)
    {
        min_i=arr[i];
    for(j=i;j<n;j++)
    {
        if(arr[j]<arr[min_i])
        {
            min_i=j;
        }
    }
    if(i!=min_i)
    {
        temp=arr[i];
        arr[i]=arr[min_i];
        arr[min_i]=temp;
        }
    }
    for(j=0;j<n;j++)
    {
        printf("%d",arr[j]);
    }
    return 0;
}

