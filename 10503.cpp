#include <bits/stdc++.h>
using namespace std;

int n, m;
bool used[18], encontrado = 0;
pair<int,int> dom[18];
pair<int,int> solution[18];

void sol(int k){
  if(encontrado) return;
  if(k == n+1){
    if(solution[k].first == solution[k-1].second){
      cout << "YES" << endl;
      encontrado = true;
    }
    return;
  }
  for(int i = 1; i <= m; i++){
    if(!used[i]){
      used[i] = true;
      if(dom[i].first == solution[k-1].second){
        solution[k].first = dom[i].first;
        solution[k].second = dom[i].second;
        sol(k+1);
      }else if(dom[i].second == solution[k-1].second){
        solution[k].first = dom[i].second;
        solution[k].second = dom[i].first;
        sol(k+1);
      }
      used[i] = false;
    }
  }
}

int main(){
  int a, b;
  while(cin >> n, n!=0){
    cin >> m;
    encontrado = false;
    memset(used,0,sizeof(used));
    cin >> a >> b;
    solution[0].first = a;
    solution[0].second = b;
    cin >> a >> b;
    solution[n+1].first = a;
    solution[n+1].second = b;

    for(int i = 1; i <= m; i++){
      cin >> a >> b; 
      dom[i].first = a;
      dom[i].second = b;
    }
    sol(1);
    if(!encontrado) cout << "NO" << endl;

  }
  return 0;
}