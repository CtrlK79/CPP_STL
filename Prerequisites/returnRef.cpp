// An example clarifying the meaning of returning a reference type...
#include <iostream>
using namespace std;

class Point
{
private:
    int x;
    int y;
public:
    Point(int _x=0, int _y=0) : x(_x), y(_y) {}
    Point& operator++() {++x; ++y; return *this;}
    void ShowPosition() const {cout<<x<<','<<y<<endl;}
};

Point& getPoint(Point& ref) {return ref;}

int main(void)
{
    Point p1(1, 2);
    Point p2 = getPoint(p1);
    Point& p3 = getPoint(p1);
    ++(++p2); ++p3;
    p1.ShowPosition();
    p2.ShowPosition();
    p3.ShowPosition();

    return 0;
}