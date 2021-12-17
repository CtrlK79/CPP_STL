// Removing algorithms : these are special cases of modifying algorithms...
// these don't change the size of the container... it just overwrites the memory by other elements...

#include <vector>
#include "algHelper.h"
using namespace alg8_3;

int main()
{
    SplitSector(); // remove(), erase(), remove_if(), remove_copy(), remove_copy_if()
    vector<int> v1;
    for(auto i=0; i<5; ++i)
        v1.push_back(10*(i+1));
    cout<<"v1: "; ShowAll(v1);
    auto iter_end_v1 = remove(v1.begin(), v1.end(), 30); // remove the element 30
    cout<<"v1(until v1.end()): "; ShowAll(v1);
    cout<<"v1(until iter_end_v1): ";
    for(auto iter=v1.begin(); iter!=iter_end_v1; ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    cout<<endl;
    // size doesn't change...

    v1.clear();
    v1.push_back(10); v1.push_back(20); v1.push_back(30);
    v1.push_back(40); v1.push_back(30); v1.push_back(50);

    cout<<"v1: "; ShowAll(v1);
    cout<<"size of v1: "<<v1.size()<<", capacity of v1: "<<v1.capacity()<<endl;
    iter_end_v1 = remove(v1.begin(), v1.end(), 30);
    cout<<"v1 after remove(): "; ShowAll(v1);
    cout<<"size of v1: "<<v1.size()<<", capacity of v1: "<<v1.capacity()<<endl;
    v1.erase(iter_end_v1, v1.end());
    cout<<"v1 after erase(): "; ShowAll(v1);
    cout<<"size of v1: "<<v1.size()<<", capacity of v1: "<<v1.capacity()<<endl;
    cout<<endl;

    v1.clear();
    for(auto i=0; i<5; ++i)
        v1.push_back(10*(i+1));
    cout<<"v1: "; ShowAll(v1);
    v1.erase(remove_if(v1.begin(), v1.end(), Predicator1), v1.end());// bool Predicator(const int& n) {return 30<=n && n<=40;}
    cout<<"v1: "; ShowAll(v1);
    cout<<endl;

    v1.clear();
    for(auto i=0; i<5; ++i)
        v1.push_back(10*(i+1));
    cout<<"v1: "; ShowAll(v1);
    vector<int> v11(5);
    iter_end_v1 = remove_copy(v1.begin(), v1.end(), v11.begin(), 30);
    cout<<"v1: "; ShowAll(v1);
    cout<<"v11 from v11.begin() to v11.end(): "; ShowAll(v11);
    cout<<"v11 from v11.begin() to iter_end_v1: ";
    for(auto iter=v11.begin(); iter!=iter_end_v1; ++iter)
        cout<<*iter<<' ';
    cout<<endl;


    SplitSector(); // unique()
    vector<int> v2;
    v2.push_back(10); v2.push_back(20); v2.push_back(30); v2.push_back(30);
    v2.push_back(40); v2.push_back(40); v2.push_back(30); v2.push_back(50);
    cout<<"v2: "; ShowAll(v2);
    auto iter_end_v2 = unique(v2.begin(), v2.end());
    cout<<"v2: "; ShowAll(v2);
    v2.erase(iter_end_v2, v2.end());
    cout<<"v2: "; ShowAll(v2);
    cout<<endl;

    v2.clear();
    v2.push_back(10); v2.push_back(11); v2.push_back(30);
    v2.push_back(32); v2.push_back(40); v2.push_back(50);
    cout<<"v2: "; ShowAll(v2);
    v2.erase(unique(v2.begin(), v2.end(), Predicator2), v2.end());
    cout<<"v2: "; ShowAll(v2);

    return 0;
}