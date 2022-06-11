#include <bits/stdc++.h>
using namespace std;

class myInt{
  private:
  int dato;

  public:
  myInt(int a){
    dato = a;
  }
  myInt(){
    dato = 0;
  }

  myInt operator+(myInt op2){
    myInt Ans(dato * op2.dato);
    return Ans;
  }

  void print(){
    cout << dato << endl;
  }
};

int main(){
  myInt a(-2), b(10), c; 
  c = a+b; 
  c.print();
  return 0;
}