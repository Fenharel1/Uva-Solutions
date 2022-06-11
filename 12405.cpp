#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc; cin >> tc;
  for(int q = 1; q <= tc; q++){
    int n; cin >> n;
    char a[n+4];
    a[0] = a[n+1] = a[n+2] = '#';
    for(int i = 1; i <= n; i++) cin >> a[i];
    printf("Case %d: ", q);
    int cont = 0;
    for(int i = 1; i <= n; i++){
      if(a[i] == '#') continue;
      i+=2;
      cont++;        
    }
    cout << cont << endl;
  }
  return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int sum(char s[], int l, int r){
  int ans = 0;
  for(int i = l; i <= r; i++)
    ans += s[i] == '.' ? 1 : 0;
  return ans;
}

int main(){
  int tc; cin >> tc;
  for(int q = 1; q <= tc; q++){
    int n; cin >> n;
    char a[n+4];
    a[0] = a[n+1] = a[n+2] = a[n+3] = '#';
    for(int i = 1; i <= n; i++) cin >> a[i];
    printf("Case %d: ", q);
      int cont = 0;
      for(int i = 1; i <= n; i++){
        if(a[i] == '#') continue;
        int op1 = sum(a, i, i+1);
        int op2 = sum(a, i, i+2);
        if(op1 == 0 && op2 == 0){
          i+=2;
          continue;
        }
        else{
          if(op1 > op2){
            i++;
          }else if(op2 >= op1){
            i+=2;
          }
          cont++;
        }
      }
      cout << cont << endl;
  }
  return 0;
}
*/