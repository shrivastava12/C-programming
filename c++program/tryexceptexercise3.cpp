#include<iostream>
using namespace std;

void division(int a,int b)
{
    try
    {
        if(b==0)
            throw b;
        else
            cout<<"a/b = "<<(float)a/b<<"\n";
    }
    catch(int)
    {
        cout<<"Caught an exception as first throwing \n";
        throw;
    }
}
int main()
{
    int a,b;
    cout<<"Enter the value of a and b";
    cin>>a>>b;
    try
    {
        division(a,b);
    }
    catch(int)
    {
        cout<<"Caught an exception as rethrowing \n";
    }
    return 0;
}
