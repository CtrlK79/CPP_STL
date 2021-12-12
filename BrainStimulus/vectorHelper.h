template <typename T>
void ShowAll(const T& obj)
{
    for(auto i=obj.begin(); i!=obj.end(); ++i)
        cout<<*i<<' ';
    cout<<endl;
}

template <typename T>
void ShowSizeCap(const T& obj)
{
    cout<<"size: "<<obj.size()<<", capacity: "<<obj.capacity()<<endl;
}