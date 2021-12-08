#include <iostream>
using namespace std;

struct FuncObject // an example of a function object
{
public:
    void operator()(int arg) const
    {
        cout<<"정수: "<<arg<<endl;
    }
    void operator()(int arg1, int arg2) const // operator() overloading
    {
        cout<<"정수: "<<arg1<<','<<arg2<<endl;
    }
    void operator()(int arg1, int arg2, int arg3) const
    {
        cout<<"정수: "<<arg1<<','<<arg2<<','<<arg3<<endl;
    }
};

void Print1(int arg)
{
    cout<<"Integer: "<<arg<<endl;
}

int main(void)
{
    void (*Print2)(int) = Print1; // function pointer
    FuncObject Print3;

    Print1(10);
    Print2(10);
    Print3(10);

    /***********************/
    FuncObject print;
    
    print(10); // implicit call by an object
    print(10, 20);
    print(10, 20, 30);
    cout<<endl;

    print.operator()(10); // explicit call
    print.operator()(10, 20);
    print.operator()(10, 20, 30);
    cout<<endl;

    FuncObject()(10); // implicit call by a temporary object
    FuncObject()(10, 20);
    FuncObject()(10, 20, 30);
    cout<<endl;

    FuncObject().operator()(10); // explicit call by a temporary object
    FuncObject().operator()(10, 20);
    FuncObject().operator()(10, 20, 30);

    // temporary object can be created by FuncObject()
    return 0;
}