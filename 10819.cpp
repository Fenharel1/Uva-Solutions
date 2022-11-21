#include <bits/stdc++.h>
#define MAX 105
#define INF 100000000
using namespace std;

int price[MAX];
int favour[MAX];
int memo[MAX][11005];

int n,m;
int Budget;

int solve(int idx, int budget, bool verify=0){
  if(idx==n)
    if(verify && Budget-budget<=2000) return -INF;
    else return 0;
  if(memo[idx][budget]!=-1) return memo[idx][budget];
  if(budget < price[idx]) return memo[idx][budget] = solve(idx+1, budget, verify);
  return memo[idx][budget] = max(solve(idx+1, budget, verify), favour[idx] + solve(idx+1, budget - price[idx], verify));
}

int main(){
  while(cin >> m >> n){
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < n; i++) cin >> price[i] >> favour[i];

    Budget=m;
    int ans1 = solve(0,m);
    memset(memo, -1, sizeof(memo));
    Budget=m+200;
    int ans2 = solve(0,m+200,1);
    cout << max(ans1,ans2) << endl;
  }
  return 0;
}