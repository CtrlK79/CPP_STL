#include "setHelper.h"

int main()
{
    int sectorNum = 0;


    SplitSector(++sectorNum);
    set<int> s1;
    s1.insert(50); s1.insert(30); s1.insert(80); s1.insert(40);
    s1.insert(10); s1.insert(70); s1.insert(90); s1.insert(50); // return type of insert() is bool...
    for(auto iter=s1.begin(); iter!=s1.end(); ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    auto ist100 = s1.insert(100); // pair<set<int>::iterator, bool> type
    auto ist50 = s1.insert(50);
    cout<<"insert(100): "<<TorF(ist100.second)<<endl;
    cout<<"insert(50): "<<TorF(ist50.second)<<endl;
    cout<<*ist100.first<<", "<<*ist50.first<<endl;


    SplitSector(++sectorNum);
    set<int> s2;
    pair<set<int>::iterator, bool> pr;

    s2.insert(50); s2.insert(30); s2.insert(80); s2.insert(40);
    s2.insert(10); s2.insert(70);
    pr = s2.insert(90);

    ShowAll(s2);
    s2.insert(pr.first, 85); // insert 85 starting from the iterator indicating 90
    ShowAll(s2);


    SplitSector(++sectorNum);
    set<int, greater<int>> s3; // set sorting criteria to greater<int>
    for(auto i=0; i<7; ++i)
        s3.insert(10*(i+1)+5*(i%2));
    ShowAll(s3);


    SplitSector(++sectorNum);
    set<int, less<int>> s_less;
    set<int, greater<int>> s_greater;

    s_less.insert(50); s_less.insert(80); s_less.insert(40);
    s_greater.insert(50); s_greater.insert(80); s_greater.insert(40);

    set<int, less<int>>::key_compare l_cmp = s_less.key_comp(); // return the predicator
    cout<<TorF(l_cmp(10, 20))<<endl; // 10 < 20

    set<int, greater<int>>::key_compare g_cmp = s_greater.key_comp();
    cout<<TorF(g_cmp(10, 20))<<endl; // 10 > 20


    SplitSector(++sectorNum);
    set<int> s4;
    s4.insert(50); s4.insert(30); s4.insert(80); s4.insert(40);
    s4.insert(10); s4.insert(70); s4.insert(90);

    ShowAll(s4);
    cout<<"the number of 50s: "<<s4.count(50)<<endl;
    cout<<"the number of 100s: "<<s4.count(100)<<endl;
    
    auto iter4 = s4.find(30); // return the iterator indicating 30
    if(iter4!=s4.end()) // if there is not the key, return end()
    {
        for(auto iter=iter4; iter!=s4.end(); ++iter)
            cout<<*iter<<' ';
        cout<<endl;
    }
    else
        cout<<"30 is not a key of s4"<<endl;

    // find logic:
    cout<<"30==50? "<<TorF(!s4.key_comp()(30, 50) && !s4.key_comp()(50, 30))<<endl; // !30<50 and !50<30 <=> 30==50... return FALSE
    cout<<"50==50? "<<TorF(!s4.key_comp()(50, 50) && !s4.key_comp()(50, 50))<<endl; // !50<50 and !50<50 <=> 50==50... return TRUE


    const int upperBound = 30; const int lowerBound = 80;
    for(auto iter = s4.lower_bound(upperBound); iter!=s4.upper_bound(lowerBound); ++iter)
        cout<<*iter<<' ';
    cout<<endl;

    const int num = 77;
    if(s4.lower_bound(num) == s4.upper_bound(num))
        cout<<num<<" is not here!"<<endl;
    else
        cout<<num<<" is here!"<<endl;
    // below codes show the same result
    if(s4.equal_range(num).first == s4.equal_range(num).second)
        cout<<num<<" is not here!"<<endl;
    else
        cout<<num<<" is here!"<<endl;
    return 0;
}