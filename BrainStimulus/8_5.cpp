// Sorting algorithms : these are special cases of mutating algorithms...
// these change the order of elements and sort those...

#include <vector>
#include <typeinfo>
#include "algHelper.h"
using namespace common;
using namespace alg8_5;

int main()
{
    SplitSector(); // make_heap(), push_heap(), pop_heap(), sort_heap()
    vector<int> v1;
    for(auto i=0; i<6; ++i)
        v1.push_back(10*(i+1));
    cout<<"v1 vector:\t\t\t"; ShowAll(v1);
    make_heap(v1.begin(), v1.end());
    cout<<"v1 after make_heap():\t\t"; ShowAll(v1);
    v1.push_back(35);
    cout<<"v1 after push_back(35):\t\t"; ShowAll(v1);
    push_heap(v1.begin(), v1.end());
    cout<<"v1 after push_heap():\t\t"; ShowAll(v1);
    pop_heap(v1.begin(), v1.end());
    cout<<"v1 after pop_heap():\t\t"; ShowAll(v1);
    cout<<endl;

    v1.clear();
    v1.push_back(10); v1.push_back(40); v1.push_back(30);
    v1.push_back(50); v1.push_back(20); v1.push_back(60);
    cout<<"v1 vector:\t\t\t"; ShowAll(v1);
    make_heap(v1.begin(), v1.end());
    cout<<"v1 after make_heap():\t\t"; ShowAll(v1);
    sort_heap(v1.begin(), v1.end());
    cout<<"v1 after sort_heap():\t\t"; ShowAll(v1);
    cout<<endl;

    v1.clear(); // using greater<int>()...
    v1.push_back(10); v1.push_back(40); v1.push_back(30);
    v1.push_back(50); v1.push_back(20); v1.push_back(60);
    cout<<"v1 vector:\t\t\t"; ShowAll(v1);
    make_heap(v1.begin(), v1.end(), greater<int>());
    cout<<"v1 after make_heap():\t\t"; ShowAll(v1);
    v1.push_back(35);
    cout<<"v1 after push_back(35):\t\t"; ShowAll(v1);
    push_heap(v1.begin(), v1.end(), greater<int>());
    cout<<"v1 after push_heap():\t\t"; ShowAll(v1);
    sort_heap(v1.begin(), v1.end(), greater<int>());
    cout<<"v1 after sort_heap():\t\t"; ShowAll(v1);


    SplitSector(); // nth_element()
    vector<int> v2;
    for(auto i=0; i<100; ++i)
        v2.push_back(rand() % 1000);
    nth_element(v2.begin(), v2.begin()+20, v2.end());
    cout<<"v2's smallest 20 elements: ";
    for(auto iter=v2.begin(); iter!=v2.begin()+20; ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    cout<<"rest of v2: ";
    for(auto iter=v2.begin()+20; iter!=v2.end(); ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    cout<<endl;
    
    nth_element(v2.begin(), v2.begin()+20, v2.end(), greater<int>());
    cout<<"v2's largest 20 elements: ";
    for(auto iter=v2.begin(); iter!=v2.begin()+20; ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    cout<<"rest of v2: ";
    for(auto iter=v2.begin()+20; iter!=v2.end(); ++iter)
        cout<<*iter<<' ';
    cout<<endl;


    SplitSector(); // sort(), stable_sort(), partial_sort()
    vector<int> v3;
    for(auto i=0; i<100; ++i)
        v3.push_back(rand()%1000);
    cout<<"v3 before sorting: "; ShowAll(v3);
    cout<<endl;

    sort(v3.begin(), v3.end());
    cout<<"v3 after sorting with less(default): "; ShowAll(v3);
    cout<<endl;

    sort(v3.begin(), v3.end(), Greater);
    cout<<"v3 after sorting with greater<int>(): "; ShowAll(v3);
    cout<<endl;

    vector<int>().swap(v3); v3.reserve(7);
    v3.push_back(30); v3.push_back(50); v3.push_back(30); v3.push_back(20);
    v3.push_back(40); v3.push_back(10); v3.push_back(40);

    cout<<"v3 before sorting: "; ShowAll(v3);
    stable_sort(v3.begin(), v3.end()); // stable_sort() maintains the order among the elements with the same value
    cout<<"v3 after sorting with less(default): "; ShowAll(v3);
    cout<<endl;

    v3.clear(); v3.reserve(100);
    for(auto i=0; i<100; ++i)
        v3.push_back(rand()%1000);
    partial_sort(v3.begin(), v3.begin()+20, v3.end());
    cout<<"v3 with partial_sort: ";
    for(auto iter=v3.begin(); iter!=v3.begin()+20; ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    cout<<"after 20 elements: ";
    for(auto iter=v3.begin()+20; iter!=v3.end(); ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    cout<<endl;

    vector<int> v33(30);
    partial_sort_copy(v3.begin(), v3.end(), v33.begin(), v33.end());
    cout<<"v33: "; ShowAll(v33);

    return 0;
}