#include <bits/stdc++.h>
using namespace std;

string Names(int arr[]){
  string ans = "";
  for(int i = 0; i < 3; i++){
    ans += arr[i]==0?"B":(arr[i]==1?"G":"C");
  }
  return ans;
}

int main(){
  // 0 > brown
  // 1 > green
  // 2 > clear
  int bottles[3][3];
  while(cin >> bottles[0][0]){
    int bins[3] = {0, 1, 2};
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        if(i==0 && j==0) continue;
        cin >> bottles[i][j];
      }
    }

    int suma = 0, sumaMin;
    string codifi = "z";
    bool first=1;
    do{
      suma = 0;
      for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
          if(i==j) continue;
          suma += bottles[j][bins[i]];
        }
      }
      if((suma <= sumaMin) || first){
        if(suma == sumaMin) codifi = min(codifi,Names(bins));
        else codifi = Names(bins);
        sumaMin = suma;
        first = 0;
      }
    }while(next_permutation(bins,bins+3));
    cout << codifi << " " << sumaMin << endl;
  }

  return 0;
}