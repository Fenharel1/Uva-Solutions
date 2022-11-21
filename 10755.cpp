#include <bits/stdc++.h>
using namespace std;
#define ll long long

int a,b,c;
ll m[25][25][25];

ll getSum(int y1, int z1, int y2, int z2, int x){
  return m[x][y2][z2] - m[x][y1-1][z2] - m[x][y2][z1-1] + m[x][y1-1][z1-1];
}

int main(){
  int tc;
  cin >> tc;
  while(tc--){
    cin >> a >> b >> c;
    ll ans = 0, x;
    for(int i = 1; i <= a; i++){
      for(int j = 1; j <= b; j++){
        for(int k = 1; k <= c; k++){
          cin >> x;
          ans += x;
          m[i][j][k]=x+m[i][j][k-1]+m[i][j-1][k]-m[i][j-1][k-1];
        }
      }
    }

    for(int i = 1; i <= b; i++){
      for(int i1 = i; i1 <= b; i1++){
        for(int j = 1; j <= c; j++){
          for(int j1 = j; j1 <= c; j1++){
            ll aux = 0;
            for(int z = 1; z <= a; z++){
              aux += getSum(i,j,i1,j1,z);
              ans = max(ans, aux);
              if(aux < 0) aux=0;
            }
          }
        }
      }
    }

    cout << ans << endl;
    if(tc) cout << endl;
  }
}