#include <bits/stdc++.h>
using namespace std;
int n, m, S;
int vcon[45];
int vdig[45];

int memo[405][405];
int xf, yf;

int solve(int x, int y){
  if(x==0 && y == 0) return 0;
  if(x<0 || y < 0) return 1000;
  if(memo[x][y]!=-1) return memo[x][y];
  int ans=1000;
  for(int i = 0; i < m; i++){
    ans = min(ans, 1 + solve(x-vcon[i], y-vdig[i]));
  }
  return memo[x][y] = ans;
}

int main(){
  cin >> n;
  while(n--){
    cin >> m;
    cin >> S;
    vector <int> xd, yd;
    memset(memo, -1, sizeof(memo));
    int r = S;
    for(int x = 0; x <= r; x++){
      float y = sqrt(r*r - x*x);
      if(y == (int)y){
        xd.push_back(x);
        yd.push_back(y);
      }
    }
    for(int i = 0; i < m; i++){
      cin >> vcon[i] >> vdig[i];
    }
    int rpta = 1000;
    for(int i = 0; i < xd.size(); i++){
      xf = xd[i]; yf = yd[i];
      rpta = min(rpta, solve(xf,yf));
    }
    if(rpta==1000) cout << "not possible" << endl;
    else cout << rpta << endl;
  }

  return 0;
}