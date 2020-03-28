#include<iostream>
#include<iterator>
#include<map>

using namespace std;
int main()
{
    map<int,int> abc;

    //insert elements in random number
    abc.insert(pair<int,int>(1,40));
    abc.insert(pair<int,int>(2,30));
    abc.insert(pair<int,int>(3,60));
    abc.insert(pair<int,int>(4,20));
    abc.insert(pair<int,int>(5,20));
    abc.insert(pair<int,int>(6,50));
    abc.insert(pair<int,int>(7,10));

    //printing map abc
    map<int,int>::iterator itr;
    count<<"\n The map abc is: \n";
    cout<<" \tKey\tElement\n";
    for(itr=abc.begin();itr!=abc.end();++itr)
    {
        cout<<'\t'<<itr->first<<'\t'<<itr->second<<'\n';
    }
    cout<<endl;

    //assigning the elements from abc to def
    map<int,int>def(abc.begin(),abc.end());

    //Print all the elements to the map def
    cout<<"\n The map abc after"<<"assign from def is:\n";
    cout<<"assign from abc is :\n";
    for

}
