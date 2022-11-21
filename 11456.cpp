#include <bits/stdc++.h>
using namespace std;

vector<int> lis;

int LIS(int arr[], int n, int _i){
  lis.clear();
  lis.push_back(arr[_i]);
  for(int i = _i+1; i < n; i++){
    int idx = lower_bound(lis.begin(), lis.end(), arr[i]) - lis.begin();
    if(idx == 0) continue;
    else if(idx == lis.size()) lis.push_back(arr[i]);
    else lis[idx] = arr[i];
  }
  return lis.size();
}

int LDS(int arr[], int n, int _i){
  lis.clear();
  lis.push_back(-arr[_i]);
  for(int i = _i+1; i < n; i++){
    int idx = lower_bound(lis.begin(), lis.end(), -arr[i]) - lis.begin();
    if(idx == 0) continue;
    else if(idx == lis.size()) lis.push_back(-arr[i]);
    else lis[idx] = -arr[i];
  }
  return lis.size();
}

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    for(int i = 0; i < n; i++){
      ans = max(ans, LIS(arr, n,i) + LDS(arr, n,i) - 1);
    }
    cout << ans << endl;
  }
  return 0;
}