#include<iostream>
using namespace std;

int main()
{
    long n,r;
    cout << "Enter number"<<endl;
    cin >> n;
     r = n&1;
     if(r==0)
     {
         cout << "Number is even :"<< endl;
     }
     else

     {
         cout << "Number is odd"<<endl;
     }
     return 0;
}
