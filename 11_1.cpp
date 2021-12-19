// 'stack' container : LIFO(last in first out)
// 'queue' container : FIFO(first in first out)
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <list>
using namespace std;

int main()
{
    // stack
    stack<int> st;
    st.push(10); st.push(20); st.push(30);
    
    while(!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
    cout<<endl;

    // queue
    queue<int, list<int>> q;
    q.push(10); q.push(20); q.push(30);

    while(!q.empty())
    {
        cout<<q.front()<<endl;
        q.pop();
    }
    cout<<endl;

    // priority_queue
    priority_queue<int> pq1;
    pq1.push(40); pq1.push(20); pq1.push(30); pq1.push(50); pq1.push(10);
    cout<<"priority_queue[less]: "<<endl;
    while(!pq1.empty())
    {
        cout<<pq1.top()<<' ';
        pq1.pop();
    }
    cout<<endl;

    priority_queue<int, deque<int>, greater<int>> pq2;
    pq2.push(40); pq2.push(20); pq2.push(30); pq2.push(50); pq2.push(10);
    cout<<"priority_queue[greater]: "<<endl;
    while(!pq2.empty())
    {
        cout<<pq2.top()<<' ';
        pq2.pop();
    }
    cout<<endl;
    
    return 0;
}

