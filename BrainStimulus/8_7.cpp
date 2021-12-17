// Numeric algorithms : these are defined in <numeric> header
#include <numeric>
#include <vector>
#include "algHelper.h"
using namespace alg8_7;

int main()
{
    SplitSector(); // accumulate()
    vector<int> v1;
    for(auto i=0; i<5; ++i)
        v1.push_back(10*(i+1));
    cout<<"v1: "; ShowAll(v1);
    cout<<accumulate(v1.begin(), v1.end(), 0)<<endl;
    cout<<accumulate(v1.begin(), v1.begin()+4, 100)<<endl;
    cout<<endl;

    cout<<accumulate(v1.begin(), v1.end(), 0, Plus1<int>())<<endl;
    cout<<accumulate(v1.begin(), v1.end(), 1, multiplies<int>())<<endl;


    SplitSector(); // inner_product()
    vector<int> v2; vector<int> v22;
    for(auto i=0; i<5; ++i)
    {    
        v2.push_back(i+1); v22.push_back(2);
    }
    cout<<inner_product(v2.begin(), v2.end(), v22.begin(), 0)<<endl;
    cout<<inner_product(v2.begin(), v2.end(), v22.begin(), 100)<<endl;

    cout<<inner_product(v2.begin(), v2.end(), v22.begin(), 0, Plus11, Minus1)<<endl;
    // return 0 + (1-2) + (2-2) + (3-2) + (4-2) + (5-2)


    SplitSector(); // adjacent_difference()
    vector<int> v3;
    for(auto i=0; i<5; ++i)
        v3.push_back(10*(i+1));
    cout<<"v3: "; ShowAll(v3);
    vector<int> v33(5);
    auto iter_end_v3 = adjacent_difference(v3.begin(), v3.end(), v33.begin());
    cout<<"v33: "; ShowAll(v33); // the first element of v33 is same with v3.
    cout<<endl;

    iter_end_v3 = adjacent_difference(v3.begin(), v3.end(), v33.begin(), plus<int>());
    cout<<"v33: "; ShowAll(v33);


    SplitSector(); // partial_sum()
    vector<int> v4;
    for(auto i=0; i<5; ++i)
        v4.push_back(10*(i+1));
    cout<<"v4: "; ShowAll(v4);
    vector<int> v44(5);
    auto iter_end_v4 = partial_sum(v4.begin(), v4.end(), v44.begin());
    cout<<"v44: "; ShowAll(v44);
    cout<<endl;

    iter_end_v4 = partial_sum(v4.begin(), v4.end(), v44.begin(), multiplies<int>());
    cout<<"v44: "; ShowAll(v44);
    iter_end_v4 = partial_sum(v4.begin(), v4.end(), v44.begin(), minus<int>());
    cout<<"v44: "; ShowAll(v44);

    return 0;
}