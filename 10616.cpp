#include <bits/stdc++.h>
using namespace std;

int N,Q,M,D;
long long nro[205];
long long memo[205][20][40];

int solve(int idx, int n, int sum){
  if(n == 0 && sum == 0) return 1;
  if(n == 0 && sum != 0) return 0;
  if(idx == N) return 0;
  if(memo[idx][n][sum] != -1) return memo[idx][n][sum];

  int op1 = solve(idx+1, n, sum);
  int op2 = solve(idx+1, n-1, (sum+nro[idx])%D);
  return memo[idx][n][sum] = op1 + op2;
}

int main() {
  int SET=1;
  while(cin >> N >> Q){
    if(N==0 && Q==0) break;
    for(int i = 0; i < N; i++) cin >> nro[i];
    cout << "SET " << SET++ << ":" << endl;
    for(int q = 1; q <= Q; q++){
      cin >> D >> M;
      memset(memo, -1, sizeof(memo));
      cout << "QUERY " << q << ": " << solve(0,M,0) << endl;
    }
  }
  return 0;
}