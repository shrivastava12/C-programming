#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool compare_string_by_length(string i,string j)
{
    return (i.size() == j.size());
}

int main()
{
    int inputs[] = {7,8,4,1,6,5,9,4};
    vector<int> v(inputs,inputs+8);
    cout<<binary_search(v.begin(),v.end(),7); //print 1, Boolean True
    cout<<binary_search(v.begin(),v.end(),217); //print 0 ,Boolean False

    string s[] = { "test","abcdf","efghijl","pop"};
    cout<<binary_search(s,s+4,"nickt",compare_string_by_length);
    // arch for the string in s which have same length as of "nicky"
    return 0;
}
