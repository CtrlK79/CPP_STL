#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(const int _x=0, const int _y=0);
    void Print() const;
    int GetX() const;
    int GetY() const;

    Point& operator++(); // prefix increment operator... ++(++obj) should be allowed.
    const Point operator++(int); // postfix increment operator... (obj++)++ should not be allowed.
    Point& operator--(); // prefix decrement operator... --(--obj) should be allowed.
    const Point operator--(int); // postfix decrement operator... (obj--)-- should not be allowed.
    bool operator==(const Point& arg) const; // equality operator...
    bool operator!=(const Point& arg) const; // inequality operator... it can be easily expressed by using == operator...
    // operator+ is defined below... with getter. It is more preferable than using friend because friend undermines encapsulation.
    friend Point& operator-(const int num, const Point& ref); // global operator with friend...
};

int main(void)
{
    Point p1(1, 2);
    ++(++p1);
};

// Initializer, getter, and other basic functions...
Point::Point(const int _x, const int _y) : x(_x), y(_y) {}
void Point::Print() const {cout<<x<<','<<y<<endl;}
int Point::GetX() const {return this->x;}
int Point::GetY() const {return this->y;}

// operator definition
Point& Point::operator++()
{
    ++x; ++y;
    return *this;
}
const Point Point::operator++(int)
{
    Point pt(x++, y++);
    return pt;
}
Point& Point::operator--()
{
    --x; --y;
    return *this;
}
const Point Point::operator--(int)
{
    Point pt(x--, y--);
    return pt;
}
bool Point::operator==(const Point& arg) const
{
    if(x==arg.x && y==arg.y)
        return true;
    else
        return false;
}
bool Point::operator!=(const Point& arg) const
{
    return !(*this == arg);
}
Point& operator+(const Point& ref1, const Point& ref2)
{
    Point pt(ref1.GetX()+ref2.GetX(), ref1.GetY()+ref2.GetY());
    return pt;
}
Point& operator-(const int num, const Point& ref)
{
    Point pt(num-ref.x, num-ref.y);
    return pt;
}