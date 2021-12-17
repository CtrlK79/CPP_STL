#include <iostream>
#include <typeinfo>
#include <algorithm>
using namespace std;

namespace std
{
    template <typename T>
    void Print(const T& n)
    {
        cout<<n<<' ';
    }

    template <typename T>
    void ShowAll(const T& ref)
    {
        for(auto iter=ref.begin(); iter!=ref.end(); ++iter)
            cout<<*iter<<' ';
        cout<<endl;
    }

    template<typename T>
    void ShowAllMap(const T& m)
    {
        for(auto iter=m.begin(); iter!=m.end(); ++iter)
            cout<<'('<<iter->first<<','<<iter->second<<") ";
        cout<<endl;
    }

    void SplitSector()
    {   
        static int n = 0;
        cout<<"=========="<<"Sector #"<<++n<<"=========="<<endl;
    }

    const char* TorF(const bool& tf)
    {
        if(tf)
            return "TRUE";
        else
            return "FALSE";
    }
}
namespace alg8_1
{


    bool Predicator1(const int& first, const int& second)
    {
        return first + second > 50;
    }

    bool Predicator2(const int& num)
    {
        return num>0;
    }

    bool Predicator3(const int& left, const int& right)
    {
        return abs(right-left)<5;
    }

    bool Predicator4(const int& num)
    {
        return num<35;
    }

    bool Predicator5(const int& left, const int& right)
    {
        return left<=right;
    }

    bool Predicator6(const int& left, const int& right)
    {
        return left>right;
    }

    class PrintFunctor
    {
        char fmt;
    public:
        explicit PrintFunctor(char c=' '):fmt(c) {}
        void operator()(const int& n) const
        {
            cout<<n<<fmt;
        }
    };

    template <typename T>
    struct Less
    {
        bool operator()(const T& left, const T& right) const
        {return left<right;}
    };

    class Point
    {
        int x, y;
    public:
        explicit Point(int _x=0, int _y=0) : x(_x), y(_y) {}
        int GetX() const {return x;}
        int GetY() const {return y;}
        void Print() const {cout<<'('<<x<<','<<y<<')'<<endl;}
    };

    bool XCompare(const Point& left, const Point& right)
    {
        return left.GetX() < right.GetX();
    }

    bool YCompare(const Point& left, const Point& right)
    {
        return left.GetY() < right.GetY();
    }

    bool Compare(const Point& left, const Point& right)
    {
        if(left.GetX()<right.GetX())
            return true;
        else if(left.GetX()>right.GetX())
            return false;
        else
            return left.GetY()<right.GetY();
    }
}

namespace alg8_2
{
    class EleGen
    {
        int data;
        int step;
    public:
        explicit EleGen(int data=0, int step=10) : data(data), step(step) {}
        int operator()() {return data+=step;}
    };

    void Func3(int& r)
    {
        r+=5;
    }

    class Accumulation
    {
        int total;
    public:
        explicit Accumulation(int init=0) : total(init) {}
        void operator()(int& r) {total+=r; r=total;}
    };

    class Integer
    {
        int data;
    public:
        explicit Integer(int d=0) : data(d) {}
        int operator()() {return data++;}
    };

    bool Predicator1(const int& n)
    {
        return n>60 || n<20;
    }

    bool Predicator2(const int& n)
    {
        return n <= 30;
    }

    int Func9(const int& n)
    {
        return n+5;
    }

    int Plus9(const int& left, const int& right)
    {
        return left+right;
    }
}

namespace alg8_3
{
    bool Predicator1(const int& n)
    {
        return 30<=n && n<=40;
    }

    bool Predicator2(const int& left, const int& right)
    {
        return abs(left-right) < 10;
    }
}

namespace alg8_4
{
    class Point
    {
        int x, y;
    public:
        explicit Point(int _x=0, int _y=0) : x(_x), y(_y) {}
        int GetX() const {return x;}
        int GetY() const {return y;}
    };

    ostream& operator<<(ostream& os, const Point& pt)
    {
        os<<'('<<pt.GetX()<<','<<pt.GetY()<<") ";
        return os;   
    }

    bool Predicator1(const Point& left, const Point& right)
    {
        return left.GetY()<right.GetY();
    }

    bool Predicator2(const int& num)
    {
        return num<40;
    }
}

namespace alg8_5
{
    bool Greater(const int& left, const int& right)
    {
        return left>right;
    }
}

namespace alg8_6
{
    bool Predicator1(const int& left, const int& right)
    {
        return 3<right-left;
    }
}

namespace alg8_7
{
    template <typename T>
    struct Plus1
    {
        T operator()(const T& left, const T& right)
        {
            return left+right;
        }
    };

    int Plus11(const int& left, const int& right)
    {
        return left+right;
    }

    int Minus1(const int& left, const int& right)
    {
        return left-right;
    }
}