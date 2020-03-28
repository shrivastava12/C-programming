#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#define minimum 500
#define service_charge 100
#define r 0.15

using namespace std;
class Account
{
protected:

    char name[100];
    int ac_number;
    char ac_type[100];
public:
    Account(char *n,char *t,int no);

};
Account::Account(char *n,char *t,int no)
{
    strcpy(name,n);
    strcpy(ac_type,t);
    ac_number=no;
}
class curr_account:public Account
{
private:
    float balance,d,w;
public:
    void withdraw(float w);
    void deposite(float d)
    {
        balance=d;
    }
    curr_account(char *n,char *t,int number,float dp,float wd):
        Account(n,t,number)
    {
        d = dp;
        w = wd;
        deposite(d);
        withdraw(w);
    }
    void display();
};
void curr_account::withdraw(float w)
{
    if(balance<w)
    {
        cout << "Sorry your balance is less than your withdraw amount";
    }
    else
    {
        balance-=w;
        if(balance<minimum)
        {
            cout<<"\n your current balance is :"<<balance<<" which is less than"<<minimum<<"\n your account is discharged by "<<service_charge<<"TK \n"<<" You must store "<<minimum<<"TK to avoid discharge \n "<<" Do you want to withdraw ? press 1 for yes press 0 for no \n"<<" what is your option ?";
            int test;
            cin>>test;
            if(test==0)
                balance+=w;
            else
                ;
        }
    }


}
void curr_account::display()
{
    cout << "\n Now balance = "<<balance<<"\n";
}
class sav_account:public Account
{
    float balance;
    int d,m,y;
public:
    void deposite(float d)
    {
        balance = d;
    }
    void withdraw(float w);
    void display();
    void set_date()
    {
        d=12;
        m=1;
        y= 2010;

    }
    void interest();
    sav_account(char *n,char *t,int number,float dp,float wd):
        Account(n,t,number)
    {
        float d,w;
        d = dp;
        w = wd;
        deposite(d);
        withdraw(w);
        interest();
    }



};
void sav_account::withdraw(float w)
{
    if(balance<w)
        cout<<" sorry your balance is less than your withdrawal amount \n";
    else
    {
        balance-=w;
        if(balance<minimum)
        {
            cout<<"\n your current balance is :"<<balance<<" which is less than"<<minimum<<"\n your account is discharged by "<<service_charge<<"TK \n"<<" You must store "<<minimum<<"TK to avoid discharge \n "<<" Do you want to withdraw ? press 1 for yes press 0 for no \n"<<" what is your option ?";
            int test;
            cin>>test;
            if(test==0)
                balance+=w;
        }
        else
            ;
    }

}
void sav_account::display()
{
    cout<<"\n Now balance = "<<balance;
}
void sav_account::interest()
{
    int D[12]= {31,28,31,30,31,30,31,31,30,31,30,31};
    int d1,y1,m1;
    cout<<" Enter today's date :(i,e day,month,year) ";
    cin>>d1>>m1>>y1;
    int iday,fday;
    iday=d;
    fday=d1;
    for(int i=0; i<m1; i++)
    {
        fday+=D[i];
    }
    for(int i=0; i<m; i++)
    {
        iday+=D[i];
    }
    int tday;
    tday=fday-iday;
    float ty;
    ty=float(tday)/365+y1-y;
    balance=balance*pow((1+r),ty);
}
int main()
{
    float d;
    cout <<"Enter customer name:";
    char name[100];
    gets(name);
    cout <<"Enter account number:";
    int number;
    cin>>number;
    cout << "Enter your deposite amount";
    cin>>d;

    cout << "Enter your withdrawal amount:";
    float w;
    cin >> w;
    curr_account s("current",name,number,d,w);
    s.display();
    sav_account c ("saving",name,number,d,w);
    c.display();
    return 0;

}
