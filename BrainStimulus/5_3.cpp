#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    stack<int> st; // default container deque is addapted...
    stack<int, vector<int>> stv;

    st.push(10); st.push(20); st.push(30);
    stv.push(10); stv.push(20); stv.push(30);

    cout<<st.top()<<endl; st.pop();
    cout<<st.top()<<endl; st.pop();
    cout<<st.top()<<endl; st.pop();

    cout<<stv.top()<<endl; stv.pop();
    cout<<stv.top()<<endl; stv.pop();
    cout<<stv.top()<<endl; stv.pop();

    if(st.empty() && stv.empty())
        cout<<"there is no data in stack"<<endl;

    return 0;
}