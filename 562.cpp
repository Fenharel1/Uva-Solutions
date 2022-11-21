#include <bits/stdc++.h>
#define REP(i,n) for(i = 0; i < n; i++)
#define read_arr(arr,n) for(int i = 0; i < n; i++) cin >> arr[i];
#define show_arr(arr,n) for(int i = 0; i < n; i++) cout << arr[i] << ((i+1!=n)?" ":"\n");
#define max3(a,b,c) max(a,max(b,c))
using namespace std;

int n;
int arr[105];
int dp[105][50005];
int sum;

int solve(int idx, int suma) {
  if(idx == n || suma > sum/2) return abs(suma - (sum - suma));
  if(dp[idx][suma] != -1) {
    return dp[idx][suma];
  }
  int op1 = solve(idx + 1, suma);
  int op2 = solve(idx + 1, suma + arr[idx]);
  return dp[idx][suma] = min(op1,op2);  
}

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    memset(dp,-1,sizeof(dp));
    sum = 0;
    cin >> n;
    read_arr(arr,n);
    for(int i = 0; i < n; i++) sum+= arr[i];
    int q = solve(0,0);
    cout <<  q << endl;
  }
  return 0;
}