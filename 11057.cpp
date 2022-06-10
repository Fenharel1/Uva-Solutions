#include <bits/stdc++.h>
using namespace std;

vector<int> nros;
int n, n1,n2, total;
int price1, price2;

void sol(){
  int diff = 100000000;
  for(int i = 0; i < n; i++){
    if(nros[i] > total) break;
    n1 = nros[i];
    n2 = lower_bound(nros.begin(),nros.end(),total-nros[i]) - nros.begin();
    if(n1+nros[n2]!=total || n2 == i) continue;
    if(abs(nros[n2]-n1) < diff){
      diff = abs(nros[n2]-n1);
      price1 = min(n1,nros[n2]);
      price2 = max(n1,nros[n2]);
    }
  }
}

int main(){
  while(cin >> n){
    nros.clear();
    for(int x,i = 0; i < n; i++){
      cin >> x;
      nros.push_back(x);
    } 
    cin >> total;
    sort(nros.begin(), nros.end());
    sol();
    printf("Peter should buy books whose prices are %d and %d.\n\n", price1, price2);
  }
  return 0;
}