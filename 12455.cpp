#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc; cin >> tc;
  while(tc--){
    int x, n;
    cin >> x >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    bool f = 1;
    for(int i = 0; i < 1<<n; i++){
      int suma = 0;
      for(int j = 0; j < n; j++){
        if(i&(1<<j)) suma += arr[j];
      }
      if(suma == x){
        f = 0;
        cout << "YES" << endl;
        break;
      }
    }
    if (f) cout << "NO" << endl;
  }
  return 0;
}