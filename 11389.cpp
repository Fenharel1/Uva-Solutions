#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,d,r;
  while(cin >> n >> d >> r, n && d && r){
    int morning[n], evening[n];
    for(int i = 0; i < n; i++) cin >> morning[i];
    for(int i = 0; i < n; i++) cin >> evening[i];
    sort(morning, morning+n);
    sort(evening, evening+n);
    reverse(evening, evening+n);
    int sum = 0;
    for(int i = 0; i < n; i++){
      int aux = (morning[i] + evening[i] - d) * r;
      if (aux >= 0) sum += aux;
    }
    cout << sum << endl;
  }
  return 0;
}