#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n;
int input[N], start[N], freq[N], tree[2*N];
void build(int arr[]){
  for(int i = 0; i < n; i++){
    tree[n+i] = arr[i];
  }
  for(int i = n-1; i > 0; i--){
    tree[i] = max(tree[i<<1],tree[i<<1 | 1]);
  }
}

int query(int l, int r){
  int res = 0;
  for(l+=n, r+=n; l < r; l >>= 1, r >>= 1){
    if(l&1) res = max(res, tree[l++]);
    if(r&1) res = max(res, tree[--r]);
  }
  return res;
}

int main(){
  int q;
  map<int,int> mp;
  while(cin >> n, n!=0){
    mp.clear();
    cin >> q;
    for(int i = 0; i < n; i++){
      cin >> input[i];
      mp[input[i]]++;
      if(mp[input[i]]==1){
        start[i] = i;
      }else{
        start[i] = start[i-1];
      }
    }
    for(int i = 0; i < n; i++){
      freq[i] = mp[input[i]];
    }
    build(freq);
    while(q--){
      int i,j;
      cin >> i >> j;
      i--; j--;
      if(input[i] == input[j])
        cout << j-i+1 << endl;
      else{
        int first = start[i] + freq[i];
        int last = start[j];
        int c1 = first - i;
        int c2 = j - last + 1;
        int c3 = query(first, last);
        cout << max(c1,max(c2,c3)) << endl;
      }
    }
  }
  return 0;
}