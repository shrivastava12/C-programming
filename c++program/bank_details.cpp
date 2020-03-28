#include<iostream>
#include<stdio.h>
#include<string>
#define minimum 500
#define service_charge 100
#define r 0.15
using namespace std;
class Account
{
protected:
    char name[100];
    int ac_number;
    char ad_type[100];
public:
    void create(char *t);
};
void Account::create(char *t)
{
    cout << "Enter customer name:";
    gets(name);

    cout <<"Enter account number:";
    cin >> ac_number;
}
class cur_account:public Account
{
private:
    float balance;
public:
    void deposite(float d);
    void withdraw(float w);
    void display();

};
void cur_account::deposite(float d)
{
    balance = d;
}
void cur_account::withdraw(float w)
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
void cur_account::display()
{
    cout << "\n Now balance =" << balance << "\n";
}
class sav_account:public Account
{
private:
    float balance;
    int d,m,y;
public:
    void deposite(float d);
    void withdraw(float w);
    void display();
    void set_date(int a,int b,int c)
    {
        d = a;
        m = b;
        y = c;
    }
    void interest();
};
void sav_account::deposite(float d)
{
    int x,y,z;
    cout << "Enter today's date(i.e day month year):";
    cin >> x >> y >> z;
    set_date(x,y,z);
    balance = d;
}

void sav_account::withdraw(float w)
{
    if(balance<w)
    {
        cout << "Sorry your balance is less than your withdraw amount\n";
    }
    else
    {
        balance-=w;
        if(balance<minimum)
        {

            cout <<"\n Your current balance is:"<<balance<<"which is less than"<<minimum<<"\n your account is discharged by "<<service_charge<<"TK\n"<<"You must store"<<minimum<<"TK to avoid discharge \n"<<"Do you want to withdraw? press 1 for yes or press 0 for no"<<"What is your option ?";
            int test;
            cin>>test;
            if(test==0)
            {
                balance+=w;
            }
        }
    }
}

void sav_account::display()
{
    cout << "\n Now balance ="<<balance;
}
void sav_account::interest()
{
    int D[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int d1,y1,m1;
    cout <<"Enter todays date:(i.e day month year)";
    cin >> d1 >>m1>>y1;
    int iday,fday;
    iday = d;
    fday = d1;
    for(int i = 0;i<m1;i++)
    {
        fday+=D[i];
    }
    int today;
    today = fday-iday;
    float ty;
    ty= float(today)/365+y1-y;
    float interst;
    interst = ty*r*balance;
    cout << "Interest is :"<<interst<<"\n";
    balance+=interst;

}
int main()
{
    sav_account santo;
    santo.create("savings");
    float d;
    cout << "Enter deposite amount:";
    cin >> d;
    santo.deposite(d);
    santo.display();
    int t;
    cout << "\n press 1 to see your interest :\n"
    <<"press  0 to skip";
    cin>>t;
    if(t==1)
    {
        santo.interest();
    }
    cout << "\n Enter your withdrawal amount :";
    float w;
    cin >> w;
    santo.withdraw(w);
    santo.display();
    return 0;
}





