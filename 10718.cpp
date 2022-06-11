// ERROR, FALTA TERMINAR

#include <bits/stdc++.h>
using namespace std;

int main(){
  long long l,u;
  long long n;
  while(cin >> n >> l >> u){
    long long m = l;
    long long resul = 0;

    for(int i = 32; i >= 0; i--){
      if(!(n&(1LL<<i))){
        if((m|(1LL<<i)) >= l && (m|(1LL<<i)) <= u){
          m = m|(1LL<<i);
        }
      }else{
        if((m&~(1LL<<i)) <= l){
          m = m&~(1LL<<i);
        }
      }
    }
    cout << m << endl;
  }
  return 0;
}