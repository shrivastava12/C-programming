#include<iostream>
#include<map>
#include<string>

using namespace std;
typedef map<string,int> phoneMap;

int main()
{
    string name;
    int number;
    phoneMap phone;

    cout<<"Enter the sets of name and number  \n";
    for(int i=0;i<3;i++)
    {
        cin >> name;
        cin >> number;
        phone[name] = number;
    }
    phone["Mithu"] = 44444;
    phone.insert(pair<string,int>("Pankaj",34432));
    int n = phone.size();
    cout<<"\n Size of the map:"<<n<<"\n\n";
    cout<<"List of telephone numbers\n";
    phoneMap::iterator p;
    for(p=phone.begin();p!=phone.end();p++)
    {
        cout<<(*p).first <<" "<<(*p).second <<"\n";
    }
    cout<<"\n";
    cout<<"Enter the name:";
    cin>>name;
    number = phone[name];
    cout<<"Number:"<<number<<"\n";
    return 0;
}
