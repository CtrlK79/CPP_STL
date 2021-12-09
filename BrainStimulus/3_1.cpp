#include <iostream>
using namespace std;

void Print() {cout<<"global function!"<<endl;}

struct Functor1 // functor... functor has better performance than function... and it can contain other member variables and functions... more flexible and powerful
{
    void operator()() {cout<<"functor!"<<endl;}
};

struct Functor2
{
    void operator()(int a, int b) {cout<<"functor: "<<a<<','<<b<<endl;}
};

class Adder
{
private:
    int total;
public:
    explicit Adder(int n=0) : total(n) {}
    int operator()(int n) {return total+=n;}
};

int main()
{
    Functor1 functor1;
    Functor2 functor2;

    Print();
    functor1();
    functor2(1, 2);
    

    Adder add(0);
    cout<<add(10)<<endl;
    cout<<add(20)<<endl;
    cout<<add(30)<<endl;
    cout<<Adder().operator()(10)<<endl;
    cout<<Adder().operator()(10)<<endl;
    cout<<Adder()(10)<<endl;

    return 0;
}