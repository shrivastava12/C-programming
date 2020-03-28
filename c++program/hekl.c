#include<stdio.h>
int main()
{
    int n,arr[100],i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {

        if(arr[i]>=38 && arr[i]%5>3)
        {
            arr[i]=arr[i]+(5-arr[i]%5);
            printf("%d",arr[i]);
        }
        else
        {
            printf("%d",arr[i]);
        }
    }
    return 0;
}
