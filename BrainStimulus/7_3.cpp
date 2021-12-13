#include "mapHelper.h"

int main()
{
    SplitSector();
    map<int, int> m1;

    m1.insert(pair<int, int>(5, 100));  m1.insert(pair<int, int>(3, 100));
    m1.insert(pair<int, int>(8, 30));   m1.insert(pair<int, int>(4, 40));
    m1.insert(pair<int, int>(1, 70));   m1.insert(pair<int, int>(7, 100));

    pair<int, int> pr1(9, 50);
    m1.insert(pr1);
    ShowAll(m1);


    SplitSector();
    map<int, int> m2;

    m2.insert(pair<int, int>(5, 100));  m2.insert(pair<int, int>(3, 100));
    m2.insert(pair<int, int>(8, 30));   m2.insert(pair<int, int>(4, 40));
    m2.insert(pair<int, int>(1, 70));   m2.insert(pair<int, int>(7, 100));

    auto pr2 = m2.insert(pair<int, int>(9, 50)); // return (iterator, bool)
    if(pr2.second)
        cout<<"Insert(pair<int, int>("<<pr2.first->first<<','<<pr2.first->second<<"))"<<" successes!!"<<endl;
    else
        cout<<"Insert(pair<int, int>("<<pr2.first->first<<','<<pr2.first->second<<"))"<<" fails!!"<<endl;
    ShowAll(m2);

    const int target_key2 = 5;
    cout<<"key: "<<target_key2<<", value: "<<m2[target_key2]<<endl;


    SplitSector();
    map<int, string, greater<int>> m3;
    m3[5] = "five";     m3[3] = "three";    m3[8] = "eight";    m3[4] = "four";
    m3[1] = "one";      m3[7] = "seven";    m3[9] = "nine";

    ShowAll(m3);
    
    for(auto iter=m3.begin(); iter!=m3.end(); ++iter)
        cout<<iter->second<<' ';
    cout<<endl;


    SplitSector();
    map<int, int> m4;
    m4[5] = 100;    m4[3] = 100;    m4[8] = 30;     m4[4] = 40;
    m4[1] = 70;     m4[7] = 100;    m4[9] = 50;
    ShowAll(m4);

    auto iter4 = m4.find(5);
    cout<<"m4[5] = "<<iter4->second<<endl;

    for(auto iter=m4.lower_bound(1); iter!=m4.upper_bound(5); ++iter)
        cout<<'('<<iter->first<<','<<iter->second<<") ";
    cout<<endl;
    return 0;

}