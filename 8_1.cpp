// Nonmodifying algorithms : do not change elements of a container


#include <vector>
#include "algHelper.h"

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
    
    


    return 0;
}