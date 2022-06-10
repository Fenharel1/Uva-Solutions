#include <bits/stdc++.h>
using namespace std;

long long pol[25];
long long grado, d, k;

int main(){
  long long tc; cin >> tc;
  while(tc--){
    memset(pol, 0, sizeof(pol));
    cin >> grado; 
    for(long long i = 0; i <= grado; i++) cin >> pol[i];
    cin >> d >> k;
    long long n = 1, tmp = d, aux = tmp;
    while(tmp < k){ tmp += (++n)*d;}
    long long suma = 0;
    for(long long i = 0; i <= grado; i++){
      double aux3 = pow(n,i);
      suma += pol[i] * aux3;
    }
    cout << suma << endl;
    
  }
  return 0;
}