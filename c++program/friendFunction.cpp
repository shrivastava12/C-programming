#include<iostream>
using namespace std;

void friend_function();
void non_friend_function();

class PrivateHolder
{
public:
    PrivateHolder(int val):private_value(val)
    {}
private:
    int private_value;
    friend void friend_function();
};

void friend_function()
{
    PrivateHolder ph(10);
    cout<<ph.private_value<<endl;
}
