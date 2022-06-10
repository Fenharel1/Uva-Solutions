#include <bits/stdc++.h>
using namespace std;

vector<long> sol2;
vector<long> sol4;
vector<long> sol6;
vector<long> sol8;

bool eval(long a, long b, long c){
  return (a+b)*(a+b) == c;
}

void Precalculate(){
  long a,b;
  for(long i = 0; i < 100000000; i++){
    if(i < 100){
      //if(i < 10) a = 0;
      //else a = i/10;
      a = i/10;
      b = i%10;
      if(eval(a,b,i)){
        sol2.push_back(i);
      }
    }
    if(i < 10000){
      a = i/100;
      b = i%100;
      if(eval(a,b,i)){
        sol4.push_back(i);
      }
    }
    if(i < 1000000){
      a = i/1000;
      b = i%1000;
      if(eval(a,b,i)){
        sol6.push_back(i);
      }
    }
    if(i < 100000000){
      a = i/10000;
      b = i%10000;
      if(eval(a,b,i)){
        sol8.push_back(i);
      }
    }
  }
}

void Mostrar(vector<long> &v, int n){
  for(int i = 0; i < v.size(); i++){
    if(n == 2)printf("%02ld\n", sol2[i]);
    if(n == 4)printf("%04ld\n", sol4[i]);
    if(n == 6)printf("%06ld\n", sol6[i]);
    if(n == 8)printf("%08ld\n", sol8[i]);
  }
}

int main(){
  Precalculate();
  int k;
  while(cin >> k){
    if(k == 2) Mostrar(sol2, 2);
    else if(k == 4) Mostrar(sol4, 4);
    else if(k == 6) Mostrar(sol6, 6);
    else if(k == 8) Mostrar(sol8, 8);
  }
  return 0;
}