#include <deque>
#include <iostream>
using namespace std;

int main(void)
{
    deque<float> coll;
    
    for(int i=0; i<7; i++)
        //coll.push_front(i*1.1);
        coll.push_back(i*1.1);
    for(int i=0; i<7; i++)
        cout<<coll[i]<<" ";
    cout<<endl;

    return 0;
}