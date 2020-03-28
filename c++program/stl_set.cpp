#include<iostream>
#include<set>
#include<iterator>
using namespace std;
int main()
{
    set <int ,greater<int> > gquiz1;

    gquiz1.insert(40);
    gquiz1.insert(30);
    gquiz1.insert(60);
    gquiz1.insert(20);
    gquiz1.insert(50);
    gquiz1.insert(10);

    set <int,greater<int>>::iterator itr;
    cout<<"THe set quiz is:";
    for(itr=gquiz)


}
