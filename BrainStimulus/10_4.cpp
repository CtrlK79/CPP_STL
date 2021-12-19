#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main()
{
    vector<int> v;
    for(auto i=0; i<5; ++i)
        v.push_back(10*(i+1));
    cout<<"v: "; copy(v.begin(), v.end(), ostream_iterator<int>(cout)); cout<<endl;
    cout<<"v: "; copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", ")); cout<<endl;

    list<int> lt;
    lt.push_back(100); lt.push_back(200); lt.push_back(300);
    cout<<"lt+v: ";
    transform(lt.begin(), lt.end(), v.begin(), ostream_iterator<int>(cout, " "), plus<int>());
    cout<<endl;

    v.clear(); lt.clear();
    cout<<endl;


    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter<vector<int>>(v));
    cout<<"v: "; copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", ")); cout<<endl;

    return 0;
}