// Sorted range algorithms : these work only on sorted range.
// when it performs equivalance, it doesn't use == but !(<) && !(>)
#include <vector>
#include "algHelper.h"
using namespace alg8_6;

int main()
{
    SplitSector(); // binary_search()
    // it works on sorted(with less) sequence...
    vector<int> v1;
    for(auto i=0; i<5; ++i)
        v1.push_back(10*(i+1));
    cout<<"v1: "; ShowAll(v1);
    cout<<"20 is in v1: "<<TorF(binary_search(v1.begin(), v1.end(), 20))<<endl;
    cout<<endl;

    v1.clear();
    v1.push_back(40); v1.push_back(46); v1.push_back(12); v1.push_back(80);
    v1.push_back(10); v1.push_back(47); v1.push_back(30); v1.push_back(50);
    v1.push_back(90); v1.push_back(53);
    cout<<"v1: "; ShowAll(v1);
    sort(v1.begin(), v1.end(), Predicator1);
    cout<<"v1: "; ShowAll(v1);
    cout<<"32: "<<TorF(binary_search(v1.begin(), v1.end(), 32, Predicator1))<<endl;
    cout<<"35: "<<TorF(binary_search(v1.begin(), v1.end(), 35, Predicator1))<<endl;
    cout<<"38: "<<TorF(binary_search(v1.begin(), v1.end(), 38, Predicator1))<<endl;
    
    
    SplitSector(); // includes()
    vector<int> v2;
    for(auto i=0; i<5; ++i)
        v2.push_back(10*(i+1));
    vector<int> v22;
    v22.push_back(10); v22.push_back(20); v22.push_back(40);
    vector<int> v222;
    v222.push_back(10); v222.push_back(20); v222.push_back(60);
    cout<<"v2: "; ShowAll(v2);
    cout<<"v22: "; ShowAll(v22);
    cout<<"v222: "; ShowAll(v222);
    cout<<"v22 is in v2: "<<TorF(includes(v2.begin(), v2.end(), v22.begin(), v22.end()))<<endl;
    cout<<"v222 is in v2: "<<TorF(includes(v2.begin(), v2.end(), v222.begin(), v222.end()))<<endl;


    SplitSector(); // lower_bound(), upper_bound(), equal_range()
    vector<int> v3;
    v3.push_back(10); v3.push_back(20); v3.push_back(30); v3.push_back(30);
    v3.push_back(30); v3.push_back(40); v3.push_back(50);
    cout<<"v3: "; ShowAll(v3);
    cout<<"30s in v3(using lower_bound(), upper_bound()): ";
    for(auto iter=lower_bound(v3.begin(), v3.end(), 30); iter!=upper_bound(v3.begin(), v3.end(), 30); ++iter)
        cout<<*iter<<' ';
    cout<<endl;

    cout<<"30s in v3(using equal_range()): ";
    auto iter_pair_v3 = equal_range(v3.begin(), v3.end(), 30);
    for(auto iter=iter_pair_v3.first; iter!=iter_pair_v3.second; ++iter)
        cout<<*iter<<' ';
    cout<<endl;


    SplitSector(); // merge(), inplace_merge()
    vector<int> v4;
    for(auto i=0; i<5; ++i)
        v4.push_back(10*(i+1));
    vector<int> v44;
    v44.push_back(20); v44.push_back(30); v44.push_back(60);
    vector<int> v444(10);
    cout<<"v4: "; ShowAll(v4);
    cout<<"v44: "; ShowAll(v44);
    cout<<"v444: "; ShowAll(v444);
    cout<<"---after merge()---"<<endl;;
    auto iter_end_v4 = merge(v4.begin(), v4.end(), v44.begin(), v44.end(), v444.begin());
    cout<<"v4: "; ShowAll(v4);
    cout<<"v44: "; ShowAll(v44);
    cout<<"v444: "; ShowAll(v444);
    cout<<"v444 until iter_end_v4: ";
    for(auto iter=v444.begin(); iter!=iter_end_v4; ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    cout<<endl;

    v4.clear();
    for(auto i=0; i<5; ++i)
        v4.push_back(10*(i+1));
    v4.push_back(20); v4.push_back(30); v4.push_back(60);
    cout<<"v4: "; ShowAll(v4);
    inplace_merge(v4.begin(), v4.begin()+5, v4.end());
    cout<<"v4 after inplace_merge(): "; ShowAll(v4);


    SplitSector(); // set_union(), set_intersection(), set_difference(), set_symmetric_difference()
    vector<int> v5;
    for(auto i=0; i<5; ++i)
        v5.push_back(10*(i+1));
    vector<int> v55;
    v55.push_back(20); v55.push_back(30); v55.push_back(60);
    vector<int> v555(10);
    cout<<"v5: "; ShowAll(v5);
    cout<<"v55: "; ShowAll(v55);
    auto iter_end_v5 = set_union(v5.begin(), v5.end(), v55.begin(), v55.end(), v555.begin());
    cout<<"v555 until iter_end_v5: ";
    for(auto iter=v555.begin(); iter!=iter_end_v5; ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    cout<<"v555: "; ShowAll(v555);

    return 0;
}