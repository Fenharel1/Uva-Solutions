#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int n; cin >> n;
    int M[n][n];
    
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        cin >> M[i][j];

    int ans = 100000;
    int arr[8] = {0,1,2,3,4,5,6,7};

    do{
      int aux = 0;
      for(int i = 0; i < n; i++) aux+=M[i][arr[i]];
      ans = min(ans, aux);
    }while(next_permutation(arr,arr+n));

    cout << ans << endl;
  }

  return 0;
}