#include <iostream>
#include <string>

using namespace std;

class Wallet{
	private: 
		double balance;
		friend class Admin;
		static int count;
	public:
		int id;
		Wallet();
		Wallet(double);
		Wallet(Wallet &);
		double getBalance();
		double topUp(double);
		bool sendMoney(Wallet*,double);
};
class Admin{
        public:
                bool mediateTransfer(Wallet*, Wallet*, double);
};
int Wallet::count = 0;

Wallet::Wallet(){id = count;count++;}
Wallet::Wallet(double money){balance = money; id = count; count++;}
Wallet::Wallet(Wallet & w){balance = w.balance; id = count; count++;}
double Wallet::getBalance(){return balance;}
double Wallet::topUp(double amount){balance += amount; return balance;}

bool Wallet::sendMoney(Wallet *receiver, double amount) {
		Admin mediator;	
	return mediator.mediateTransfer(this, receiver, amount);
}

bool Admin::mediateTransfer(Wallet* sender, Wallet* receiver, double amount){
    if (sender->balance >= amount) {
        sender->balance -= amount;
        receiver->balance += amount;
        return true;
    } else {
        cout << "Insufficient balance." << endl;
        return false;
    }
};

int main(void){

	Wallet *w1 = new Wallet(10000.00);
	Wallet *w2 = new Wallet(10000.00); 	
	Wallet *w3 = new Wallet(0.00);
	
	//cin >> "Enter amount to top off in w3: " >> endl;
	w3->topUp(1000.00);
	
	w1->sendMoney(w2,1600.50);	
	
	cout << "Balance in w1: " << w1 -> getBalance() << endl;
	cout << "Balance in w2: " << w2 -> getBalance() << endl;

	delete w1;
	delete w2;
	delete w3;
	return 0;
}
