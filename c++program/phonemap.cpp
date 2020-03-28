// Use map to create a phone directory
#include<iostream>
#include<map>
#include<cstring>
using namespace std;
class name
{
    char str[40];
public:
    name()
    {
        strcpy(str," ");
    }
    name(char *s)
    {
        strcpy(str,s);
    }
    char *get()
    {
        return str;
    }

};
//Must define less than relative to name objects
bool operator<(name a,name b)
{
    return strcmp(a.get(),b.get())
}
