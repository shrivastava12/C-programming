#include<iostream>
#include<list>
#include<cstdlib>

using namespace std;
void display(list<int> &lst)
{
    list<int> :: iterator p;
    for(p=lst.begin();p!=lst.end();++p)
    {
        cout <<*p <<", ";
        cout << "\n\n";
    }
}
int main()
{
    list<int> list1;
    list<int> list2(5);
    for(int i=0;i<3;i++)
    {
        list1.push_back(rand()/100);

    }
    list<int> :: iterator p;
    for(p = list2.begin();p!=list2.end();++p)
    {
        *p = rand()/100;
    }
    cout <<"List1\n";
    display(list1);
    cout <<"List 2\n";
    display(list2);

    //Add two elements at the end of the list1
    list1.push_front(100);
    list1.push_back(200);

    //Remove an element at the front of list 2

    list2.pop_front();

    cout <<"Now List1\n";
    display(list1);
    cout <<"Now list2\n";
    display(list2);

    list<int> listA,listB;
    listA = list1;
    listB = list2;

    //Merging two list(unsorted)

    list1.merge(list2);
    cout <<"Merged unsorted list\n";
    display(list1);

    //sorting and merging
    listA.sort();
    listB.sort();
    listA.merge(listB);
    cout <<"Merged sorted lists\n";
    display(list1);

    //Reversing a list
    listA.reverse();
    cout <<"Reversed merged list\n";
    display(listA);
    return 0;
}
