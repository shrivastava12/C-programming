#include<iostream>
using namespace std;

int count = 0;
class test
{
public:
    test()
    {
        count++;
        cout<<"\n\n Constructor Msg:Object number"<<count<<"Created..";
    }
    ~test()
    {
        cout<<"\n\nDestructor Msg:object number "<<count<<"destroyed..";
        count--;
    }
};
int main()
{
    cout <<"Inside the main block";
    cout <<"\n\n Creating first object T1";
    test T1;
    {
        //Block 1
        cout<<"\n\n inside block one";
        cout <<"\n\n Creating two or more objects T2 and T3..";
        test T2,T3;
        cout<<"\n\n Leaving block 1..";
    }
    cout<<"\n\n Back inside the main block...";
    return 0;
}
