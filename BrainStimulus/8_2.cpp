// Modifying algorithms : change elements of a container
// it works in 'overwrite mode'... it means that to make it work, there should be pre-allocated memory...

#include <vector>
#include "algHelper.h"
using namespace alg8_2;

int main()
{
    SplitSector(); // copy(), copy_backward()
    vector<int> v1;
    for(auto i=0; i<5; ++i)
        v1.push_back(10*(i+1));
    cout<<"v1: "; ShowAll(v1);
    
    vector<int> v11(5); // vector<int> with size 5
    auto iter_v1 = copy(v1.begin(), v1.end(), v11.begin());
    cout<<"the last element of v11: "<<*(iter_v1-1)<<endl;
    cout<<"v11: "; ShowAll(v11);

    v11.clear(); v11.resize(10, 1);
    iter_v1 = copy_backward(v1.begin(), v1.end(), v11.end());
    cout<<"the first element of v11: "<<*iter_v1<<endl;
    cout<<"v11: "; ShowAll(v11);


    SplitSector(); // fill(), fill_n()
    vector<int> v2;
    for(auto i=0; i<5; ++i)
        v2.push_back(10*(i+1));
    cout<<"v2: "; ShowAll(v2);
    fill(v2.begin(), v2.end(), 0);
    cout<<"v2: "; ShowAll(v2);
    fill_n(v2.begin(), 3, 55); // fill 55 from v2.begin() to v2.begin()+3
    cout<<"v2: "; ShowAll(v2);


    SplitSector(); // for_each(), transform()
    vector<int> v3;
    for(auto i=0; i<5; ++i)
        v3.push_back(10*(i+1));
    cout<<"v3: "; ShowAll(v3);
    for_each(v3.begin(), v3.end(), Func3);
    cout<<"v3: "; ShowAll(v3);
    
    v3.clear();
    for(auto i=0; i<5; ++i)
        v3.push_back(i+1);
    cout<<"v3: "; ShowAll(v3);
    for_each(v3.begin(), v3.end(), Accumulation(0));
    cout<<"v3: "; ShowAll(v3);


    SplitSector(); // generate(), generate_n()
    vector<int> v4;
    for(auto i=0; i<5; ++i)
        v4.push_back(10*(i+1));
    cout<<"v4: "; ShowAll(v4);
    generate(v4.begin(), v4.end(), Integer(1));
    cout<<"v4: "; ShowAll(v4);
    generate(v4.begin(), v4.end(), Integer(100));
    cout<<"v4: "; ShowAll(v4);
    generate_n(v4.begin(), 3, Integer(0));
    cout<<"v4: "; ShowAll(v4);


    SplitSector(); // swap(), iter_swap()
    int a5=10, b5=20;
    vector<int> v5;
    v5.push_back(10); v5.push_back(20);
    cout<<"a5: "<<a5<<','<<"b5: "<<b5<<endl;
    swap(a5, b5);
    cout<<"a5: "<<a5<<','<<"b5: "<<b5<<endl;
    cout<<"v5: "; ShowAll(v5);
    iter_swap(v5.begin(), v5.begin()+1);
    cout<<"v5: "; ShowAll(v5);


    SplitSector(); // merge()
    vector<int> v6(5); vector<int> v66(5); vector<int> v666(15);
    generate(v6.begin(), v6.end(), EleGen(0, 7));
    generate(v66.begin(), v66.end(), EleGen(20, 13));
    cout<<"v6: "; ShowAll(v6);
    cout<<"v66: "; ShowAll(v66);
    auto iter_end_v6 = merge(v6.begin(), v6.end(), v66.begin(), v66.end(), v666.begin()); // return sorted vector
    // auto iter_end_v6 = merge(v6.begin(), v6.end(), v66.begin(), v66.end(), v666.begin(), less<int>()); // same result...
    cout<<"v666: "; ShowAll(v666);
    cout<<"'iter_end_v6' minus 1: "<<*(iter_end_v6-1)<<endl;


    SplitSector(); // replace(), replace_if(), replace_copy(), replace_copy_if()
    vector<int> v7(10);
    generate(v7.begin(), v7.begin()+5, EleGen(0, 14));
    generate(v7.begin()+5, v7.end(), EleGen(0, 14));
    cout<<"v7: "; ShowAll(v7);
    replace(v7.begin(), v7.end(), 28, 0); // replace 28 with 0 from v7.begin() to v7.end()
    cout<<"v7: "; ShowAll(v7);

    replace_if(v7.begin(), v7.end(), Predicator1, 10); // bool Predicator1(const int& n) {return n>60 || n<20;}
    cout<<"v7: "; ShowAll(v7);

    vector<int>().swap(v7);
    v7.push_back(10); v7.push_back(20); v7.push_back(30);
    v7.push_back(40); v7.push_back(30); v7.push_back(50);
    vector<int> v77(6); vector<int> v777(6);

    auto iter_end_v77 = replace_copy(v7.begin(), v7.end(), v77.begin(), 30, 0); // copy all the elements from v7.begin() to v7.end() to v77, except 30s... 30s are replaced by 0s
    auto iter_end_v777 = replace_copy_if(v7.begin(), v7.end(), v777.begin(), Predicator2, 0); // copy all the elements from v7.begin() to v7.end() to v777, except less than 30... the elements are replaced by 0s
    cout<<"v7: "; ShowAll(v7);
    cout<<"v77: "; ShowAll(v77);
    cout<<"v777: "; ShowAll(v777);


    SplitSector(); // swap_ranges()
    vector<int> v8(5); generate(v8.begin(), v8.end(), EleGen(0, 10));
    vector<int> v88(5); generate(v88.begin(), v88.end(), EleGen(0, 11));
    cout<<"v8: "; ShowAll(v8);
    cout<<"v88: "; ShowAll(v88);
    swap_ranges(v8.begin(), v8.end(), v88.begin());
    cout<<"v8: "; ShowAll(v8);
    cout<<"v88: "; ShowAll(v88);


    SplitSector(); // transform()
    // check differences between transform() and for_each()
    vector<int> v9;
    for(auto i=0; i<5; ++i)
        v9.push_back(10*(i+1));
    cout<<"v9: "; ShowAll(v9);
    auto iter_end_v9 = transform(v9.begin(), v9.end(), v9.begin(), Func9);
    cout<<"v9: "; ShowAll(v9);
    cout<<"'iter_end_v9' minus 1: "<<*(iter_end_v9-1)<<endl;

    v9.clear(); vector<int> v99;
    for(auto i=0; i<5; ++i)
    {
        v9.push_back(10*(i+1));
        v99.push_back(i+1);
    }
    cout<<"v9: "; ShowAll(v9);
    cout<<"v99: "; ShowAll(v99);

    vector<int> v999(5);
    iter_end_v9 = transform(v9.begin(), v9.end(), v99.begin(), v999.begin(), Plus9); // int Plus9(const int& left, const int& right) {return left+right;}
    cout<<"v999: "; ShowAll(v999);
    cout<<"'iter_end_v9' minus 1: "<<*(iter_end_v9-1)<<endl;
        
    

    return 0;
}