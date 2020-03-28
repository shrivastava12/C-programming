#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("country");
    fout << "United state of america\n";
    fout << "United Kingdom\n";
    fout << "south korea\n";

    fout.close();

    fout.open("Capital");
    fout << "Washingaton\n";
    fout << "London\n";
    fout << "Seoul\n";

    fout.close();

    // Reading the file

    const int N =80;
    char line[N];
    ifstream fin;
    fin.open("country");
    cout << "Contents of the country file\n" <<"\n";
    while(fin)
    {
        fin.getline(line,N);
        cout << line;
    }
    fin.close(); // disconnect read line

    fin.open("capital");
    cout << "\n Content of capital file\n\n";
    while(fin)
    {
        fin.getline(line,N);
        cout << line;
    }
    fin.close();
    return 0;

}
