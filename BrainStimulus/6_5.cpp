#include <iostream>
#include <list>
#include <vector>
using namespace std;

#include "listHelper.h"

bool Predicate1(int n)
{ return 10<=n && n<=30;}

bool Predicate2(int first, int second)
{ return ((second-first)<=0);}

int main()
{
    list<int> lt1;
    for(auto i=0; i<5; ++i)
        lt1.push_back(10*(i+1));
    
    list<int>::iterator iter1;
    ShowAll(lt1);

    lt1.push_front(100); lt1.push_front(200);
    ShowAll(lt1);
    cout<<endl;


    list<int> lt2;
    for(auto i=0; i<5; ++i)
        lt2.push_back(10*(i+1));
    list<int>::iterator iter2 = lt2.begin();
    list<int>::iterator iter22;
    ++iter2; ++iter2;

    iter22 = lt2.erase(iter2); // erase an element at the position and return the iterator pointing the next element.
    ShowAll(lt2);
    cout<<"iter22: "<<*iter22<<endl;

    iter2 = iter22;
    iter22 = lt2.insert(iter2, 300); // insert an element in front of the position which the iterator points
    ShowAll(lt2);
    cout<<"iter22: "<<*iter22<<endl;
    cout<<endl;


    vector<int> v;
    list<int> lt3;

    for(auto i=0; i<5; ++i)
    {v.push_back(10*(i+1)); lt3.push_back(10*(i+1));}

    vector<int>::iterator viter = v.begin(); ++viter;
    list<int>::iterator liter = lt3.begin(); ++liter;
    
    viter = v.insert(viter, 600);
    liter = lt3.insert(liter, 600);
    
    cout<<"vector: "<<*viter<<endl;
    cout<<"list: "<<*liter<<endl;

    cout<<"vector: "; ShowAll(v);
    cout<<"list: "; ShowAll(lt3);
    cout<<endl;

    
    list<int> lt4;
    for(auto i=0; i<7; ++i)
        lt4.push_back(10*(i+1));
    lt4.push_back(10); lt4.push_back(10); lt4.push_back(10);
    ShowAll(lt4);
    lt4.remove(10); // remove all the 10s in lt4...
    ShowAll(lt4);
    cout<<endl;


    list<int> lt5;
    for(auto i=0; i<7; ++i)
        lt5.push_back(10*(i+1));
    lt5.push_back(10); lt5.push_back(10); lt5.push_back(10);
    ShowAll(lt5);
    lt5.remove_if(Predicate1); // remove all the elements returning true...
    ShowAll(lt5);
    auto iter5 = lt5.begin(); ++iter5; ++iter5;
    lt5.splice(iter5, lt4);
    ShowAll(lt5);
    cout<<endl;


    list<int> lt6;
    list<int> lt66;
    for(auto i=0; i<5; i++)
    {lt6.push_back(10*(i+1)); lt66.push_back(100*(i+1));}

    auto iter6 = lt6.begin(); ++iter6; ++iter6;
    auto iter66 = lt66.begin(); ++iter66;

    lt6.splice(iter6, lt66, iter66);
    ShowAll(lt6); cout<<"iter6: "<<*iter6<<endl;
    
    ++iter6; ++iter6;
    lt6.splice(iter6, lt66, lt66.begin(), lt66.end());
    ShowAll(lt6);
    cout<<endl;


    list<int> lt7;
    for(auto i=0; i<7; ++i)
        lt7.push_back(10*(i+1));
    ShowAll(lt7);
    lt7.reverse();
    ShowAll(lt7);

    lt7.push_back(10); lt7.push_back(30); lt7.push_back(50); lt7.push_back(70);
    ShowAll(lt7);
    lt7.unique();
    ShowAll(lt7);

    lt7.unique(Predicate2);
    ShowAll(lt7);
    cout<<endl;


    list<int> lt8;
    for(auto i=0; i<10; ++i)
        lt8.push_back(100*(10-i));
    ShowAll(lt8);
    lt8.sort();
    ShowAll(lt8);
    lt8.sort(greater<int>());
    ShowAll(lt8);
    cout<<endl;


    list<int> lt9;
    list<int> lt99;
    for(auto i=0; i<10; ++i)
        lt9.push_back(10*(i+1));
    lt99.push_back(25); lt99.push_back(55); lt99.push_back(65);
    ShowAll(lt9); ShowAll(lt99);
    lt9.merge(lt99);
    cout<<"lt9: "; ShowAll(lt9);
    cout<<"lt99: "; ShowAll(lt99);

    list<int> lt999;
    for(auto i=0; i<5; ++i)
        lt999.push_back(7+10*(i+1));
    lt999.sort(greater<int>());
    cout<<"lt999: "; ShowAll(lt999);
    //lt9.merge(lt999); // error occurs... or merged in a not desirable manners... because the sorting strategies are different...
    lt999.sort(less<int>());
    cout<<"lt999: "; ShowAll(lt999);
    lt9.merge(lt999, less<int>());
    ShowAll(lt9);
    return 0;
}