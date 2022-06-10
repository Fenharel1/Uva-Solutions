#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  int contCase = 1;
  while(cin >> n){
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int q = 0;
    long long sum = 0, aux;
    while(q != n){
      for(int i = 0; i < n - q; i++){
        aux = arr[i];
        for(int j = i+1; j <= i + q; j++){
          aux *= arr[j];
        }
        if(aux > 0) sum = max(sum, aux);
      }
      q++;
    }
    printf("Case #%d: The maximum product is %lld.\n\n", contCase, sum);
    contCase++;
  }
  return 0;
}