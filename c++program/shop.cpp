#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

class books
{
public:
    char **author;
    char **title;
    float *price;
    char **publisher;
    int *stock_copy;
    int size;
public:
    books();
    void book_detail(int i);
    void buy(int i);
    int search();

};
books :: books()
{
    size = 4;
    author  =  new char*[80];
    title =  new char*[80];
    publisher = new char*[80];

    for(int i=0;i<size;i++)
    {
        author[i] = new char[80];
        title[i] = new char[80];
        publisher[i] = new char[80];
    }
    stock_copy = new int[size];
    price =  new float[size];

    title[0] = "object oriented programming with c++";
    title[1] = "programming in ANCI";
    title[2] = "electronic circuit thoery";
    title[3] = "computer algorithm";

    author[0] = "balagurusamy";
    author[1] = "mithu";
    author[2] = "mithu1";
    author[3] = "mithu2";

    stock_copy[0] = 200;
    stock_copy[1] = 150;
    stock_copy[2] = 50;
    stock_copy[3] = 80;

    price[0] = 120.3;
    price[1] = 113.2;
    price[2] = 140;
    price[3] = 180.3;
}
void books :: book_detail(int i)
{
    cout <<"************book detail ************\n";
    cout<<setw(12)<<"Title"<<setw(25)<<"Author Name"
    <<setw(18)<<"Stock copy\n";
    cout<<setw(15)<<title[i]<<setw(16)<<author[i]<<setw(15)
    <<stock_copy[i]<<"\n";
}
int books::search()
{
    char name[80],t[80];
    cout <<"Enter author name";
    gets(name);
    cout <<" and title of book in small letter:";
    gets(t);

    int count =-1;
    int a,b;
    for(int i=0;i<size;i++)
    {
        a = strcmp(name,author[i]);
        b = strcmp(t,title[i]);
        if(a==0 && b ==0)
            count = i;
    }
    return count;
}

void books::buy(int i)
{
    if(i<0)
    {
        cout<<"This book is not available\n";
    }
    else
    {
        book_detail(i);
        cout<<"How many copies of this book is required:?";
        int copy;
        int remaining_copy;
        cin >>copy;
        if(copy<=stock_copy[i])
        {
            remaining_copy = stock_copy[i]-copy;
            float total_price;
            total_price = price[i]*copy;
            cout<<"Total price = "<<total_price <<"TK\n";
        }
        else
            cout <<"Sorry your required copy is not available\n";

    }

}
int main()
{
    books b1;
    int result;
    result = b1.search();
    b1.buy(result);
    return 0;
}
