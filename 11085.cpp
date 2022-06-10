#include <bits/stdc++.h>
using namespace std;

int input[8], rows[8], solutions[92][8];
int idx = 0;

bool killed(int r, int col){
  bool cruz = 0;
  for(int i = 0; i < col; i++){
    if(rows[i] == r) cruz = 1;
    if(abs(col-i)==abs(rows[i]-r)) cruz = 1;
  }
  return cruz;
}
 
void Queens(int c){
  if(c == 8){
    memcpy(solutions[idx],rows,sizeof(rows));
    idx++;
    return;
  }
  for(int k = 0; k < 8; k++){
    if(killed(k,c)) continue;
    rows[c] = k;
    Queens(c+1);
  }
}

int evaluate(){
  int cont, ans=10000;
  for(int i = 0; i < 92; i++){
    cont = 0;
    for(int j = 0; j < 8; j++){
      if(input[j] != solutions[i][j]) cont++;
    }
    ans = min(ans, cont);
  }
  return ans;
}

int main(){
  int tc = 1;
  memset(rows, 0, sizeof(rows));
  Queens(0);
  while(cin >> input[0]){
    for(int i = 1; i < 8; i++){
      cin >> input[i];
      input[i]--;
    }
    input[0]--;
    int ans = evaluate();
    cout << "Case " << tc++ << ": " << ans << endl;
  }
  return 0;
}