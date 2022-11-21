#include <bits/stdc++.h>
using namespace std;
int N,x,T,K;
int prices[105];
int favour[105];
int dp[205][100005];

int Solve(int idx, int budget) {
  if(idx == 2*K || budget < 0) return 0;
  if(dp[idx][budget] != -1) return dp[idx][budget];
  if(prices[idx] > budget) return dp[idx][budget] = Solve(idx+1,budget);
  return dp[idx][budget] = max( Solve(idx+1,budget), favour[idx] + Solve(idx+1, budget-prices[idx]));
}

int main(){
  while(cin >> N >> x >> T >> K){
    memset(favour,0,sizeof(favour));
    memset(dp,-1,sizeof(dp));

    if(!N&&!x&&!T&&!K) break;
    N++;
    for(int i = 0; i < 2*K; i+=2){
      cin >> prices[i];
      prices[i]= ((11*prices[i] + 9) / 10) * 100 ;
      prices[i+1] = prices[i];
      for(int j = 0; j < N; j++){
        int favor;
        cin >> favor;
        favour[i] += favor;
      }
      favour[i+1] = favour[i];
    }
    int budget = x*N*100 - 110*(T*N);
    INT_MIN;

    float ans = Solve(0,budget);
    cout << ans << endl;
    printf("%.2f\n", ans/N);
  }
  return 0;
}