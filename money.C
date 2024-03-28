#include <iostream>
using namespace std;

class Money{
  public:
    int rupees;
    int paise;

    Money(){rupees = paise = 0;}
    Money(int a, int b): rupees(a), paise(b){}

    Money operator +(Money const &v1){
      Money result;
      result.rupees = rupees + v1.rupees;
      result.paise = paise + v1.paise;
      if (result.paise>=100){
        result.rupees += result.paise/100;
        result.paise %= 100;
      }
      return result;
    }

    Money operator -(Money const &v1){
      Money result;
      int inflated1 = rupees*100 + paise;
      int inflated2 = v1.rupees*100 + v1.paise;
      int inf_res = inflated1-inflated2;
      if (inf_res<0){inf_res*=-1;}     
      result.rupees = inf_res/100;
      result.paise = inf_res%100;
      return result;
    }

    Money operator *(int n){
      Money result;
      int inflated1 = rupees*100 + paise;
      inflated1 *= n;
      if (inflated1<0){inflated1*=-1;}     
      result.rupees = inflated1/100;
      result.paise = inflated1%100;
      return result;
    }

};

int main(void){
  Money m1(20,70);
  Money m2(3,50);
  Money m3 = m1-m2;
  Money m4 = m1+m2;
  Money m5 = m1*3;
  //Money m5 = m1/3;
  cout<< m3.rupees << "." << m3.paise<<endl;
  cout<< m4.rupees << "." << m4.paise<<endl;
  cout<< m5.rupees << "." << m5.paise<<endl;
  return 0;
}