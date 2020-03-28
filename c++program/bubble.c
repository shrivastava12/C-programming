#include<stdio.h>
int main()
{
    int n,i,j,temp,arr[20];
    printf("Enter no:");
    scanf("%d",&n);
    printf("Enter element in array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++) 
    {
        for(j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    for(j=0;j<n;j++)
    {
        printf("%d",arr[j]);
    }
    return 0;
}
