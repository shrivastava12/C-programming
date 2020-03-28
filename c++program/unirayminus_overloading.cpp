#include<iostream>
using namespace std;

class Space
{
    int x;
    int y;
    int z;
public:
    void getdata(int a,int b,int c);
    void display();
    void operator-();
};

void Space :: getdata(int a,int b,int c)
{
    x = a;
    y = b;
    z = c;
}

void Space :: display()
{
    cout<<"x = "<<x<<" ";
    cout<<"y = "<<y<<" ";
    cout<<"Z = "<<z<<"\n";
}
void Space :: operator-()
{
    x = -x;
    y = -y;
    z = -z;
}
int main()
{
    Space s;
    s.getdata(10,-20,30);
    cout<< " s: ";
    s.display();

    -s;
    cout<< "-s: ";
    s.display();

    return 0;
}
