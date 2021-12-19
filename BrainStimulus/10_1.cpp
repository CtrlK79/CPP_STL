#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // iterator : it supports reading and writing over the container
    // const_iterator : it only supports reading over the container
    vector<int> v;
    for(auto i=0; i<5; ++i)
        v.push_back(10*(i+1));
    
    cout<<"read elements by iterator: ";
    for(vector<int>::iterator iter=v.begin(); iter!=v.end(); ++iter)
        cout<<*iter<<' ';
    cout<<endl;

    cout<<"read elements by const_iterator: ";
    for(vector<int>::const_iterator iter=v.begin(); iter!=v.end(); ++iter)
        cout<<*iter<<' ';
    cout<<endl;

    vector<int>::iterator iter = v.begin();
    vector<int>::const_iterator citer = v.begin();
    const vector<int>::iterator const_iter = v.begin();
    const vector<int>::const_iterator const_citer = v.begin();

    // element change
    *iter = 100;
    // *citer = 200; // error!
    *const_iter = 300;
    // const_citer = 400; // error!

    // iterator change
    ++iter;
    ++citer;
    // ++const_iter; // error!
    // ++const_citer; // error!
    
    return 0;
}