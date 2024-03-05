#include <iostream>
using namespace std;

class Vehicle {
public:
    Vehicle(int x) : index(x) { cout << "Vehicle(" << index << ")" << endl; }
    void beep() const { cout << "Beep, beep!" << endl; }
private:
    int index;
};

class Engine {
public:
    void start() const {}
    void rev() const {}
    void stop() const {}
};

class Wheel {
public:
  void inflate(int psi) const {cout<<"Wheel inflated to 72psi\n";}
};

class Window {
public:
    void rollup() const { std::cout <<"Window rolled up" <<endl; }
    void rolldown() const {}
};

class Door {
public:
    Window window;
    void open() const {}
    void close() const {}
};

// define the class Car

class Car : public Vehicle{
        public:

                Car(int y): Vehicle(y) {}
                Engine engine;

                // front left, front right, back left, back right
                Wheel wheels[4];
                Door doors[4];
};

int main() {

        // instantiate Car dynamically
        Car* car = new Car(1);

        // roll up the left window
        car->doors[0].window.rollup();

        // fill all the wheels with a pressure of 72
        for (int i = 0 ; i<=3 ; ++i){
                car->wheels[i].inflate(72);
        }

        // make the car beep
        car->beep();
}
