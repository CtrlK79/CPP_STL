#include <iostream>
#include <deque>
using namespace std;

#include "vectorHelper.h"

int main()
{
    deque<int> dq1;
    for(auto i=0; i<10; ++i)
        dq1.push_back(10*(i+1));
    ShowAll(dq1);
    for(deque<int>::size_type i=0; i<dq1.size(); ++i) // deque also can access element by using [] operator
        cout<<dq1[i]<<' ';
    cout<<endl;
    dq1.push_front(100);
    ShowAll(dq1);
    cout<<endl;
    
    deque<int> dq2;
    for(auto i=0; i<10; ++i)
        dq2.push_back(10*(i+1));
    auto iter2 = dq2.begin()+2;
    auto iter22 = dq2.insert(iter2, 500);
    ShowAll(dq2); cout<<*iter22<<endl;


    return 0;
}