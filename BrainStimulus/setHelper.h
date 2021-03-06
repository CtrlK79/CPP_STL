#include <iostream>
#include <set>
#include <typeinfo>
using namespace std;

template <typename T>
void ShowAll(const T& ref)
{
    for(auto i=ref.begin(); i!=ref.end(); ++i)
        cout<<*i<<' ';
    cout<<endl;
}

void SplitSector()
{   
    static int n = 0;
    cout<<"=========="<<"Sector #"<<++n<<"=========="<<endl;
}

const char* TorF(const bool& tf)
{
    if(tf)
        return "TRUE";
    else
        return "FALSE";
}