#include "funobjHelper.h"
using namespace common;
using namespace fo9_6;


int main(void)
{
    SplitSector();
    vector<int> v1;
    for(auto i=0; i<5; ++i)
        v1.push_back(10*(i+1));
    cout<<"# of elements 30<= and <=40 : "<<count_if(v1.begin(), v1.end(), Pred1)<<endl;
    // cout<<"# of elements 30> or >40 : "<<count_if(v1.begin(), v1.end(), not1(Pred1))<<endl; // error
    cout<<"# of elements 30> or >40 : "<<count_if(v1.begin(), v1.end(), not1(ptr_fun(Pred1)))<<endl; // transform function to functor...
    cout<<"# of elements 30> or >40 : "<<count_if(v1.begin(), v1.end(), not1(Ptr_fun(Pred1)))<<endl; // transform function to functor...

    return 0;
}
