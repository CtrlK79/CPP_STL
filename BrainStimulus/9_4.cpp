#include "funobjHelper.h"
using namespace common;
using namespace fo9_4;
/*
 * <Binder>
 * bind1st : fix the first argument of binary function
 * bind2nd : fix the second argument of binary function
 */

int main(void)
{
    SplitSector();
    // binder1st
    // binder1st<less<int>> binder = bind1st(less<int>(), 10);
    auto binder1 = bind1st(less<int>(), 10); // makes an unary predicate with fixed first argument, 10
    
    cout<<TorF(binder1(5))<<':'<<TorF(less<int>()(10, 5))<<endl;
    cout<<TorF(binder1(10))<<':'<<TorF(less<int>()(10, 10))<<endl;
    cout<<TorF(binder1(20))<<':'<<TorF(less<int>()(10, 20))<<endl;
    cout<<endl;

    cout<<TorF(bind1st(less<int>(), 10)(5))<<':'<<TorF(less<int>()(10, 5))<<endl;
    cout<<TorF(bind1st(less<int>(), 10)(10))<<':'<<TorF(less<int>()(10, 10))<<endl;
    cout<<TorF(bind1st(less<int>(), 10)(20))<<':'<<TorF(less<int>()(10, 20))<<endl;


    SplitSector();
    // binder2nd
    // binder2nd<less<int>> binder = bind2nd(less<int>(), 10);
    auto binder2 = bind2nd(less<int>(), 10); // makes an unary predicate with fixed second argument, 10

    cout<<TorF(binder2(5))<<':'<<TorF(less<int>()(5, 10))<<endl;
    cout<<TorF(binder2(10))<<':'<<TorF(less<int>()(10, 10))<<endl;
    cout<<TorF(binder2(20))<<':'<<TorF(less<int>()(20, 10))<<endl;
    cout<<endl;

    cout<<TorF(bind2nd(less<int>(), 10)(5))<<':'<<TorF(less<int>()(5, 10))<<endl;
    cout<<TorF(bind2nd(less<int>(), 10)(10))<<':'<<TorF(less<int>()(10, 10))<<endl;
    cout<<TorF(bind2nd(less<int>(), 10)(20))<<':'<<TorF(less<int>()(20, 10))<<endl;

    return 0;
}
