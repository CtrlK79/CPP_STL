#include <iostream>
using namespace std;

template <typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf)
{
    while(begin != end)
    {
        pf(*begin++);
    }
}

void PrintInt(int data) {cout<<data<<" ";}
void PrintString(string data) {cout<<data<<" ";}

template <typename T>
void Print(T data) {cout<<data<<" ";}

template <typename T>
struct PrintFunctor
{
    string sep;

    explicit PrintFunctor(const string& s=" "):sep(s) {}

    void operator()(T data) {cout<<data<<sep;}
};

int main(void)
{
    PrintFunctor<int> pfi("!");
    PrintFunctor<string> pfs("!");

    int arr[5] = {10, 20, 30, 40, 50};
    For_each(arr, arr+5, PrintInt); // types of instances are automatically assigned
    cout<<endl;
    For_each(arr, arr+5, Print<int>);
    cout<<endl;
    For_each(arr, arr+5, PrintFunctor<int>());
    cout<<endl;
    For_each(arr, arr+5, pfi);
    cout<<endl<<endl;

    string sarr[3] = {"abc", "ABCDE", "Hello!"};
    For_each(sarr, sarr+3, PrintString);
    cout<<endl;
    For_each(sarr, sarr+3, Print<string>);
    cout<<endl;
    For_each(sarr, sarr+3, PrintFunctor<string>());
    cout<<endl;
    For_each(sarr, sarr+3, pfs);
    cout<<endl;

    return 0;
}