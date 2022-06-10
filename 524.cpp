#include <bits/stdc++.h>
using namespace std;

int n;
int ring[20];
bool used[20];

bool primo(int x){
  for(int i = 2; i < x; i++){
    if(x%i==0) return false;
  }
  return true;
}

void Solve(int k){
  if(k == n+1){
    if(primo(ring[n]+ring[1])){
      for(int i = 1; i <= n; i++){
        if(i != 1) cout << " ";
        cout << ring[i];
      }
      cout << endl;
    }
    return;
  }
  for(int i = 2; i <= n; i++){
    if(used[i]) continue;
    if(primo(i+ring[k-1])){
      used[i] = true;
      ring[k] = i; 
      Solve(k+1);
      used[i] = false;
    }
  }
}

int main(){
  int tc = 1;
  while(cin >> n){
    if(tc!=1 )cout << endl;
    ring[1] = 1;
    memset(used,0,sizeof(used));
    for(int i = 0; i < 20; i++){
      used[i] = false;
    }
    cout << "Case " << tc++ << ":" <<endl;
    Solve(2);
  }
  return 0;
}