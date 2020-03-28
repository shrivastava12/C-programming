#include<iostream>
#include<queue>
using namespace std;

void showq(queue<int> gq)
{
    queue<int> g = gq;
    while(!g.empty())
    {
        cout<< '\t' << g.front();
        g.pop();
    }
    cout<<"\n";
}
int main()
{
    queue<int> gquiz;
    gquiz.push(10);
    gquiz.push(20);
    gquiz.push(30);

    cout<<"The queue quiz is :";
    showq(gquiz);

    cout<<"\nquiz.size() : "<<gquiz.size();
    cout<<"\nquiz.front() : "<<gquiz.front();
    cout<<"\nquiz.back() : "<<gquiz.back();

    cout<<"\ngquiz.pop() : ";
    gquiz.pop();
    showq(gquiz);
    return 0;
}
