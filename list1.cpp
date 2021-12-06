#include <list>
#include <iostream>
using namespace std;

int main(void)
{
    list<char> coll;
    for(char c='a'; c<'z'+1; c++)
        coll.push_back(c);
    
    for (auto elem : coll)
        cout<<elem<<" ";

    cout<<endl;

    return 0;
}