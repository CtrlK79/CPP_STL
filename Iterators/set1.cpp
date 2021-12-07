#include <set>
#include <iostream>
using namespace std;

int main(void)
{
    typedef set<int> IntSet;
    //typedef set<int, greater<int>> IntSet; // sort the elements in descending order...

    IntSet coll;

    //coll.insert(3); coll.insert(1); coll.insert(5); coll.insert(4);
    //coll.insert(1); coll.insert(6); coll.insert(2);
    coll.insert({3, 1, 5, 4, 1, 6, 2});

    //for(auto pos = coll.cbegin(); pos != coll.cend(); ++pos)
    //for(const auto& elem : coll)
    IntSet::const_iterator pos;
    for(pos=coll.begin(); pos!=coll.end(); ++pos)
        std::cout<<*pos<<' ';
    cout<<endl;
}