#include <bits/stdc++.h>
using namespace std;

int n, tc, arr[100005];

bool can(int k){
  for(int i = 1; i <= n; i++){
    if(arr[i] - arr[i-1] > k) return false;
    else if(arr[i] - arr[i-1] == k) k--;
  }
  return true;
}

int main(){
  cin >> tc;
  int nro = 1;
  while(tc--){
    cin >> n;
    arr[0] = 0;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    int a = 1, b = 100000000;
    int m;
    while(b - a > 0){
      m = (a+b)/2;
      int v = can(m);
      if(v && !can(m-1)) break;
      else if(v) b = m;
      else if(!v) a = m;
    }
    cout << "Case " << nro++ << ": " << m << endl;
  }
  return 0;
}