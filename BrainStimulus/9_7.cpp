#include "funobjHelper.h"
using namespace common;
using namespace fo9_7;

int main()
{
    SplitSector();
    vector<Point> v1;
    for(auto i=0; i<5; ++i)
        v1.push_back(Point(i+1, i+1));
    for_each(v1.begin(), v1.end(), mem_fun_ref(&Point::Print)); // call member function by the object
    
    
    SplitSector();
    typedef Point* POINT_PTR;
    vector<POINT_PTR> v2;
    for(auto i=0; i<5; ++i)
        v2.push_back(new Point(i+1, i+1));
    for_each(v2.begin(), v2.end(), mem_fun(&Point::Print)); // call member function by the address of the object
    for_each(v2.begin(), v2.end(), Mem_fun(&Point::Print));

    return 0;
}