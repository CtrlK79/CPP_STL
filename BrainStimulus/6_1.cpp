#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    for(auto i=0;i<5;i++)
        v.push_back(10*(i+1));

    // size() : returns the number of elements
    // capacity() : returns the size of the allocated memory
    // max_size() : maximum number of elements which this container can contain
    for(vector<int>::size_type i=0; i<v.size(); ++i)
        cout<<v[i]<<' ';
    cout<<typeid(vector<int>::size_type).name()<<endl<<endl;
    cout<<"size(): "<<v.size()<<endl;
    cout<<"capacity(): "<<v.capacity()<<endl;
    cout<<"max_size(): "<<v.max_size()<<endl;
    cout<<endl;

    // capacity()
    vector<int> vv;
    for(auto i=0;i<10;i++)
    {
        cout<<"size: "<<vv.size()<<", capacity: "<<vv.capacity()<<endl;
        vv.push_back(10*(i+1));
    }
    cout<<endl;

    // reserve() : allocate memory by user
    vector<int> vvv;
    vvv.reserve(10);
    for(auto i=0;i<10;i++)
    {
        cout<<"size: "<<vvv.size()<<", capacity: "<<vvv.capacity()<<endl;
        vvv.push_back(10*(i+1));
    }
}