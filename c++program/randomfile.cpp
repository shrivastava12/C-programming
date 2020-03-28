#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class INVENTORY
{
    char name[10];
    int code;
    float cost;

public:
    void getdata()
    {
        cout << "Enter name :" ;cin >>name;
        cout << "Enter code:" ;cin >>code;
        cout << "Enter cost:" ; cin >>cost;
    }
    void putdata()
    {
        cout << setw(10) <<name
        << setw(10) <<code
        << setprecision(2) << setw(10) <<cost
        <<endl;
    }
    //end class definition


};
int main()
{
    INVENTORY item;
    fstream inoutfile;
    inoutfile.open("STOCK.DAT",ios::ate|ios::in|ios::out|ios::binary);
    inoutfile.seekg(0,ios::beg);
    cout << "Current content of stock" <<endl;
    while(inoutfile.read((char *)& item,sizeof item))
    {
        item.putdata();
    }
    inoutfile.clear();

    // *************Add one more item ***************

    cout << "\n Add an item\n";
    item.getdata();
    char ch;
    cin.get(ch);
    inoutfile.write((char *) &item,sizeof item);

    // Display the appended file

    inoutfile.seekg(0);
    cout << "Contents of the append file" <<endl;
    while(inoutfile.read((char *) &item,sizeof item))
    {
        item.putdata();
    }

    //Find number of the objects in the file
    int last = inoutfile.tellg();
    int n = last/sizeof(item);

    cout << "Number of objects = "<<n<<endl;
    cout << "Total bytes in the file =" <<last <<endl;

    //  Modify the details of an item

    cout << "Enter object number to be updated\n";
    int object;
    cin >> object;
    cin.get(ch);
    int location = (object - 1)*sizeof(item);
    if(inoutfile.eof())
        inoutfile.clear();

    inoutfile.seekp(location);
    cout << "Enter new value to the object \n";
    item.getdata();
    cin.get(ch);
    inoutfile.seekg(0);

    //go to the start

    cout << "Contents of updated  file:"<<endl;
    while(inoutfile.read((char *)& item,sizeof item))
    {
        item.putdata();
    }
    inoutfile.close();

    return 0;

}
