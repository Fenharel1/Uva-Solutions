#include <bits/stdc++.h>
#define MAX 10000000
using namespace std;

int coins[105];
long long memo[105][30005];
int m;

long long Solve(int type, long long val){
  if(val == 0) return 0;
  if(val < 0) return MAX;
  if(type == m) return MAX;
  if(memo[type][val] != -1) return memo[type][val];
  long long minv = MAX;
  minv = min(Solve(type+1, val), 1 + Solve(type+1, val-coins[type]));
  // cout << type << " " << val << " minv " << minv << endl;
  return memo[type][val] = minv;
}

int main(){
  int n;
  cin >> n;
  while(n--){
    memset(memo, -1, sizeof(memo));
    long long valor;
    cin >> valor >> m;
    for(int i = 0; i < m; i++){
      cin >> coins[i];
    }
    
    long long rpta=0, valor_extra = valor;
    while(valor_extra != MAX){
      rpta = Solve(0,valor_extra);
      // cout << rpta << endl;
      if(rpta==MAX){
        valor_extra++;
      }else{
        break;
      }
    }
    cout << valor_extra << " " << rpta << endl;
  }
  return 0;
}