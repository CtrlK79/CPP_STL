#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    list<int> lt;
    v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(40); v.push_back(50);
    lt.push_back(10); lt.push_back(20); lt.push_back(30); lt.push_back(40); lt.push_back(50);

    auto iter = find(v.begin(), v.end(), 20); // iter type : vector<int>::iterator
    cout<<*iter<<endl<<endl;

    iter = find(v.begin(), v.end(), 100);
    if(iter==v.end())
        cout<<"100 is not here!"<<endl;
    cout<<endl;

    sort(v.begin(), v.end());
    //sort(lt.begin(), lt.end()); // error occurs... list supports bidirectional iterator

    vector<int> vv;
    vv.push_back(50); vv.push_back(10); vv.push_back(20); vv.push_back(40); vv.push_back(30);
    sort(vv.begin(), vv.end(), less<int>()); // ascending sort
    for(iter=vv.begin(); iter!=vv.end(); ++iter)
        cout<<*iter<<endl;
    cout<<endl;

    sort(vv.begin(), vv.end(), greater<int>()); // descending sort
    for(iter=vv.begin(); iter!=vv.end(); ++iter)
        cout<<*iter<<endl;
    cout<<endl;

    return 0;
}