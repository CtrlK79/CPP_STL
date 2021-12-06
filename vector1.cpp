#include <vector>
#include <iostream>
using namespace std;

int main(void)
{
    vector<int> coll;
    
    for(int i=0; i<7; i++)
        coll.push_back(i);
    
    for(int i=0; i<coll.size(); i++)
        cout<<coll[i]<<" ";
    
    cout<<endl;

    return 0;
}