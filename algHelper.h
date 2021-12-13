#include <iostream>
#include <typeinfo>
#include <algorithm>
using namespace std;

template <typename T>
void ShowAll(const T& ref)
{
    for(auto i=ref.begin(); i!=ref.end(); ++i)
        cout<<*i<<' ';
    cout<<endl;
}

template<typename T>
void ShowAllMap(const T& m)
{
    for(auto iter=m.begin(); iter!=m.end(); ++iter)
        cout<<'('<<iter->first<<','<<iter->second<<") ";
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

bool Predicator1(const int& first, const int& second)
{
    return first + second > 50;
}

bool Predicator2(const int& num)
{
    return num>0;
}