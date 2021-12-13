#include "setHelper.h"

int main()
{
    SplitSector();
    multiset<int> ms1;
    multiset<int>::iterator iter1;

    ms1.insert(50); ms1.insert(30); ms1.insert(80);
    ms1.insert(80); ms1.insert(30); ms1.insert(70);
    iter1 = ms1.insert(10);

    cout<<"iter1: "<<*iter1<<endl;
    ShowAll(ms1);


    SplitSector();
    multiset<int> ms2;
    ms2.insert(50); ms2.insert(30); ms2.insert(80);
    ms2.insert(80); ms2.insert(30); ms2.insert(70);

    ShowAll(ms2);
    
    cout<<"the number of 30s: "<<ms2.count(30)<<endl;
    
    auto lower_iter2 = ms2.lower_bound(30);
    auto upper_iter2 = ms2.upper_bound(30);
    cout<<"lower_bound(30): "<<*lower_iter2<<endl;
    cout<<"upper_bound(30): "<<*upper_iter2<<endl;
    for(auto iter=lower_iter2; iter!=upper_iter2; ++iter)
        cout<<*iter<<' ';
    cout<<endl;

    const int check_num = 40;
    cout<<check_num<<" is an element of ms2: "<<TorF(ms2.equal_range(check_num).first!=ms2.equal_range(check_num).second)<<endl;

    
    

    return 0;
}