#include <iostream>
#include <map>
using namespace std;

template <typename T>
void ShowAll(const T& m)
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