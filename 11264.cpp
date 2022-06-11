#include <bits/stdc++.h>
using namespace std;

long long coins[1005];
int main(){
  int tc; cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> coins[i];
    coins[n] = 2*coins[n-1]-1;
    long long v = 0, ans = 0;
    for(int i = 0; i < n; i++){
      if(v + coins[i] < coins[i+1]){
        v += coins[i];
        ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}