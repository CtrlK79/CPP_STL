#include <utility>
#include <iostream>
using namespace std;

int main(void)
{
    pair<int, int> p1;
    
    cout<<"First default element of pair<int, int>: "<<p1.first<<endl;
    cout<<"Second default element of pair<int, int>: "<<p1.second<<endl<<endl;

    // Another way to access values in pair struct
    cout<<"First default element of pair<int, int>: "<<get<0>(p1)<<endl;
    cout<<"Second default element of pair<int, int>: "<<get<1>(p1)<<endl;

    pair<int, double> p2(5, 3.141595);
    pair<int, double> p3(2, 3.3029);
    pair<double, int> p4 = make_pair(get<1>(p2), get<0>(p2));
    swap(p2, p3);

    cout<<"p2: "<<p2.first<<", "<<p2.second<<endl;
    cout<<"p3: "<<p3.first<<", "<<p3.second<<endl;
    cout<<"p4: "<<p4.first<<", "<<p4.second<<endl;
}