#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <functional>
using namespace std;

namespace common
{
    template <typename T>
    void ShowAll(const T& seq)
    {
        for(auto iter=seq.begin(); iter!=seq.end(); ++iter)
            cout<<*iter<<' ';
        cout<<endl;
    }

    void SplitSector()
    {
        static int secNum;
        cout<<"=====Sector#"<<++secNum<<"====="<<endl;
    }

    string TorF(const bool& tf)
    {
        if(tf)
            return "TRUE";
        else
            return "FALSE";
    }
}

namespace fo9_1
{
    template <typename T>
    struct Plus: public binary_function<T, T, T> // enable application of adapter... set first_argument_type, second_argument_type, return_type
    {
        T operator()(const T& left, const T& right) const
        {
            return left+right;
        }
    };
}

namespace fo9_2
{
    template <typename T>
    struct Less: public binary_function<T,T,bool>
    {
        bool operator()(const T& left, const T& right) const
        {
            return left<right;
        }
    };
}

namespace fo9_3
{

}
namespace fo9_4
{   
    template <typename T>
    struct Logical_and: public binary_function<T,T,bool>
    {
        bool operator()(const T& left, const T& right) const
        {
            return left && right;
        }
    };
}

namespace fo9_5
{

}

namespace fo9_6
{
    bool Pred1(const int& n)
    {
        return 30<=n && n<=40;
    }

    // functor class
    template <typename RType, typename AType>
    class Ptr_fun_class: public unary_function<AType, RType>
    {
        RType (*pf)(AType);
    public:
        Ptr_fun_class(RType (*_pf)(AType)) : pf(_pf) {}
        RType operator()(AType n) const
        {
            return pf(n);
        }
    };

    // ptr_fun() function
    template <typename RType, typename AType>
    Ptr_fun_class<RType, AType> Ptr_fun(RType (*pf)(AType))
    {
        return Ptr_fun_class<RType, AType>(pf);
    }
}

namespace fo9_7
{
    class Point
    {
        int x, y;
    public:
        explicit Point(int _x=0, int _y=0) : x(_x), y(_y) {}
        void Print() const {cout<<x<<','<<y<<endl;}
        int GetX() const {return x;}
        int GetY() const {return y;}
    };

    template <typename RType, typename CType>
    class Mem_fun_class: public unary_function<CType, RType>
    {
        RType (CType::*pf)() const;
    public:
        Mem_fun_class(RType (CType::*_pf)() const) : pf(_pf) {}
        RType operator()(const CType* p) const{
            return (p->*pf)();
        }
    };

    template <typename RType, typename CType>
    Mem_fun_class<RType, CType> Mem_fun(RType (CType::*pf)() const)
    {
        return Mem_fun_class<RType, CType>(pf);
    }
}