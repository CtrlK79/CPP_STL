//뇌를 자극하는 STL... 4단원 이것만은 알고갑시다
#include <iostream>
using namespace std;

template <typename T>
void Copy(T* des, const T* dep, int n)
{
    for(auto i=0;i<n;i++)
        des[i] = dep[i];
}

template <typename T>
class Stack
{
private:
    T arr[50];
    int len;
public:
    Stack() : len(0) {}

    void Push(const T& data) {arr[len++]=data;}
    
    T Pop() {return arr[--len];}
    
    bool Empty()
    {
        if(len)
            return false;
        else
            return true;
    }
};

template <typename T>
class Queue
{
private:
    T arr[50];
    int len;
public:
    Queue() : len(0) {}

    void Push(const T& data)
    {
        for(auto i=0;i<len;i++)
            arr[len-i] = arr[len-i-1];
        arr[0] = data; ++len;
    }
    
    T Pop() {return arr[--len];}
    
    bool Empty()
    {
        if(len)
            return false;
        else
            return true;
    }
};

int main(void)
{
    int arr1[5] = {10, 20, 30, 40, 50};
    int arr2[5];
    Copy(arr2, arr1, 5);
    for(auto i=0;i<5;i++)
        cout<<arr2[i]<<' ';
    cout<<endl;

    Stack<int> st;
    st.Push(10);
    st.Push(20);
    st.Push(30);
    if(!st.Empty())
        cout<<st.Pop()<<endl;
    if(!st.Empty())
        cout<<st.Pop()<<endl;
    if(!st.Empty())
        cout<<st.Pop()<<endl;

    Queue<int> q;
    q.Push(10);
    q.Push(20);
    q.Push(30);
    if(!q.Empty())
        cout<<q.Pop()<<endl;
    if(!q.Empty())
        cout<<q.Pop()<<endl;
    if(!q.Empty())
        cout<<q.Pop()<<endl;
    return 0;
}