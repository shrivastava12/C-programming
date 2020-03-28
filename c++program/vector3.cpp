#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int>g1;
    for(int i = 1;i<=10;i++)
        g1.push_back(i*10);

    cout<<"\n Reference operator [g] :g1[2] = "<<g1[2];
    cout<<"\n at:g1.at(4) = "<<g1.at(4);
    cout<<"\n Front():g1.front() = "<<g1.front();
    cout<<"\n Back() :g1.back() = "<<g1.back();

    //Pointer to the first element
    int *pos = g1.data();

    cout<<"\n The first element is "<<*pos;
    return 0;
}
