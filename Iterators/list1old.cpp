#include <list>
#include <iostream>
using namespace std;

int main(void)
{
    list<char> coll;

    for(char c='a'; c<'z'+1; c++)
        coll.push_back(c);
    
    // pos type is list<char>::const_iterator pos
    for(auto pos = coll.cbegin(); pos!=coll.cend(); ++pos) // using pos++ makes this program slightly slower / cbegin() anc cend() return const::const_iterator.
        cout<<*pos<<" ";
    cout<<endl;

    /* below codes work in the same way
    for(const auto& elem : coll)
        cout<<elem<<" ";
    cout<<endl;

    in this code, const auto& is more preferable because auto elem makes unnecessary copies.
    */
}