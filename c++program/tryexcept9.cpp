#include<iostream>
using namespace std;
void myclass()
{
    try
    {
        throw "y";
    }
    catch(const char*)
    {
        cout<<"Exception inside myclass\n";
        throw;
    }
}
int main()
{
    cout<<"Now main starts\n";
    try
    {
        myclass();
    }
    catch(const char*)
    {
        cout<<"Exception inside main\n";
    }
    cout<<"Now main ends\n";
    return 0;
}
