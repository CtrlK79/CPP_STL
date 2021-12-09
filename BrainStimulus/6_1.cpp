#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    v.push_back(10); v.push_back(20); v.push_back(30); v.push_back(40); v.push_back(50);

    // size() : returns the number of elements
    // capacity() : returns the size of the allocated memory
    // max_size() : maximum number of elements which this container can contain
    for(vector<int>::size_type i=0; i<v.size(); ++i)
        cout<<v[i]<<' ';
    cout<<typeid(vector<int>::size_type).name()<<endl<<endl;
    cout<<"size(): "<<v.size()<<endl;
    cout<<"capacity(): "<<v.capacity()<<endl;
    cout<<"max_size(): "<<v.max_size()<<endl;
}