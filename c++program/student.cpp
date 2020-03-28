#include<iostream>
using namespace std;

//Base class
class std_basic_info
{
private:
    char name[30];
    int age;
    char gender;
public:
    void getBasicInfo(void);
    void putBasicInfo(void);
};
//function definitions

void std_basic_info::getBasicInfo(void)
{
    cout << "Enter student's basic information"<<endl;
    cout << "Name ?";cin>>name;
    cout << "Age ?";cin >>age;
    cout << "Gender?";cin >>gender;
}
void sts_basic_info::putBasicInfo(void)
{
    cout << "Name:" <<name <<",Age: " <<age << ",Gender:" <<gender <<endl;

}
class std_result_info::public std_basic_info
{
private:
    int totlaM;
    float perc;
    char grade;
public:
    void getResultInfo(void);
    void putResultInfo(void);
};

void std_result_info::getResultInfo(void)
{
    cout << "Enter student's result information:"<<endl;
    cout <<"Total marks";cin>>totalM;
    perc = (float)((totalM*100)/500);
    cout << "Grade?:";cin >>grade;
}
void std_result_info::putResultInfo(void)
{
    cout << "Total marks:"<<totalM <<",percentage:"<<perc <<"Grade":<<grade<<endl;

}
