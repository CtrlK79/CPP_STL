#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(int _x=0, int _y=0) : x(_x), y(_y) {}
    void Print() const {cout<<x<<','<<y<<endl;}
};

class PointPtr // smart pointer object... if we use a smart pointer, we don't need to free the memory explicitly... plus, it prevents the memory from remaining assigned when the program closes accidently...
{
private:
    Point *ptr;
public:
    PointPtr(Point *p) : ptr(p) {}
    ~PointPtr() {delete ptr;}
    Point* operator->() const {return ptr;}
    Point& operator*() const {return *ptr;}
};

int main()
{
    Point* p1 = new Point(2, 3);
    Point* p2 = new Point(5, 5);

    p1->Print();
    p2->Print();

    delete p1;
    delete p2;

    // smart pointer
    PointPtr pp1 = new Point(2, 3);
    PointPtr pp2 = new Point(5, 5);

    pp1->Print();
    pp2->Print();
    (*pp1).Print();
    (*pp2).Print();
    // don't need to use delete to free the assigned memory

    return 0;
}