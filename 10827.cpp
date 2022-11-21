#include <bits/stdc++.h>
#define MAX 80
using namespace std;
int n;
int input[MAX*2][MAX*2];
int memo[MAX*2][MAX*2];

int main(){
  int tc; cin >> tc;
  while(tc--){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        int x; cin >> x;
        input[i][j] = input[i+n][j] = input[i][j+n] = input[i+n][j+n] = x;
      }
    }

    for(int i = 0; i < 2*n; i++)
      for(int j = 0; j < 2*n; j++){
        memo[i][j] = input[i][j];
        if(i>0) memo[i][j] += memo[i-1][j];
        if(j>0) memo[i][j] += memo[i][j-1];
        if(i>0&&j>0) memo[i][j] -= memo[i-1][j-1];
      }

    int ans = -1000000;
    for(int i = 0; i < 2*n; i++) for(int i2 = i; i2 < i+n && i2 < 2*n; i2++)
      for(int j = 0; j < 2*n; j++) for(int j2 = j; j2 < j+n && j2 < 2*n; j2++) {
        int value = memo[i2][j2];
        if(i>0) value -= memo[i-1][j2];
        if(j>0) value -= memo[i2][j-1];
        if(i>0&&j>0) value += memo[i-1][j-1];
        ans = max(ans, value);
      }
        
    cout << ans << endl;
  }
  return 0;
}

/*
1 2 3 1 2 3
4 5 6 4 5 6
7 8 9 7 8 9
1 2 3 1 2 3
4 5 6 4 5 6
7 8 9 7 8 9
*/