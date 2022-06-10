#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

string Nombres[MAX];
int low[MAX], high[MAX];
int d, q, p;

void Buscar(int price){
  int cont = 0, idx;
  for(int i = 0; i < d; i++) 
    if (price >= low[i] && price <= high[i]){
      cont++;
      idx = i;
    }
  if(cont == 1) cout << Nombres[idx] << endl;
  else cout << "UNDETERMINED" << endl;
  
}

int main(){
  int tc; cin >> tc;
  while(tc--){
    cin >> d;
    for(int i = 0; i < d; i++) cin >> Nombres[i] >> low[i] >> high[i];
    cin >> q;
    while(q--){
      cin >> p;
      Buscar(p);
    }
    if(tc) cout << endl;
  }
  return 0;
}