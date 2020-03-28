#include<iostream>
#include<vector>

using namespace std;

int main()
{

    vector<int> g1;
    for(int i = 1;i<5;i++)
        g1.push_back(i);

    cout<<"Size:"<<g1.size();
    cout<<"\n Capacity:"<<g1.capacity();
    cout<<"\n Max_size:"<<g1.max_size();

    g1.resize(4);

    cout<<"\n Size: "<<g1.size();

    if(g1.empty() == false)
        cout<<"\n Vector is not empty";
    else
        cout<<"\n Vector is empty";

    g1.shrink_to_fit();
    cout<<"\n Vector elements are:";
    for(auto it = g1.begin();it!=g1.end();it++)
        cout<<*it<<" ";
    return 0;
}
