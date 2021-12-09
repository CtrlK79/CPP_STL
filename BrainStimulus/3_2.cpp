#include <iostream>
using namespace std;

bool Pred_less(int a, int b) {return a<b;}
struct Less1
{
    bool operator()(int a, int b) {return a<b;}
};
typedef less<int> Less2;

int main()
{
    Less1 l;
    cout<<Pred_less(10, 20)<<endl;
    cout<<Pred_less(20, 10)<<endl;
    cout<<endl;
    cout<<l(10, 20)<<endl;
    cout<<l(20, 10)<<endl;
    cout<<Less1()(10, 20)<<endl;
    cout<<Less1()(20, 10)<<endl;
    cout<<endl;
    cout<<l.operator()(10, 20)<<endl;
    cout<<Less1().operator()(10, 20)<<endl<<endl;

    /******************************************/

    Less2 ll;
    cout<<ll(10, 20)<<endl;
    cout<<ll(20, 10)<<endl;
    cout<<ll.operator()(10, 20)<<endl;
    cout<<Less2()(10, 20)<<endl;
    cout<<Less2().operator()(10, 20)<<endl;
    cout<<less<int>()(10, 20)<<endl;
    cout<<plus<int>()(10, 20)<<endl;

    return 0;
}