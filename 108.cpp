#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int matrix[n][n];
  int memo[n][n];
  memset(memo, 0, sizeof(memo));

  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> matrix[i][j];

  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      memo[i][j] += matrix[i][j];
      if(i > 0) memo[i][j] += memo[i-1][j];
      if(j > 0){
        memo[i][j] += memo[i][j-1];
        if(i>0) memo[i][j] -= memo[i-1][j-1];
      }
    }
  }

  int ans = -1270005;

  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
    for(int p = i; p < n; p++) for(int q = j; q < n; q++){
      int valor = memo[p][q];
      if (i > 0) valor -= memo[i-1][q];
      if (j > 0){ 
        valor -= memo[p][j-1];
        if( i > 0){
          valor += memo[i-1][j-1];
        }
      }
      ans = max(ans, valor);
    }
  }

  cout << ans << endl;
  return 0;
}