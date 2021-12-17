#include "funobjHelper.h"
using namespace common;
using namespace fo9_2;
/*
 * <Comparison operator objects>
 * equal_to<T> : binary operator ==
 * not_equal_to<T> : binary operator !=
 * less<T> : binary operator <
 * less_equal<T> : binary operator <=
 * greater<T> : binary operator >
 * greater_equal<T> : binary operator >=
 */

int main(void)
{
    SplitSector();
    less<int> oLess1;
    cout<<TorF(oLess1(10, 20))<<endl;
    cout<<TorF(oLess1.operator()(10, 20))<<endl;
    cout<<TorF(less<int>()(10, 20))<<endl;
    cout<<TorF(less<int>().operator()(10, 20))<<endl;

    
    SplitSector();
    Less<int> oLess2;
    cout<<TorF(oLess2(10, 20))<<endl;
    cout<<TorF(oLess2.operator()(10, 20))<<endl;
    cout<<TorF(Less<int>()(10, 20))<<endl;
    cout<<TorF(Less<int>().operator()(10, 20))<<endl;


    SplitSector();
    vector<int> v;
    for(auto i=0; i<5; ++i)
        v.push_back(10*(i+1));
    cout<<"v: "; ShowAll(v);
    cout<<"# of elements less than 20: "<<count_if(v.begin(), v.end(), bind2nd<less<int>>(less<int>(), 20))<<endl;
    cout<<"# of elements less than or equal to 20: "<<count_if(v.begin(), v.end(), bind2nd<less_equal<int>>(less_equal<int>(), 20))<<endl;

    return 0;
}
