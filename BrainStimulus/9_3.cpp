#include "funobjHelper.h"
using namespace common;
using namespace fo9_3;
/*
 * <Logical operator objects>
 * logical_and<T> : binary operator &&
 * logical_or<T> : binary operator ||
 * logical_not<T> : unary operator !
 */

int main()
{
    const int n = 30;
    logical_and<int> oAnd1;
    cout<<TorF(oAnd1(greater<int>()(n, 10), less<int>()(n, 50)))<<endl;
    cout<<TorF(oAnd1.operator()(greater<int>()(n, 10), less<int>()(n, 50)))<<endl;
    cout<<TorF(logical_and<bool>()(greater<int>()(n, 10), less<int>()(n, 50)))<<endl;
    cout<<TorF(logical_and<bool>().operator()(greater<int>()(n, 10), less<int>()(n, 50)))<<endl;

}