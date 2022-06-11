#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while(cin >> n, n!=0){
    int ans = 0, curr = 0;
    for(int i = 0; i < n; i++){
      int x; cin >> x;
      if(curr + x < 0){
        curr = 0;
        continue;
      }
      curr += x;
      ans = max(ans, curr);
    }
    if(ans > 0) cout << "The maximum winning streak is " << ans << "." << endl;
    else cout << "Losing streak." << endl;
  }
  return 0;
}