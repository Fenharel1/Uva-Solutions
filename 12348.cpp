#include <bits/stdc++.h>
using namespace std;

int conjs[111];

int value(int x){
  int sum = 0;
  while(x){
    sum += (x&1);
    x >>= 1;
  }
  return sum;
}

int suma(int x, int crit){
  int aux = x&crit;
  return value(aux);
}

int main(){
  int tc; cin >> tc;
  string ansTotal = "";
  while(tc--){
    memset(conjs, 0, sizeof(conjs));
    int n,m; cin >> n >> m;
    char input[100];
    cin.ignore();
    for(int i = 0; i < m; i++){
      cin.getline(input, 100, '\n');
      istringstream iss(input);
      int nro;
      while(iss >> nro){
        conjs[i] |= 1 << (nro-1);
      }

      // int aux = conv(input);
      // conjs[i] = aux;
    }

    bool logr = 0;
    for(int i = 0; i < (1<<n); i++){
      bool flag = 1;
      for(int j = 0; j < m; j++){
        // bool red = false, blue = false;
        // for(int q = 0; q < n; q++){
        //   if(conjs[j] & (1<<q)){
        //     if(i & (1<<q)) red = true;
        //     else blue = true;
        //   }
        // }
        // if(!(red && blue)){
        //   flag = 0;
        //   break;
        // }
        int sum = value(conjs[j]);
        int sum2 = suma(conjs[j],i);
        if(sum2 >= sum || sum2 == 0){
          flag = 0;
          break;
        }
      }
      if(flag){
        logr = 1;
        break;
      }
    }
    if(logr) ansTotal += "Y";
    else ansTotal += "N";
  }

  cout << ansTotal << endl;

  return 0;
}