#include <bits/stdc++.h>
using namespace std;

const int MINUS = -1; 
const int PLUS = 1;   

class MyBigInt{
  public:
  int signo;
  string digitos;

  MyBigInt(string nro){
    if(nro.size()!=0){
      signo = nro[0]=='-'?MINUS:PLUS;
      digitos = nro.substr(signo==MINUS?1:0);
      reverse(digitos.begin(), digitos.end());
    }
  }

  MyBigInt(int _signo, string _digitos){
    signo = _signo;
    digitos = _digitos;
  }

  MyBigInt multiply(MyBigInt b){
    string c;
    c.resize(digitos.size() + b.digitos.size(), '0');
    int carry = 0;
    for(int i = 0; i < b.digitos.size(); i++){
      for(int j = 0; j < digitos.size(); j++){
        int total = 
          (digitos[j] - '0') * (b.digitos[i] - '0') + (c[i+j] - '0') + carry;
        c[i+j] = static_cast<char>('0' + total%10);
        carry = total / 10;
      }
    }
    while(c[c.size()-1]=='0')
      c = c.substr(0, c.size()-1);
    MyBigInt ans(signo == b.signo ? PLUS:MINUS, c);
    return ans;
  }

  void operator=(MyBigInt b){
    signo = b.signo;
    digitos = b.digitos;
  }
};

MyBigInt multiply(MyBigInt a, MyBigInt b){
  string c;
  c.resize(a.digitos.size() + b.digitos.size(), '0');
  cout << c << endl;
  int carry = 0, i, j;
  for(; i < b.digitos.size(); i++){
    for(j = 0; j < a.digitos.size(); j++){
      int total = 
        (a.digitos[j] - '0') * (b.digitos[i] - '0') + (c[i+j] - '0') + carry;
      c[i+j] = static_cast<char>('0' + total%10);
      carry = total / 10;
    }    
  }

  c[i+j-1] = static_cast<char>('0' + carry);
  cout << c << endl;
  while(c[c.size()-1]=='0')
    c = c.substr(0, c.size()-1);
  MyBigInt ans(a.signo == b.signo ? PLUS:MINUS, c);
  return ans;
}

void print(MyBigInt a, bool ENDL = true){
  if(a.signo == MINUS) printf("-");
  for(int i = a.digitos.size() - 1; i >= 0; i--) cout << a.digitos[i];
  if(ENDL) cout << endl;
}

int main(){
  string n1, n2;
  cin >> n1 >> n2;
  MyBigInt a(n1), b(n2);
  print(multiply(a,b));
  return 0;
}