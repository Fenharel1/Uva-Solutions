#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc; cin >> tc;
  while(tc--){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int sum = 0;    
    for(int i = 1; i < n; i++){
      int cont = 0;
      for(int j = 0; j < i; j++)
        if(arr[j] <= arr[i]) cont++;
      sum += cont;
    }
    cout << sum << endl;

  }
  return 0;
}