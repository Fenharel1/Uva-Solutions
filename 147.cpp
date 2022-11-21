#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

int coins[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
ull memo[15][30005];

ull ways(int type, int value){
  if(value < 0) return 0;
  if(value == 0) return 1;
  if(type == 11) return 0;
  if(memo[type][value] != -1) return memo[type][value];
  return memo[type][value] = ways(type+1, value) + ways(type, value-coins[type]);
}

int convert(string m){
  int len = m.size();
  return atoi(&(m.substr(0,len-3))[0])*100 + atoi(&(m.substr(len-2))[0]);
}

int main(){
  memset(memo,-1,sizeof(memo));
  ull ans[30005];
  for(int i = 0; i <= 30000; i++){
    ans[i] = ways(0,i);
  }
  string moneda_str;
  while(cin >> moneda_str){
    int moneda = convert(moneda_str);
    if(moneda == 0) return 0;
    printf("%6s%17llu\n",&moneda_str[0], ans[moneda]);
  }

  return 0;
  
}