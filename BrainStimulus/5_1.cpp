#include <iostream>
#include <vector>
using namespace std;

int main()
{

    // vector
    vector<int> v;

    v.push_back(10); // element can be added by push_back() (sequence containers : vector, deque, list)
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for(auto i=0; i<v.size(); ++i)
        cout<<v[i]<<endl; // elements can be accessed by [] operator (array-based containers : vector, deque)
    cout<<endl;

    for(auto iter=v.begin(); iter!=v.end(); ++iter) // iter is a 'vector<int>::iterator' object.
        cout<<*iter<<endl; // * operator to access the element which an iterator points.
    cout<<endl;

    auto iter = v.begin();
    cout<<iter[0]<<endl;
    cout<<iter[3]<<endl<<endl;;

    iter+=2;
    cout<<*iter<<endl<<endl;

    return 0;
}