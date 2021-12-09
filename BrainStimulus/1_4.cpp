#include <iostream>
using namespace std;

class Array
{
private:
    int *arr;
    int size;
    int capacity;
public:
    Array(int cap=100)
    : size(0), capacity(cap)
    {
        arr = new int[capacity];
    }

    ~Array() {delete []arr;}

    void Add(int data)
    {
        if(size<capacity)
            arr[size++]=data;
        else
            throw "size cannot over the capacity";
    }

    int Size() const {return size;}

    int operator[](int idx) const {return arr[idx];} // return a value

    int& operator[](int idx) {return arr[idx];} // return a reference of the object
};

int main()
{
    Array arr(50);
    arr.Add(10); arr.Add(20); arr.Add(30);
    cout<<arr.Size()<<endl;
    for(int i=0; i<arr.Size(); i++)
        cout<<arr[i]<<' ';
    cout<<endl;
    arr[3] = 10; // I guess this code is not sound because the size mismatches the number of the elements...
    
    return 0;
}