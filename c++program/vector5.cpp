#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vect1{1,2,3,4};

    vector<int>vect2;

    vect2 = vect1;

    cout<<"old vector elements are:";
    for(int i = 0;i<vect1.size();i++)
        cout<<vect1[i]<<" ";
    cout<<endl;

    cout<<"new vector elements are";
    for(int i =0;i<vect2.size();i++)
        cout<<vect2[i]<<" ";
    cout<<endl;

    vect1[0] = 2;
    cout<<"The first element of old vector is:";
    cout<<vect1[0]<<endl;
    cout<<"The first element of new vector is";
    cout<<vect2[0]<<endl;

    return 0;
}
