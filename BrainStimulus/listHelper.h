template <typename T>
void ShowAll(const T& obj)
{
    for(auto i=obj.begin(); i!=obj.end(); ++i)
        cout<<*i<<' ';
    cout<<endl;
}