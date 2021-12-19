#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main()
{
    vector<int> v1;
    for(auto i=0; i<5; ++i)
        v1.push_back(10*(i+1));
    
    vector<int> v2;
    // copy(v1.begin(), v1.end(), v2.begin()) // error!
    copy(v1.begin(), v1.end(), inserter<vector<int>>(v2, v2.begin()));
    cout<<"v1: "; for(auto iter=v1.begin(); iter!=v1.end(); ++iter){cout<<*iter<<' ';} cout<<endl;
    cout<<"v2: "; for(auto iter=v2.begin(); iter!=v2.end(); ++iter){cout<<*iter<<' ';} cout<<endl;
    cout<<endl;


    vector<int> v; for(auto i=0; i<5; ++i){v.push_back(10*(i+1));}
    list<int> lt1; for(auto i=0; i<3; ++i){lt1.push_back(i+1);}
    list<int> lt2; for(auto i=0; i<3; ++i){lt2.push_back(i+1);}
    copy(v.begin(), v.end(), back_inserter<list<int>>(lt1)); // push_back call
    copy(v.begin(), v.end(), front_inserter<list<int>>(lt2)); // push_front call
    cout<<"lt1: "; for(auto iter=lt1.begin(); iter!=lt1.end(); ++iter){cout<<*iter<<' ';} cout<<endl;
    cout<<"lt2: "; for(auto iter=lt2.begin(); iter!=lt2.end(); ++iter){cout<<*iter<<' ';} cout<<endl;

    return 0;
}