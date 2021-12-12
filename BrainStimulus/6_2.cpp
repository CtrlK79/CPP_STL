#include <iostream>
#include <vector>
using namespace std;

#include "vectorHelper.h"

int main()
{
    vector<int> v1(5); // initialize vector<int> with 5 0s.
    for(auto i=0; i<5; i++)
        v1.push_back(10*(i+1));
    ShowAll(v1); cout<<endl;

    vector<int> v2(5);
    for(auto i=0; i<5; i++)
        v2[i]=10*(i+1);
    ShowAll(v2); cout<<endl;

    vector<int> v3(5, 10); // initialize vector<int> with 5 10s.
    ShowAll(v3); cout<<endl;

    vector<int> v4(10);
    ShowSizeCap(v4); ShowAll(v4);
    v4.resize(20, 10);
    ShowSizeCap(v4); ShowAll(v4);
    v4.resize(5);
    ShowSizeCap(v4); ShowAll(v4);
    cout<<endl;
    // once the capacity becomes larger, it cannot be smaller by using resize()
    
    vector<int> v5(10, 7);
    ShowAll(v5); cout<<"Is it empty? "<<v5.empty()<<endl;
    v5.clear();
    ShowAll(v5); cout<<"Is it empty? "<<v5.empty()<<endl;
    ShowSizeCap(v5); // clear() discards all the elements in a vector, but it cannot free the memory.
    cout<<endl;

    vector<int> v6(20, 7);
    ShowAll(v6); ShowSizeCap(v6);
    vector<int>().swap(v6); // you can delete the elements and memory simultaneously by using swap()
    ShowAll(v6); ShowSizeCap(v6);
    cout<<endl;

    vector<int> v7(7, 7);
    ShowAll(v7);
    int& frt = v7.front(); // return ref of the first element
    frt = 777;
    int& bak = v7.back(); // return ref of the last element
    bak = 0;
    ShowAll(v7);
    cout<<endl;

    vector<int> v8(10, 10);
    //cout<<v8[10]<<endl;
    //cout<<v8.at(10)<<endl;
    // at() confirm the range of the vector before it access the element.
    // As a result, it is a little slower than [] operator, but safe.
    // in at() function, if the argument is out of range, then out_of_range exception occurs.
    try
    {
        cout<<v8.at(10)<<endl;
    }
    catch(out_of_range &e)
    {
        cout<<e.what()<<endl;
    }
    cout<<endl;

    vector<int> v9(5, 1);
    ShowAll(v9);
    v9.assign(3, 1); // assign elements
    ShowAll(v9);

    return 0;
}