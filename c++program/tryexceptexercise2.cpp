#include<iostream> //For multiple catch statement
using namespace std;
void add(int x,int y)
{
    try
    {
        if(x == 1 && y == 1)
            throw x; //int
        else
            if(x == 2 && y == 2)
            throw 'x'; //char
        else
            if(x == 3 && y == 3)
            throw 1.0; //double
    }
    catch(char c)
    {
        cout<<"Caught character\n";
    }
    catch(int m)
    {
        cout<<"Caught integer\n";
    }
    catch(double n)
    {
        cout<<"Caught a double number\n";
    }
    cout<<"End of try catch system\n\n";
}
int main()
{
    cout<<"Testing multiple catch statement\n";
    cout<<"x == 1 and y == 1\n";
    add(1,1);
    cout<<"x == 2 and y==2\n";
    add(2,2);
    cout<<"x == 3 and y == 3\n";
    add(3,3);
    return 0;
}
