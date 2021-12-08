// 뇌를 자극하는 STL... 1단원 이것만은 알고갑시다
#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char* str;
    int len;
public:
    String(const char* str)
    : len(strlen(str)+1)
    {
        this->str = new char[len];
        strcpy(this->str, str);
    }
    
    const char* GetStr() const {return str;}

    int GetLen() const {return len;}

    operator const char*()
    {
        char* str_copy = new char[len];
        strcpy(str_copy, this->str);
        return str_copy;
    }

    void operator=(const char* str)
    {
        len = strlen(str)+1;
        this->str = new char[len];
        strcpy(this->str, str);
    }

    
};

ostream& operator<<(ostream& os, const String& ref)
{
    os<<ref.GetStr();
    return os;
}

int main(void)
{
    String s1("Hello!");
    const char* sz1 = s1;
    cout<<"s1 = "<<s1<<endl;
    cout<<"sz1 = "<<sz1<<endl<<endl;

    const char* sz2 = "Hello!";
    String s2("Hi~!");
    s2 = sz2;
    cout<<"s2 = "<<s2<<endl;
    cout<<"sz2 = "<<sz2<<endl;

    return 0;
}