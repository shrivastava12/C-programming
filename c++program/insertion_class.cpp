#include<iostream>
using namespace std;
class Insertion
{
public:
    int arr[30];
    int i,j,key;
    int n;
    void read()
    {
        cout <<"\n";
        cout<<"----------------\n";
        cout<<"Enter array elements\n";
        cout<<"-----------\n";
        //Get an array elements
        for(int i=0;i<n;i++)
        {
            cout<<"<"<<i+1<<"> ";
            cin>>arr[i];
        }
    }
    //Insertion sort algorithm
    void InsertionSort()
    {

        for(i=1;i<n;i++)
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j =  j-1;
        }
        arr[j + 1] = key;
    }
    void display()
    {
        cout<<"Sorted array"<<endl;
        for(int j=0;j<n;j++)
        {
            cout<<arr[j]<<endl;
        }
        cout<<endl;
    }

};
int main()
{
    Insertion insrt;
    insrt.read();
    insrt.InsertionSort();
    insrt.display();
    return 0;
}
