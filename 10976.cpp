#include <bits/stdc++.h>
using namespace std;
int as[10000];
int bs[10000];

int main(){
  int k;
  while(cin >> k){
    int cont = 0;
    for(int b = k+1; b <= k*2; b++){
      int a = k*b/(b-k);
      if(a*b == k*(a+b)){
        as[cont] = a;
        bs[cont] = b;
        cont++;
      }
    }
    cout << cont << endl;
    for(int i = 0; i < cont; i++){
      printf("1/%d = 1/%d + 1/%d\n", k, as[i], bs[i]);
    }
  }
  return 0;
}