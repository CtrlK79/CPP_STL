#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <ctime>

using namespace std;

const int ITER_NUM = 500000;

int main()
{
    // in the middle of the container... # of iterations in vector's loop is 1/50 of others'...
    cout<<"****** Inserting elements at the middle of the container ******"<<endl;
    vector<int> v(10, 1);
    auto t1 = time(NULL);
    for(auto i=0; i<ITER_NUM; ++i){v.insert(v.begin()+5, 1);}
    auto t2 = time(NULL);
    cout<<"vector: "<<(t2-t1)<<endl;
    
    deque<int> dq(10, 1);
    t1 = time(NULL);
    for(auto i=0; i<ITER_NUM*50; ++i){dq.insert(dq.begin()+2, 1);}
    t2 = time(NULL);
    cout<<"deque: "<<(t2-t1)<<endl;

    list<int> lt(10, 1);
    auto iter = lt.begin(); ++iter; ++iter;
    t1 = time(NULL);
    for(auto i=0; i<ITER_NUM*50; ++i){lt.insert(iter, 1);}
    t2 = time(NULL);
    cout<<"list: "<<(t2-t1)<<endl;

    vector<int>().swap(v);
    deque<int>().swap(dq);
    list<int>().swap(lt);

    // in the end of the container
    cout<<"****** Inserting elements at the end of the container ******"<<endl;
    v.assign(10, 1);
    t1 = time(NULL);
    for(auto i=0; i<ITER_NUM*50; ++i){v.insert(v.end(), 1);}
    t2 = time(NULL);
    cout<<"vector: "<<(t2-t1)<<endl;
    
    dq.assign(10, 1);
    t1 = time(NULL);
    for(auto i=0; i<ITER_NUM*50; ++i){dq.insert(dq.end(), 1);}
    t2 = time(NULL);
    cout<<"deque: "<<(t2-t1)<<endl;

    lt.assign(10, 1);
    iter = lt.end();
    t1 = time(NULL);
    for(auto i=0; i<ITER_NUM*50; ++i){lt.insert(iter++, 1);}
    t2 = time(NULL);
    cout<<"list: "<<(t2-t1)<<endl;

    return 0;
}