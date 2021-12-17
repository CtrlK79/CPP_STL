// Nonmodifying algorithms : do not change elements of a container


#include <vector>
#include <deque>
#include "algHelper.h"
using namespace common;
using namespace alg8_1;

int main()
{
    SplitSector(); // adjacent_find()
    vector<int> v1;
    for(auto i=0; i<10; ++i)
    {
        v1.push_back(10*(i+1));
        if(i%4 == 3)
            v1.push_back(10*(i+1));
    }
    cout<<"v1: "; ShowAll(v1);

    auto iter1 = adjacent_find(v1.begin(), v1.end());
    if(iter1!=v1.end())
        cout<<"adjacent_find(v1.begin(), v1.end()): "<<*iter1<<endl;
    else
        cout<<"there is not a pair of same adjacent elements in v1"<<endl;
    cout<<endl;

    v1.clear();
    for(auto i=0; i<10; ++i)
    {
        v1.push_back(10*(i+1));
        // if(i%4 == 3)
        //    v1.push_back(10*(i+1));
    }
    cout<<"v1: "; ShowAll(v1);
    iter1 = adjacent_find(v1.begin(), v1.end());
    if(iter1!=v1.end())
        cout<<"adjacent_find(v1.begin(), v1.end()): "<<*iter1<<endl;
    else
        cout<<"there is not a pair of same adjacent elements in v1"<<endl;

    iter1 = adjacent_find(v1.begin(), v1.end(), Predicator1); // bool Predicator1(const int& first, const int& second) {return first+second>50;}
    if(iter1!=v1.end())
        cout<<"adjancent elemenets "<<*iter1<<'+'<<*++iter1<<">50"<<endl;
    else
        cout<<"there are not adjancent elemenets with sum over 50"<<endl;


    SplitSector(); // count(), count_if()
    vector<int> v2;
    v2.push_back(10); v2.push_back(20); v2.push_back(30);
    v2.push_back(50); v2.push_back(90); v2.push_back(-100);
    cout<<"v2: "; ShowAll(v2);

    cout<<"# of 30s in v2: "<<count(v2.begin(), v2.end(), 30)<<endl;
    cout<<"# of positive numbers in v2: "<<count_if(v2.begin(), v2.end(), Predicator2)<<endl; // bool Predicator2(const int& num) {return num>0}
    
    
    SplitSector(); // equal()
    vector<int> v3; vector<int> v33;
    v3.push_back(10); v3.push_back(20); v3.push_back(30);
    v33.push_back(10); v33.push_back(20); v33.push_back(30); v33.push_back(40); v33.push_back(50);
    cout<<"v3: "; ShowAll(v3);
    cout<<"v33: "; ShowAll(v33);
    cout<<"v3 and v33 are equal: "<<TorF(equal(v3.begin(), v3.end(), v33.begin()))<<endl;
    // it returns [v3.begin(), v3.end()) == [v33.begin(), v33.begin()+(v3.end()-v3.begin()))...
    // below code results in different output
    cout<<"v3 and v33 are equal: "<<TorF(equal(v33.begin(), v33.end(), v3.begin()))<<endl;
    
    v3.clear(); v33.clear();
    v3.push_back(10); v3.push_back(21); v3.push_back(30);
    v33.push_back(10); v33.push_back(20); v33.push_back(33);
    cout<<"v3: "; ShowAll(v3);
    cout<<"v33: "; ShowAll(v33);
    cout<<"differences between v3 and v33 are under 5: "<<equal(v3.begin(), v3.end(), v33.begin(), Predicator3);
    // bool Predicator3(const int& left, const int& right){return abs(left-right)<5;}


    SplitSector(); // find(), find_if()
    vector<int> v4;
    for(auto i=0; i<5; ++i)
        v4.push_back(10*(i+1));
    cout<<"v4: ";ShowAll(v4);
    
    auto iter4 = find(v4.begin(), v4.end(), 20);
    if(iter4!=v4.end())
        cout<<"20 is in v4!"<<endl;
    else
        cout<<"20 is not in v4..."<<endl;

    iter4 = find_if(v4.begin(), v4.end(), Predicator4);
    cout<<"the first elemement which is greater than 35: "<<*iter4<<endl;


    SplitSector(); // find_end(), search()... find_end() return last sequence, search() return first sequence
    vector<int> v5; vector<int> v55;
    for(auto i=0; i<7; ++i)
        v5.push_back(10*(i+1));
    v5.push_back(30); v5.push_back(40); v5.push_back(50);
    v55.push_back(30); v55.push_back(40); v55.push_back(50);

    auto iter5 = find_end(v5.begin(), v5.end(), v55.begin(), v55.end());
    // return last sequence same with [v55.begin(), v55.end())
    if(iter5!=v5.end())
        cout<<"(30, 40, 50) sequence is in v5"<<endl;
    
    cout<<"search(): ";
    for(auto i=search(v5.begin(), v5.end(), v55.begin(), v55.end()); i!=v5.end(); ++i)
        cout<<*i<<' ';
    cout<<endl;
    cout<<"find_end(): ";
    for(auto i=find_end(v5.begin(), v5.end(), v55.begin(), v55.end()); i!=v5.end(); ++i)
        cout<<*i<<' ';
    cout<<endl;
    
    v5.clear(); v55.clear();
    v5.push_back(10); v5.push_back(15); v5.push_back(20); v5.push_back(40); v5.push_back(50);
    v5.push_back(60); v5.push_back(10); v5.push_back(11); v5.push_back(12); v5.push_back(80);
    v55.push_back(10); v55.push_back(15); v55.push_back(25);
    cout<<"v5: "; ShowAll(v5);
    cout<<"v55: "; ShowAll(v55);

    iter5 = find_end(v5.begin(), v5.end(), v55.begin(), v55.end(), Predicator5);
    // find sequence in v5 satisfying Predicator5 applied with v55.
    for(;iter5!=v5.end(); ++iter5)
        cout<<*iter5<<' ';
    cout<<endl;
    

    SplitSector(); // find_first_of()
    vector<int> v6; vector<int> v66;
    for(auto i=0; i<5; ++i)
        v6.push_back(10*(i+1));
    v66.push_back(40); v66.push_back(80); v66.push_back(20);
    cout<<"v6: "; ShowAll(v6);
    cout<<"v66: "; ShowAll(v66);
    cout<<"iter: "<<*find_first_of(v6.begin(), v6.end(), v66.begin(), v66.end())<<endl;
    cout<<"iter: "<<*find_first_of(v66.begin(), v66.end(), v6.begin(), v6.end())<<endl;
    // return iterator pointing the first element which is also in the other container...

    deque<int> dq6;
    dq6.push_front(30); dq6.push_front(40); dq6.push_front(80);
    cout<<"iter: "<<*find_first_of(v6.begin(), v6.end(), dq6.begin(), dq6.end())<<endl;

    cout<<"iter: "<<*find_first_of(v6.begin(), v6.end(), dq6.begin(), dq6.end(), Predicator6)<<endl;
    // boold Predicator6(const int& left, const int& right) {return left>right;} // return the first element which is greater than 30 or 40 or 80


    SplitSector(); // for_each()
    vector<int> v7;
    for(auto i=0; i<5; ++i)
        v7.push_back(10*(i+1));
    
    for_each(v7.begin(), v7.end(), Print<int>); // apply Print to each element from v7.begin() to v7.end()...
    cout<<endl;
    for_each(v7.begin(), v7.begin()+2, Print<int>);
    cout<<endl;

    for_each(v7.begin(), v7.end(), PrintFunctor('~'));
    cout<<endl;


    SplitSector(); // lexicographical_compare()
    vector<int> v8; vector<int> v88; vector<int> v888;
    v8.push_back(10); v8.push_back(20); v8.push_back(30);
    v88.push_back(10); v88.push_back(20); v88.push_back(50);
    v888.push_back(10); v888.push_back(30); v888.push_back(20);
    cout<<"v8: ";ShowAll(v8);
    cout<<"v88: ";ShowAll(v88);
    cout<<"v888: ";ShowAll(v888);

    // compare values in a lexicographical manners...
    if(lexicographical_compare(v8.begin(), v8.end(), v88.begin(), v88.end()))
        cout<<"v8 < v88"<<endl;
    else
        cout<<"v8 >= v88"<<endl;

    if(lexicographical_compare(v8.begin(), v8.end(), v888.begin(), v888.end()))
        cout<<"v8 < v888"<<endl;
    else
        cout<<"v8 >= v888"<<endl;
    
    v8.clear(); v88.clear();
    v8.push_back(10); v8.push_back(20); v8.push_back(30);
    v88.push_back(10); v88.push_back(25); v88.push_back(30);
    cout<<"v8: "; ShowAll(v8);
    cout<<"v88: "; ShowAll(v88);
    cout<<"compare v1 and v2 based on less<int>... "<<TorF(lexicographical_compare(v8.begin(), v8.end(), v88.begin(), v88.end(), less<int>()))<<endl;
    cout<<"compare v1 and v2 based on greater<int>... "<<TorF(lexicographical_compare(v8.begin(), v8.end(), v88.begin(), v88.end(), greater<int>()))<<endl;
    cout<<"compare v1 and v2 based on Less<int>... "<<TorF(lexicographical_compare(v8.begin(), v8.end(), v88.begin(), v88.end(), Less<int>()))<<endl;


    SplitSector(); // max(), min()
    int a9=10, b9=20; cout<<"a9: "<<a9<<','<<"b9: "<<b9<<endl;
    int r;

    r = max(a9, b9); cout<<"max: "<<r<<endl;
    r = min(a9, b9); cout<<"min: "<<r<<endl;
    
    Point pt1(5, 8), pt2(3, 9);
    Point pt3;

    cout<<"pt1: "; pt1.Print();
    cout<<"pt2: "; pt2.Print();

    pt3 = max(pt1, pt2, XCompare); // return Point satisfying XCompare
    cout<<"x max: "; pt3.Print();
    pt3 = max(pt1, pt2, YCompare);
    cout<<"y max: "; pt3.Print();
    //cout<<&pt3<<','<<&pt2<<endl; // pt3 and pt2 are different objects with different addresses...


    SplitSector(); // max_element(), min_element()
    vector<int> vv1;
    vv1.push_back(30); vv1.push_back(10); vv1.push_back(20); vv1.push_back(50); vv1.push_back(40);
    cout<<"vv1: "; ShowAll(vv1);
    cout<<"max element: "<<*max_element(vv1.begin(), vv1.end())<<endl;
    cout<<"min element: "<<*min_element(vv1.begin(), vv1.end())<<endl;

    vector<Point> vv11;
    vv11.push_back(Point(3, 2)); vv11.push_back(Point(2, 5)); vv11.push_back(Point(1, 5));
    vv11.push_back(Point(3, 3)); vv11.push_back(Point(3, 2));

    cout<<"elements of v10{ "<<endl;
    for(auto iter=vv11.begin(); iter!=vv11.end(); ++iter)
        iter->Print();
    cout<<"}"<<endl;
    cout<<"max element: "; max_element(vv11.begin(), vv11.end(), Compare)->Print();


    SplitSector(); // mismatch()
    vector<int> vv2; vector<int> vv22;
    for(auto i=0; i<5; i++)
        vv2.push_back(10*(i+1));
    vv22.push_back(10); vv22.push_back(20); vv22.push_back(30); vv22.push_back(80); vv22.push_back(90);
    cout<<"vv2: "; ShowAll(vv2);
    cout<<"vv22: "; ShowAll(vv22);
    auto iter_pair_vv2 = mismatch(vv2.begin(), vv2.end(), vv22.begin());
    cout<<"mismatch: "<<"vv2 - "<<*(iter_pair_vv2.first)<<", vv22 - "<<*(iter_pair_vv2.second)<<endl;

    vv2.clear(); vv22.clear();
    for(auto i=0; i<5; ++i)
        vv2.push_back(10*(i+1));
    vv22.push_back(11); vv22.push_back(25); vv22.push_back(33); vv22.push_back(46); vv22.push_back(50);
    iter_pair_vv2 = mismatch(vv2.begin(), vv2.end(), vv22.begin(), Predicator3);
    cout<<"mismatch with Predicator3: "<<"vv2 - "<<*(iter_pair_vv2.first)<<", vv22 - "<<*(iter_pair_vv2.second)<<endl;


    SplitSector(); // search_n()
    // find n consecutive same elements
    vector<int> vv3;
    for(auto i=0; i<5; ++i)
    {
        vv3.push_back(10*(i+1));

        if(!(i-2)){vv3.push_back(10*(i+1)); vv3.push_back(10*(i+1));}
    }
    cout<<"vv3: "; ShowAll(vv3);
    
    auto iter_vv3 = search_n(vv3.begin(), vv3.end(), 3, 30); // find consecutive 30s 3 times or more
    for(auto iter=iter_vv3-1; iter!=iter_vv3+4; ++iter)
        cout<<*iter<<' ';
    cout<<endl;

    vv3.clear();
    vv3.push_back(10); vv3.push_back(20); vv3.push_back(32); vv3.push_back(28);
    vv3.push_back(33); vv3.push_back(40); vv3.push_back(50);
    cout<<"vv3: "; ShowAll(vv3);
    iter_vv3 = search_n(vv3.begin(), vv3.end(), 3, 30, Predicator3);
    for(auto iter=iter_vv3; iter!=vv3.end(); ++iter)
        cout<<*iter<<' ';
    cout<<endl;

    return 0;
}