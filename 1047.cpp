#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> combinations;

void Combi(int a[], int reqLen, int s, int currLen, bool check[], int l)
{
   if(currLen > reqLen)
   return;
   else if (currLen == reqLen) {
      vector<int> aux;
      for (int i = 0; i < l; i++) {
         if (check[i] == true) {
            aux.push_back(a[i]);
         }
      }
      combinations.push_back(aux);
      return;
   }
   if (s == l) {
      return;
   }
   check[s] = true;
   Combi(a, reqLen, s + 1, currLen + 1, check, l);
   check[s] = false;
   Combi(a, reqLen, s + 1, currLen, check, l);
}

bool isIn(vector<int> L, int value){
  for(int i = 0; i < L.size(); i++){
    if(L[i] == value) return true;
  }
  return false;
}

int main() {
  int tc = 1;
  int nt, na;

  while(cin>> nt >> na, nt!=0 && na!=0){
    combinations.clear();
    bool check[nt];
    int towers[nt];
    int towersTotal[nt];

    for(int i = 0; i < nt; i++) {
      towers[i] = i;
      check[i] = false;
      cin >> towersTotal[i];
    }
    Combi(towers, na, 0, 0, check, nt);

    int m; cin >> m;
    vector<int> groups[m];
    int groupsCnt[m];
    for(int i = 0; i < m; i++){
      int ntg; cin >> ntg;
      for(int x, j = 0; j < ntg; j++){
        cin >> x; 
        x--;
        groups[i].push_back(x);
      }
      cin >> groupsCnt[i];
    }
    //evaluamos todas las posibles combinaciones
    int ans = -1;
    int idxAns = -1;
    for(int i = 0; i < combinations.size(); i++){
      int total = 0;
      for(int j = 0; j < combinations[i].size(); j++) total += towersTotal[combinations[i][j]];
      for(int a = 0; a < m; a++){
        int cont = 0;
        for(int b = 0; b < groups[a].size(); b++){
          if(isIn(combinations[i], groups[a][b])) cont++;
        }
        if(cont > 1){
          total -= groupsCnt[a]*(cont-1);
        }        
      }  
      if(total > ans){
        ans = total;
        idxAns = i;
      }
    }

    printf("Case Number  %d\n", tc++);
    printf("Number of Customers: %d\n", ans);
    printf("Locations recommended: ");
    for(int i = 0; i < na; i++){
      if(i != 0) cout << " ";
      cout << combinations[idxAns][i]+1;
    }
    cout << endl << endl;
  }
  return 0;
}