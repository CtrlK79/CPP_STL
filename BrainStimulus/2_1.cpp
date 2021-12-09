#include <iostream>
using namespace std;

void Print(int n) {cout<<"Integer: "<<n<<endl;}

int main()
{
    void (*fp)(int);
    fp = Print;

    Print(10);
    fp(10);
    (*fp)(10);

    cout<<endl;
    cout<<Print<<endl;
    cout<<fp<<endl;
    cout<<*fp<<endl;

    return 0;
}