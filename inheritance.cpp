#include <iostream>
#include <string>

using namespace std;

class Person {
        protected:
                string id;
        public:
                Person(string idvar){
                        id = idvar;
                }
};
class Student : protected Person{
        protected:
                float cgpa;
                int fee;
                int attendance = 0;
        public:
                Student(string idvar, float cgpavar, int feevar):Person(idvar), cgpa(cgpavar), fee(feevar){cout<<"Student constructor called"<<endl;}
                ~Student(){cout<< "Student destructor called" << endl;}
                void updateAttendance(){
                        attendance++;
                }
};

class Undergraduate : public Student {
        private:
                bool scholarshipStatus;
        public:
                Undergraduate(string idvar,float cgpavar,int feevar,bool scholarship):Student(idvar,cgpavar,feevar),scholarshipStatus(scholarship) { cout << "UG Constructor" << endl;}
                ~Undergraduate(){cout << "UG destructor" <<endl;}
                void display(){
                        string status;
                        if (scholarshipStatus == true){status = "Yes";} else {status = "No";}
                        cout << "ID: "<< Person::id << "\n" << "CGPA: " << Student::cgpa << "\n" << "Fee: Rs." << Student::fee << "\n" << "Scholarship: "<< status << "\nAttendance: " << attendance<<endl;             }

};

class Postgraduate : private Student {
        public:
                Postgraduate(string idvar,float cgpavar,int feevar):Student(idvar,cgpavar,feevar){cout << "PG constructor" <<endl;}
                ~Postgraduate(){cout << "PG destructor" <<endl;}
                void display(){
                        cout << "ID: "<<Person::id << "\n" << "CGPA: " << Student::cgpa << "\n" << "Fee: Rs." << Student::fee << "\n" << "Scholarship: Yes" << "\nAttendance: " << attendance <<endl;                }

};

class PHD : private Student {
        public:
                PHD(string idvar,float cgpavar,int feevar):Student(idvar,cgpavar,feevar){cout << "PHD constructor" <<endl;}
                ~PHD(){cout << "PHD destructor" <<endl;}
                void display(){
                        cout << "ID: "<< Person::id << "\n" << "CGPA: " << Student::cgpa << "\n" << "Fee: Rs." << Student::fee << "\n" << "Scholarship: Yes" << "\nAttendance: " << attendance<<endl;                }

};


class Staff : protected Person{
        protected:
                int salary;
        public:
                Staff(string idvar, int salaryvar) : Person(idvar), salary(salaryvar) {}
};
class Faculty : private Staff {
        public:
                Faculty(string idvar, int salaryvar) : Staff(idvar, salaryvar){}

        void display(){cout << "ID: "<< Person::id << "\n Salary: " << Staff::salary <<endl;}

};

class Admin : private Staff {
        public:
                Admin(string idvar, int salaryvar) : Staff(idvar, salaryvar){}
        void display(){cout << "ID: "<< Person::id << "\n Salary: " << Staff::salary <<endl;}

};


int main() {
    // Sample usage
    Undergraduate ug("UG123", 3.8, 2000, true);  // The boolean is an expression that indicates whether the student has a scholarship or not
    Postgraduate pg("PG456", 4.0, 2500);
    ug.updateAttendance();
    PHD phd("PHD789", 4.2, 3000);

    Faculty fac("FAC101", 6000);
    Admin admin("ADM202", 4000);

    cout << "Student Information:" << endl;
    ug.display();
    pg.display();
    phd.display();

    cout << "\nStaff Information:" << endl;

    fac.display();
    admin.display();

    return 0;
}
