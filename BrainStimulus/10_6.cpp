#include <iostream>

template <class Iter>
struct iterator_traits
{
    typedef typename Iter::iterator_category iterator_category; // use typename to differentiate class Iter and a type defined by a template
    typedef typename Iter::value_type value_type;
    typedef typename Iter::difference_type difference_type;
    typedef typename Iter::pointer pointer;
    typedef typename Iter::reference reference;
};

struct input_iterator_tag{};
struct output_iterator_tag {};
struct forward_iterator_tag: public input_iterator_tag{};
struct bidirectional_iterator_tag: public input_iterator_tag{};
struct random_access_iterator_tag: public bidirectional_iterator_tag{};

template <typename T>
class Vector
{
public:
    class Iterator
    {
    public:
        typedef random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef int difference_type;
        typedef T* pointer;
        typedef T& reference;
        void operator+=(int){}
    };
    void Push_back(const T& data){}
    Iterator Begin() {return Iterator();}
};

template <typename T>
class List
{
public:
    class Iterator
    {
    public:
        typedef random_access_iterator_tag iterator_category;
        typedef T value_type;
        typedef int difference_type;
        typedef T* pointer;
        typedef T& reference;
        void operator++(){}
    };
    void Push_back(const T& data){}
    Iterator Begin() {return Iterator();}
};

template <typename Iter>
void _Advance(Iter& iter, int n, bidirectional_iterator_tag category_tag)
{
    for(int i=0; i<n; ++i)
        ++iter;
    std::cout<<"bidirectional version of advance() ++iter"<<std::endl;
}

template <typename Iter>
void _Advance(Iter& iter, int n, random_access_iterator_tag category_tag)
{
    iter += n;
    std::cout<<"random access version of advance() ++iter"<<std::endl;
}

template <typename Iter>
void Advance(Iter& iter, int n)
{
    _Advance(iter, n, iterator_traits<Iter>::iterator_category);
}

int main()
{
    Vector<int> v;
    v.Push_back(10); v.Push_back(20); v.Push_back(30);

    List<int> lt;
    lt.Push_back(10); lt.Push_back(20); lt.Push_back(30);
    
    Vector<int>::Iterator viter(v.Begin());
    List<int>::Iterator liter(lt.Begin());

    Advance(viter, 2);
    Advance(liter, 2);
    
    return 0;
}