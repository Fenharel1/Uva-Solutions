#include <bits/stdc++.h>
#define max3(a,b,c) max(a,max(b,c))
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

void print(MyBigInt a, bool ENDL = true){
  if(a.signo == MINUS) printf("-");
  for(int i = a.digitos.size() - 1; i >= 0; i--) cout << a.digitos[i];
  if(ENDL) cout << endl;
}

MyBigInt multiply(MyBigInt a, MyBigInt b){
  if(a.digitos == "0" || b.digitos == "0") return MyBigInt("0");

  string c;
  c.resize(a.digitos.size() + b.digitos.size(), '0');
  int carry = 0, i=0, j=0;
  for(; i < b.digitos.size(); i++){
    carry = 0;
    for(j = 0; j < a.digitos.size(); j++){
      int total = 
        (a.digitos[j] - '0') * (b.digitos[i] - '0') + (c[i+j] - '0') + carry;
      c[i+j] = static_cast<char>('0' + total%10);
      carry = total / 10;
    }    
    c[i+j] = static_cast<char>('0' + carry);
  }

  while(c[c.size()-1]=='0')
    c = c.substr(0, c.size()-1);
  MyBigInt ans(a.signo == b.signo ? PLUS:MINUS, c);
  return ans;
}

MyBigInt maxim(MyBigInt a, MyBigInt b){
  if (a.signo != b.signo){
    if(a.signo == PLUS) return a;
    else return b;
  }else{
    if(a.digitos.size() > b.digitos.size()) return a;
    else if(b.digitos.size() > a.digitos.size()) return b;
    else {
      for(int i = a.digitos.size()-1; i >= 0; i--){
        if(a.digitos[i] > b.digitos[i]) return a;
        else if(b.digitos[i] > a.digitos[i]) return b;
      }
      return a;
    }
  }
}


vector <MyBigInt> V;
vector <int> v;

int main(){
  string x;
  int n = 0;
  while(cin >> x){
    if(x == "-999999"){
      MyBigInt max1("1");
      MyBigInt ans = V[0];

      for(int i = 0; i < n; i++){
        if(V[i].digitos == "0"){
          ans = maxim(ans,MyBigInt("0"));
          max1.digitos = "1";
          max1.signo = PLUS;
          continue;
        }
        max1 = multiply(max1, V[i]);
        ans = maxim(ans, max1);
      } 
      reverse(V.begin(), V.end());

      max1.digitos = "1";
      max1.signo = PLUS;

      ans = maxim(ans, V[0]);
      for(int i = 0; i < n; i++){
        if(V[i].digitos == "0"){
          ans = maxim(ans,MyBigInt("0"));
          max1.digitos = "1";
          max1.signo = PLUS;
          continue;
        }
        max1 = multiply(max1, V[i]);
        ans = maxim(ans, max1);
      } 

      print(ans);
      V.clear();
      n = 0;
    }else{
      n++;
      V.push_back(MyBigInt(x));
    }
  }
  return 0;
}