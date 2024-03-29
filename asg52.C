#include <iostream>
#include <cmath>
using namespace std;

class Point{
    public:
        int x;
        int y;
        Point(){};
        Point(int a, int b): x(a), y(b){};
        float distance(const Point & a){float d = sqrt(((x-a.x)*(x-a.x))+((y-a.y)*(y-a.y)));return d; }
};

int main(void){
    Point a(2,3);
    Point b(3,4);
    cout << a.distance(b) << endl;
    return 0;
}