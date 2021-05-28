#include <iostream>
using namespace std;
class Info
{
public:
    int year;      //data member (also instance variable)
    string month; //data member(also instance variable)
    string day;
    info(int y, string m,string d)
    {
        year= y;
        month = m;
        day = d;
    }
    void display()
    {
        cout << year << "  " << month << "  " << day<< endl;
    }
};

int main(void)
{ //explicit call
    Info e1 = Info(2019, "June",mon); 
    Info e2 = Info(2020, "april",tue);
    e1.display();
    e2.display();
    return 0;
}
