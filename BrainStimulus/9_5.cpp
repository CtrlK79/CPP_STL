#include "funobjHelper.h"
using namespace common;
using namespace fo9_5;
/*
 * <Nagator>
 * not1 : unary predicate
 * not2 : binary predicate
 */

int main(void)
{
    less<int> oLess;
    // binary_negate<less<int>> negate = not2(less<int>());
    auto negate = not2(less<int>());

    cout<<TorF(negate(5, 10))<<':'<<TorF(not2(oLess)(5, 10))<<':'<<TorF(not2(less<int>())(5, 10))<<endl;
    // cout<<TorF(greater_equal<int>()(5, 10))<<endl; // same result
    cout<<TorF(negate(10, 10))<<':'<<TorF(not2(oLess)(10, 10))<<':'<<TorF(not2(less<int>())(10, 10))<<endl;
    cout<<TorF(negate(20, 10))<<':'<<TorF(not2(oLess)(20, 10))<<':'<<TorF(not2(less<int>())(20, 10))<<endl;

    return 0;
}
