#include <iostream>
using namespace std;

class A
{
};

class B
{
public:
    B() {cout<<"B() constructor"<<endl;}
    B(A& _a) {cout<<"B(A _a) constructor"<<endl;}
    B(int n) {cout<<"B(int n) constructor"<<endl;}
    B(double d) {cout<<"B(double d) constructor"<<endl;}

    operator A()
    {
        cout<<"operator A() call"<<endl;
        return A();
    }
    operator int()
    {
        cout<<"operator int() call"<<endl;
        return 10;
    }
    operator double()
    {
        cout<<"operator double() call"<<endl;
        return 5.5;
    }
};

class Point
{
private:
    int x;
    int y;
public:
    explicit Point(int _x=0, int _y=0) : x(_x), y(_y) {}
    void Print() const {cout<<x<<','<<y<<endl;}
    operator int() const {return x;}
};

int main()
{
    A a;
    int n = 10;
    double d = 3.5;
    
    B b; // call B()
    b = a; // b = B(a)
    b = n; // b = B(n)
    b = d; // b = B(d)
    cout<<endl;

    a = b; // a = b.operator A()
    n = b; // n = b.operator int()
    d = b; // d = b.operator double()
    cout<<endl;
    
    Point pt;
    pt.Print();

    // pt = 10; // it raises an error because the constructor Point(int, int) is defined as explicit...
    pt = Point(10);
    pt.Print();
    int x = pt;
    cout<<"x="<<x<<endl;

    return 0;
}