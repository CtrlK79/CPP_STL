#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Point
{
    int x, y;
public:
    Point(const int& _x=0, const int& _y=0) : x(_x), y(_y) {}
    void Print() const {cout<<x<<','<<y<<endl;}
};

int main()
{
    vector<int> v; list<int> lt;
    for(auto i=0; i<3; ++i)
    {
        v.push_back(10*(i+1));
        lt.push_back(10*(i+1));
    }

    vector<int>::iterator viter = v.begin();
    list<int>::iterator liter = lt.begin();

    cout<<"vector: "<<*viter<<endl;
    cout<<"list: "<<*liter<<endl;

    cout<<"vector: "<<*++viter<<endl;
    cout<<"list: "<<*++liter<<endl;

    cout<<"vector: "<<*--viter<<endl;
    cout<<"list: "<<*--liter<<endl;

    viter+=2;
    // liter+=2; // error!
    cout<<endl;

    // reverse_iterator
    vector<int>::reverse_iterator riter= v.rbegin();
    cout<<"riter: "<<*riter<<','<<*++riter<<endl;

    // iterator adaptor...
    reverse_iterator<vector<int>::iterator> rbiter(v.end());
    reverse_iterator<vector<int>::iterator> reiter(v.begin());
    cout<<"v[rbiter, reiter): ";
    for(; rbiter!=reiter; ++rbiter)
        cout<<*rbiter<<' ';
    cout<<endl;

    cout<<endl;

    vector<Point> ptVector; ptVector.push_back(Point(2, 5));
    list<Point> ptList; ptList.push_back(Point(2, 5));
    ptVector.begin()->Print();
    ptList.begin()->Print();

    return 0;
}