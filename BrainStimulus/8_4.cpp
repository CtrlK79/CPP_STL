// Mutating algorithms : change the order of the elements
#include <vector>
#include <cstdlib>
#include <ctime>
#include "algHelper.h"
using namespace common;
using namespace alg8_4;

int main()
{
    SplitSector();// next_permutation(), prev_permutation()
    // change the order in lexicographical manners... like a permutation
    // return false at the last permutation
    // prev_permutation() is similar to next_permutation(), but it generates permutation in the reverse sequence
    vector<int> v1; 
    v1.push_back(10); v1.push_back(20); v1.push_back(30);
    do
    {cout<<"v1: "; ShowAll(v1);}
    while(next_permutation(v1.begin(), v1.end()));
    cout<<endl;

    vector<Point> v11;
    v11.push_back(Point(5, 1)); v11.push_back(Point(7, 2)); v11.push_back(Point(5, 3));
    do
    {cout<<"v11: "; ShowAll(v11);}
    while(next_permutation(v11.begin(), v11.end(), Predicator1));


    SplitSector(); // partition()
    vector<int> v2;
    v2.push_back(30); v2.push_back(40); v2.push_back(50);
    v2.push_back(10); v2.push_back(20); v2.push_back(60);
    cout<<"v2: "; ShowAll(v2);
    auto iter_sep_v2 = partition(v2.begin(), v2.end(), Predicator2);
    cout<<"under 40: ";
    for(auto iter=v2.begin(); iter!=iter_sep_v2; ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    cout<<"equal to 40 or over: ";
    for(auto iter=iter_sep_v2; iter!=v2.end(); ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    // it doesn't keep the relative orders among elements
    // if you want for your code to do so, use stable_partition instead...
    cout<<endl;

    v2.clear();
    v2.push_back(30); v2.push_back(40); v2.push_back(50);
    v2.push_back(10); v2.push_back(20); v2.push_back(60);
    cout<<"v2: "; ShowAll(v2);
    iter_sep_v2 = stable_partition(v2.begin(), v2.end(), Predicator2);
    cout<<"under 40: ";
    for(auto iter=v2.begin(); iter!=iter_sep_v2; ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    cout<<"equal to 40 or over: ";
    for(auto iter=iter_sep_v2; iter!=v2.end(); ++iter)
        cout<<*iter<<' ';
    cout<<endl;
    // it works slower than partition(), so don't use it if what you need are only the elements satisfying a specific condition not the order.


    SplitSector(); // random_shuffle()
    vector<int> v3;
    for(auto i=0; i<5; ++i)
        v3.push_back(10*(i+1));
    cout<<"v3: "; ShowAll(v3);
    random_shuffle(v3.begin(), v3.end());
    cout<<"v3: "; ShowAll(v3);


    SplitSector(); // reverse(), reverse_copy()
    vector<int> v4;
    for(auto i=0; i<5; ++i)
        v4.push_back(10*(i+1));
    cout<<"v4: "; ShowAll(v4);
    reverse(v4.begin(), v4.end());
    cout<<"v4: "; ShowAll(v4);
    cout<<endl;

    vector<int> v44(5);
    cout<<"v4: "; ShowAll(v4);
    reverse_copy(v4.begin(), v4.end(), v44.begin());
    cout<<"v44: "; ShowAll(v44);


    SplitSector(); // rotate()
    vector<int> v5;
    for(auto i=0; i<20; ++i)
        v5.push_back(10*(i+1));
    cout<<"v5: "; ShowAll(v5);
    rotate(v5.begin(), v5.begin()+5, v5.end());
    cout<<"v5: "; ShowAll(v5);
    rotate(v5.begin(), v5.begin()+5, v5.end()-5);
    cout<<"v5: "; ShowAll(v5);

    vector<int> v55(20);
    rotate_copy(v5.begin(), v5.begin()+5, v5.end()-5, v55.begin());
    cout<<"v55: "; ShowAll(v55);
    return 0;
}