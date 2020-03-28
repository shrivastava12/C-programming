#include<iostream>
using namespace std;
class bank
{
private:

    char Name[40];
    int ac_no;
    char ac_type[20];
    double balance;
public:
    int assign(void);
    void deposite(float b);
    void withdraw(float c);
    void display(void);
};
int bank::assign(void)
{
    float initial;
    cout <<"You have to pay 500 to open your account\n"
    <<"You have to store at least 500 to keep your account active\n"
    <<"Would you want to open a account???\n"
    <<"If Yes press 1\n"
    <<"If No press 0:";
    int test;
    cin >> test;
    if(test==1)
    {

        initial=500;
        balance = initial;
        cout <<"Enter name , account number and account type to create account :\n";
        cin >>Name>>ac_no>>ac_type;
    }
    else
        ; //do nothing

    return test;
}
void bank::deposite(float b)
{
    balance+=b;
}
void bank::withdraw(float c)
{
    balance = c;
    if(balance<500)
    {

        cout <<" Sorry your balance is not sufficient to withdraw "<<c <<"\n"
        <<"You have to store at least 500 to keep your account active\n";
        balance+=c;
    }
}
void bank::display(void)
{
    cout << "Name" << Name <<"Account type"<< ac_type<<"Balance"<<balance<<endl;

}
int main()
{
    bank account;
    int t;
     t =  account.assign();
     if(t==1)
     {
         cout <<"Would you want to deposite:?"<<endl
         <<"If No press 0"<<endl
         <<"If YES enter deposite ammount :"<<endl;
         float dp;
         cin >> dp;
         account.deposite(dp);
         cout<<"Would you want to withdraw:?"<<endl
         <<"if NO press 0"<<endl
         <<"If YES enter withdrawal ammount :"<<endl;
         float wd;
         cin >>wd;
         account.withdraw(wd);
         cout << "See details :"<<endl<<endl;
         account.display();

     }
     else if(t==0)
    cout<<"Thank you see you again\n";
    return 0;
}
