#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[],int low,int high)
{
    int pivot;
    pivot = arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;


}
void quicksort(int arr[],int low ,int high)
{
    if(low<high)
    {
        int loc=partition(arr,low,high);
        quicksort(arr,low,loc-1);
        quicksort(arr,loc+1,high);
    }
}
void printarray(int arr[],int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<"";
        cout <<endl;
    }
}
int main()
{
    int arr[20],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    cout<<"Sorted array\n";
    printarray(arr,n);
    return 0;

}
