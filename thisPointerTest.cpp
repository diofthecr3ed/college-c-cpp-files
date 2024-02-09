#include <iostream>
using namespace std; 

class c{
	public: 
		int val1;
		int val2;
		c calc(){
			val1++;
			return *this;
		}
};

int main(void){

	c* c1 = new c();
	c1->val1 = 1;
	c1->val2 = 2;

	c result = c1->calc();
	cout << result.val1;
	delete c1;
return 0;
}
