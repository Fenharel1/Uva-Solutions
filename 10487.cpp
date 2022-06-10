#include <bits/stdc++.h>
using namespace std;
int input[1005];
int n, m;

int main(){
  int tc = 0;
  while(cin >> n, n!=0){
    for(int i = 0; i < n; i++) cin >> input[i];
    cin >> m;
    cout << "Case "<< ++tc << ":" << endl;
    while(m--){
      int query, minDiff = -1, ans;
      cin >> query;
      for(int i = 0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
          if(i !=j && input[i] != input[j]){
            int sum = input[i] + input[j];
            int diff = abs(sum - query);
            if(minDiff == -1 || diff < minDiff){
              minDiff = diff;
              ans = sum;
            }
          }
        }
      }
      cout << "Closest sum to " << query << " is " << ans << ".\n";
    }
  }
  return 0;
}