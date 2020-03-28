#include<iostream>
using namespace std;

class Balagurusamy
{
public:
    virtual void example()=0;
};
class c:public Balagurusamy
{
public:
    void example()
    {
        cout<<"C text book written by anc";
    }
};
class opps:public Balagurusamy
{
public:
    void example()
    {
        cout<<"C++ is  a good programming language";
    }
};
int main()
{
    Balagurusamy* arr[2];
    c e1;
    opps e2;
    arr[0] = &e1;
    arr[1] = &e2;

    arr[0]->example();
    arr[1]->example();
    return 0;

}
