#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using namespace std;

int main()
{
    vector<int> v; v.push_back(10); v.push_back(20); v.push_back(30);
    list<int> lt; lt.push_back(10); lt.push_back(20); lt.push_back(30);
    
    auto viter = v.begin();
    auto liter = lt.begin();

    advance(viter, 1); // viter+=1;
    advance(liter, 2); // liter+=2; // error!

    cout<<"viter: "<<*viter<<endl;
    cout<<"liter: "<<*liter<<endl;
    
    cout<<"distance in vector: "<<distance(v.begin(), viter)<<endl;
    cout<<"distance in list: "<<distance(lt.begin(), liter)<<endl;

    return 0;
}