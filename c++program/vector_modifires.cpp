// Modifiers in vector

#include<iostream>
#include<vector>
using namespace std;
int main()
{

    vector<int> v;
    v.assign(5,10);
    cout<<"The vector elements are:";
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

    //Insert 15 elements to the last position
    v.push_back(15);
    int n = v.size();

    cout<<"\n The last element is :"<<v[n-1];

    //Remove last element
    v.pop_back();

    cout<<"\n The vector element is:";
    for(int i = 0;i<v.size();i++)
        cout<<v[i]<<" ";

    //Insert 5 at the beginning
    v.insert(v.begin(),5);

    cout<<"\n The first element is :"<<v[0];

    //remove the first element
    v.erase(v.begin());
    cout<<"\n The first element is:"<<v[0];

    //Insert element at the beginning
    v.emplace(v.begin(),5);

    // Insert 20 at the end
    v.emplace_back(20);
    n = v.size();

    cout<<"\n The last element is "<<v[n-1];

    //erase the vector
    v.clear();
    cout<<"\n Vector size after erase:"<<v.size();

    //two vector to perform swap
    vector<int> v1,v2;
    v1.push_back(1);
    v1.push_back(1);
    v2.push_back(3);
    v2.push_back(4);

    cout<<"\n\nVector 1:";
    for(int i =0;i<v1.size();i++)
        cout<<v1[i]<<" ";

    cout<<"\n Vector 2";
    for(int i =0;i<v2.size();i++)
    cout<<v2[i]<<" ";

    v1.swap(v2);

    cout<<"\n After swap \n Vector 1";
    for(int i=0;i<v1.size();i++)
    cout<<v1[i]<<" ";

    cout<<"\n vector 2";
    for(int i=0;i<v2.size();i++)
    cout<<v2[i]<<" ";
    return 0;

}
