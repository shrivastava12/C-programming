#include<iostream>
using namespace std;

class Base
{
public:
    void display()
    {
        cout<<"\n Display Base:";
    }
    virtual void show()
    {
        cout<<"\n Show base";
    }
};
class Derived:public Base
{
public:
    void display()
    {
        cout<<"\n Display derived";
    }
    void show()
    {
        cout<<"\n Show derived";
    }
};
int main()
{
    Base B;
    Derived D;
    Base *ptr;
    cout<<"\n ptr points to the base\n";
    ptr = &B;
    ptr -> display();
    ptr -> show();

    cout<<"\n ptr points to derived object\n";
    ptr = &D;
    ptr -> display();
    ptr -> show();

    return 0;
}
