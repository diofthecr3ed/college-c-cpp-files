#include <iostream>

using namespace std;
class SpaceShip {
  public: void fly() {
    cout << "SpaceShip::fly()" <<
      endl;
  }
};
class Shuttle: public SpaceShip {
  public: virtual void land() {
    cout << "Shuttle::land()" << endl;
  }
};
int main() {
  Shuttle sh;
  SpaceShip * sPtr = & sh;
  sPtr -> fly();
  //sPtr -> land();
  return 0;
}