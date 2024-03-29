#include <iostream>

#include <string>

using namespace std;
class Pet {
  string pname;
  public:
    Pet(const string & petName): pname(petName) {}
  virtual string name() = 0;
  virtual string speak() = 0;
  virtual~Pet() {}
};
string Pet::name() {
  return pname;
}

class Dog: public Pet {
    public: Dog(const string & petName): Pet(petName) {}
    virtual string sit() {
      return Pet::name() + "sits "; }
      string speak() {
        return Pet::name() + " says 'Bark!'"; }
        string name() {
            return Pet::name();
          }
          ~Dog() {}
      };
      int main() {
        Pet * p = new Dog("bob");
        cout << p -> speak() << endl;
        delete p;
      }