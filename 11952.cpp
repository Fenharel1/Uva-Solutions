#include <bits/stdc++.h>
#define REP(i,a,b) for(i = a; i < b; i++) 
using namespace std;

int main(){
  int tc, Price;
  cin >> tc;
  for(int q = 1; q <= tc; q++){
    Price=0;
    int n,m,i,j,budget,ans=0;
    cin >> n >> m >> budget;
    int M[n][m];
    REP(i, 0,n)
      REP(j,0,m) cin >> M[i][j];
    i=j=0;

    REP(i, 0,n)
      REP(j,0,m){
        if(i>0) M[i][j] += M[i-1][j];
        if(j>0) M[i][j] += M[i][j-1];
        if(i>0&&j>0) M[i][j] -= M[i-1][j-1];
      }

    int i2,j2;
    REP(i, 0,n) REP(i2,i,n)
      REP(j, 0,m) REP(j2,j,m){
        int price = M[i2][j2];
        if(i>0) price -= M[i-1][j2];
        if(j>0) price -= M[i2][j-1];
        if(i>0&&j>0) price += M[i-1][j-1];
        int area = (i2-i+1) * (j2-j+1);
        if(price <= budget){
          if(area > ans){
            ans = area;
            Price = price;
          }else if(area == ans){
            if(price < Price) Price = price;
          }
        }
      }

    cout << "Case #" << q << ": " << ans << " " << Price << endl;
  }
  return 0;
}