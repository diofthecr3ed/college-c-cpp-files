#include <iostream>
#include <cmath>
using namespace std;

class Shape{
        public:
                virtual double Area() = 0;
};

class Rectangle: public Shape{
        public:
                Rectangle(double lp, double bp): l(lp), b(bp){}
                Rectangle(const Rectangle &r){l = r.l; b = r.b;}
                double l;
                double b;
                double Area(){return l*b;}
};

class Circle: public Shape{
        public:
                Circle(double rad): r(rad){}
                Circle(const Circle &c){r = c.r;}
                double r;
                double Area(){return r*r*3.14;}
};

class Triangle: public Shape{
        public:
                Triangle(double side1, double side2, double side3) : s1(side1), s2(side2), s3(side3) {}
                Triangle(const Triangle& t) {
                        s1 = t.s1;
                        s2 = t.s2;
                        s3 = t.s3;
                }
                double s1;
                double s2;
                double s3;
                double Area() {
                        double s = (s1+s2+s3)/2;
                        double a = sqrt(s*(s-s1)*(s-s2)*(s-s3));
                        return a;
}
};

class Square: public Rectangle{
        public:
                Square(double sp): Rectangle(sp,sp), s(sp){}
                Square(const Square& sq): Rectangle(sq.s, sq.s){s = sq.s;}
                double s;
                double Area(){return s*s;}
};

int main(void){
        Shape* shapes[4];
        shapes[0] = new Rectangle(5.0, 3.0);
        shapes[1] = new Square(4.0);
        shapes[2] = new Circle(2.5);
        shapes[3] = new Triangle(3.0, 4.0, 5.0);


        for (int i = 0; i < 4; ++i) {
                cout << "Area of Shape " << i+1 << ": " << shapes[i]->Area() << endl;
        }


        for (int i = 0; i < 4; ++i) {
                delete shapes[i];
        }

        return 0;
}

// Yes, my abstract class is also an interface class here as it contains only one pure virtual function.
