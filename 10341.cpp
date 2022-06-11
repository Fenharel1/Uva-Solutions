#include <bits/stdc++.h>
using namespace std;

float p,q,r,s,t,u,x,a,b;

float funcion(float valor){
  return p*exp(-valor) + q*sin(valor) + r*cos(valor) + s*tan(valor) + t*valor*valor + u;
}

void sol(){
  float delta = 0.001, fx;
  while(funcion(x) != 0){
    x = (a+b) / 2;
    cout << x << endl;
    if(funcion(a)*funcion(x) > 0) a = x;
    else if(funcion(b)*funcion(x) > 0) b = x;
    if(abs(funcion(x) < delta)) break;
  }
  cout << funcion(x) << " " << x << endl;
}

int main(){
  while(cin >> p >> q >> r >> s >> t >> u){
    a = 0; b = 1;
    sol();
  }
  return 0;
}