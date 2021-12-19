#include "funobjHelper.h"
using namespace common;
using namespace fo9_1;
/*
 * <Arithemetic>
 * plus<T> : binary operator +
 * minus<T> : binary operator -
 * multiplies<T> : binary operator *
 * divides<T> : binary operator /
 * modulus<T> : binary operator %
 * negate<T> : unary operator -
 */

int main(void)
{
    SplitSector();
    plus<int> oPlus1;
    cout<<oPlus1(10, 20)<<endl;
    cout<<oPlus1.operator()(10, 20)<<endl;
    cout<<plus<int>()(10, 20)<<endl;
    cout<<plus<int>().operator()(10, 20)<<endl;


    SplitSector();
    Plus<int> oPlus2;
    cout<<oPlus2(10, 20)<<endl;
    cout<<oPlus2.operator()(10, 20)<<endl;
    cout<<Plus<int>()(10, 20)<<endl;
    cout<<Plus<int>().operator()(10, 20)<<endl;


    SplitSector();
    vector<int> v1; vector<int> v2;
    for(auto i=0; i<5; ++i)
    {   
        v1.push_back(10*(i+1));
        v2.push_back(i+1);
    }
    vector<int> v3(5);
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), plus<int>());
    cout<<"v3: "; ShowAll(v3);
    transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), multiplies<int>());
    cout<<"v3: "; ShowAll(v3);
    transform(v1.begin(), v1.end(), v3.begin(), negate<int>());
    cout<<"v3: "; ShowAll(v3);

    return 0;
}
