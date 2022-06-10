#include <bits/stdc++.h>
using namespace std;

int t, n, cont = 0;
int arr[15];
bool used[15];

map<string, int> unico;

void Sol(int total, int k){
  if(total == t){
    cont++;
    string sol = "";
    for(int i = 0; i < n; i++){
      if(!used[i]) continue;
      sol += "+" + to_string(arr[i]);
    }
    if(unico[sol]==0){
      unico[sol] = 1;
      cout << sol.substr(1) << endl;
    }
    return;
  }
  for(int i = k; i < n; i++){
    if(!used[i] && (arr[i] + total) <= t){
      used[i] = true;
      Sol(total + arr[i], k+1);
      used[i] = false;
    }
  }
}

int main(){
  while(cin >> t >> n, n!=0){
    unico.clear();
    memset(used,0,sizeof(used));
    for(int i = 0; i < n; i++) cin >> arr[i];
    cout << "Sums of " << t << ":" << endl;
    cont = 0;
    Sol(0,0);
    if(cont == 0) cout << "NONE" << endl;
  }
  
  return 0;
}