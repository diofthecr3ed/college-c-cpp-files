#include <iostream>
#include <string>

using namespace std;

// interface inheritance = is a
// implementation inheritance = uses a
// eg. stack uses a linked list
// Overriding = taking the base class's function and modifying to to suit my need
// Polymorphism = Outpass exists in student but gets modified based on which subclass it goes to
// Upcasting = taking the derived class object, pointer from the baseclass points to the derived class but uses the members of the baseclass; passing a derived object as a referece to a baseclass
// Implement polymorphism = add "virtual" keyword in baseclass
// return (char *) "instrument"; = typecasting
// late binding = when compiler gets to know what type of object it has to use for the method
// To override a function of the base class in a derived class, D class definition: void play(note) override;
// When you redefine a virtual function, you are enabling polymorphism
// Same signature is necessary condition for overriding to happen
// If not same signature,  it is called redefinition
// If the signature was same and it was virtual, then would be overriding
// Function hiding : when you have a function witha different signature in the child class, it will hide all versions of that function in the parent class. in redefinition example. Write one more simillar function if you really want to overload the function in the child class. Functions expected to overload from the parent class will be hidden. The concept of function pointers also comes in here. VPTR[0] example

class Person{
                string id;
        public:
                string getId(){return id;}
};

class Student: public Person{
        private:
                bool outpassStatus;

        public:
                virtual void outpass(){cout << "Outpass given Student" << endl;}
};

class Tlf final: public Student{
        public:
                void outpass(){cout << "Outpass given TLF" << endl;}
};

class Phd final: public Student{
        public:
};

class Ug final: public Student{
        public:
                void outpass(){cout << "Outpass given UG" << endl;}
};



int main(void){

        Ug* ptr= new Ug;
        (*ptr).outpass();

        Student* ptr2 = new Tlf;
        (*ptr2).outpass(); //upcasting

        cout << (*ptr).getId() << endl;
        return 0;
}
