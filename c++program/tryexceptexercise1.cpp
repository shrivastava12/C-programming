#include<iostream>
using namespace std;

void add(int x,int y)
{
    int sum = 0;
    if(x>5 && y>5)
        throw sum;
    else
        sum = x+y;
        cout<<"sum="<<sum<<endl;
}
int main()
{
    try
    {
        add(4,3);
        add(7,8);
    }
    catch(int)
    {
        cout<<"Wrong input"<<endl;
    }
    return 0;


}
