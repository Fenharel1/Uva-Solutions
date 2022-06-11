#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  while(cin >> n, n!=0){
    int arr[n+5];
    bool difcero = true;
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++){
      if(arr[i]>0){
        if(!difcero) cout << " ";
        cout << arr[i];
        difcero = false;
      }
    }
    if(difcero) cout << 0 << endl;
    else cout << endl;
  }
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//   int n;
//   while(cin >> n, n!=0){
//     int arr[n+5];
//     for(int i = 0; i < n; i++){
//       cin >> arr[i];
//     }
//     int i = 0, start = 0, end = 0, sum = 0, currSum = 0, tam = 0;
    
//     while(i < n){
//       if(arr[i] != 0){
//         int aux1 = i, aux2;
//         while(arr[i] != 0 && i < n){
//           currSum += arr[i];
//           aux2 = i;
//           i++;
//         }
//         if(currSum > sum || (currSum == sum && (end - start + 1) < tam)){
//           start = aux1;
//           end = aux2;
//           tam = end - start + 1;
//         }
//       }
//       i++;
//     }
//     for(int i = start; i <= end; i++){
//       if(i!=start) cout << " ";
//       cout << arr[i];
//     }
//     cout << endl;
//   }
//   return 0;
// }