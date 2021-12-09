#include <iostream>
using namespace std;
// calling convention is different depending on the type of a function...

void Print(int n) {cout<<"global function: "<<n<<endl;}

namespace A
{
    void Print(int n) {cout<<"namespace A function: "<<n<<endl;}
}

class Point
{
private:
    int x;
    int y;
public:
    explicit Point(int _x=0, int _y=0) : x(_x), y(_y) {}
    static void Print(int n) {cout<<"Point class, static member function: "<<n<<endl;}
    void Print() const {cout<<x<<','<<y<<endl;}
    void PrintInt(int n) {cout<<"test integer: "<<n<<endl;}
};

int main(void)
{
    void (*fp)(int);

    Print(10);
    A::Print(10);
    Point::Print(10);

    fp = Print;
    fp(10);
    fp = A::Print;
    fp(10);
    fp = Point::Print;
    fp(10);
    cout<<endl;

    /*****************************/
    Point pt(2, 3);
    Point* p = &pt;

    void (Point::*pfp1)() const;
    void (Point::*pfp2)(int);

    pfp1 = &Point::Print;
    pfp2 = &Point::PrintInt;

    (pt.*pfp1)(); // call by object
    (pt.*pfp2)(10);
    cout<<endl;

    (p->*pfp1)(); // call by object pointer
    (p->*pfp2)(10);
    cout<<endl;
    return 0;
}