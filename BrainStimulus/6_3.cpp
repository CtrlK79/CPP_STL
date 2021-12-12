#include <iostream>
#include <vector>
using namespace std;

#include "vectorHelper.h"

int main()
{
    vector<int> v1;
    for(auto i=0; i<5; i++)
        v1.push_back(10*(i+1));
    ShowAll(v1);
    vector<int>::iterator iter1 = v1.begin(); // ref
    vector<int>::const_iterator citer = v1.begin(); // const ref
    cout<<*iter1<<", "; cout<<*citer<<endl;
    cout<<*++iter1<<", "; cout<<*++citer<<endl;
    *iter1 = 100; // the element which iter ref is changed
    // *citer = 100; // the element which citer ref cannot be changed
    const vector<int>::iterator iter_const1 = v1.begin();
    const vector<int>::const_iterator citer_const1 = v1.begin();    
    // vector<int>::iterator is similar to int*
    // vector<int>::const_iterator is similar to const int*
    // const vector<int>::iterator is similar to  int* const
    // const vector<int>::const_iterator is similar to const int* const
    cout<<endl;


    vector<int> v2;
    for(auto i=0; i<5; i++)
        v2.push_back(10*(i+1));
    vector<int>::iterator iter2 = v2.begin()+2;
    vector<int>::iterator iter22;
    iter22 = v2.insert(iter2, 3, 100); // insert 3 100s in 3rd position of v2... and return the iterator ref to that position
    ShowAll(v2);
    cout<<endl;


    vector<int> v3;
    for(auto i=0; i<3; i++)
        v3.push_back(100*(i+1));
    auto iter3 = v3.begin();
    v3.insert(iter3, v2.begin(), v2.end());
    ShowAll(v3);
    auto iter33 = v3.begin();
    auto iter333 = v3.erase(iter33);
    ShowAll(v3); cout<<*iter333<<endl;
    auto iter3333 = v3.erase(v3.begin()+1, v3.end()); // return v3.end()
    ShowAll(v3);
    cout<<endl;


    vector<int> v4;
    for(auto i=0; i<5; i++)
        v4.push_back(10*(i+1));
    vector<int> v44(v4.begin(), v4.end());
    vector<int> v444; v444.assign(v4.begin(), v4.end());
    ShowAll(v44); ShowAll(v444);
    cout<<endl;
    
    
    vector<int> v5;
    for(auto i=0; i<5; i++)
        v5.push_back(10*(i+1));
    vector<int> v55;
    v55.push_back(10); v55.push_back(20); v55.push_back(50);
    cout<<(v5<v55)<<endl;
    cout<<endl;


    vector<int> v6(10, 1);
    v6.resize(5, 1); ShowSizeCap(v6); ShowAll(v6);
    v6.assign(3, 2); ShowSizeCap(v6); ShowAll(v6);

    return 0;
}

