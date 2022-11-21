#include <bits/stdc++.h>
#define MAX 4000
using namespace std;

int coins[5] = {1,5,10,25,50};
int Value, n=5;
long long memo[10][30005]; // 500 is the max of value
long long ans[30005];

/*
penny1: 1c
nickel: 5c
dime: 10c
quarter: 25c
half-dollar: 50c
*/

long long Solve(int type, int value){
  if(value < 0) return 0;
  if(memo[type][value] != -1) return memo[type][value];
  if(value == 0) return memo[type][value] = 1;
  if(type==n) return memo[type][value] = 0;
  return memo[type][value] = Solve(type+1, value) + Solve(type, value - coins[type]);
}

int main(){
  memset(memo, -1, sizeof(memo));
  for(int i = 0; i <= 30000; i++){
    ans[i] = Solve(0,i);
  }

  while(cin >> Value){
    if(ans[Value]==1) printf("There is only 1 way to produce %d cents change.\n", Value);
    else{
      cout << "There are " << ans[Value] << " ways to produce " << Value << " cents change." << endl;
    }
  }

  return 0;
}