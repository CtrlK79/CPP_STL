#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(40); v.push_back(50);

    for(auto iter=v.begin(); iter!=v.end(); ++iter)
        cout<<*iter<<' ';
    cout<<endl;

    reverse_iterator<vector<int>::iterator> riter(v.end());
    reverse_iterator<vector<int>::iterator> end_riter(v.begin());
    for(; riter!=end_riter; ++riter)
        cout<<*riter<<' ';
    cout<<endl;

    for(auto iter=v.rbegin(); iter!=v.rend(); ++iter) // iter type is 'reverse_iterator<vector<int>::iterator>', and it has another typedef 'vector<int>::reverse_iterator'
        cout<<*iter<<' ';
    cout<<endl;

    return 0;
}