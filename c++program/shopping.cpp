#include<iostream>
using namespace std;
#define m 50
class items
{
    int itemCode[m];
    float itemPrice[m];
    int count;
public:
    void cnt(void)
    {
        count = 0;
    }
    void getItem(void);
    void displaySum(void);
    void remove(void);
    void displayItem(void);

};
void items::getItem(void)
{
    cout << "Enter item code:";
    cin >> itemCode[count];
    cout << "Enter item cost:";
    cin >> itemPrice[count];
    count++;
}
void items::displaySum(void)
{
    float sum = 0;
    for(int i =0;i<count ;i++)
    {
        sum = sum+itemPrice[i];
        cout << "\n Total value:"<<sum <<"\n";
    }
}
void items::remove(void)
{
    int a;
    cout << "Enter Item code";
    cin >> a;
    for(int i=0;i<count;i++)
    {
        if(itemCode[i]==a)
        {
            itemPrice[i]=0;
        }
    }
}
void items::displayItem(void)
{
    cout << "\n Code price";
    for(int i=0;i<count;i++)
    {
        cout << "\n" << itemCode[i];
        cout << "\n"<<itemPrice[i];

    }
    cout << "\n";
}
//-----------------Main area start----------------------
int main()
{
    items order;
    order.cnt();
    int x;
    do
    {
        cout << "\n You can do the following"
        <<"Enter appropriate number \n";
        cout << "\n1: Add an Item";
        cout << "\n2: Display total value";
        cout << "\n3: Delete an Item";
        cout << "\n4: Display all Items";
        cout << "\n5: Quit";
        cout << "\n\n What is your option?";
        cin >> x;
        switch(x)

        {
        case 1:
            order.getItem();
            break;
        case 2:
            order.displaySum();
            break;
        case 3:
            order.remove();
            break;
        case 4:
            order.displaySum();
            break;
        case 5:
            break;
        default:
            cout << "Error in input Please try again";
        }

}
 while(x!=5);
            return 0;

}
