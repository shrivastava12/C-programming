#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1("The life of software engineer lies within the skill that he gained");
    cout<<s1;
    string enterString;
    cin>>enterString;
    int pos = s1.find(enterString);

    string sub = s1.substr(pos);

    cout << "String is: " << sub;
    return 0;
}
