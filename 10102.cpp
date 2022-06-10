#include <bits/stdc++.h>
using namespace std;

int manhattan(int x1, int y1, int x2, int y2){
  return abs(x1-x2) + abs(y1-y2);
}

vector<int> tresX;
vector<int> tresY;
vector<int> unoX;
vector<int> unoY;

int main(){
  int n;
  string row;
  while(cin >> n){
    //cout << "MALDITA SEA<<" << endl;
    tresX.clear();
    tresY.clear();
    unoX.clear();
    unoY.clear();
    int cont1 = 0, cont3 = 0;
    for(int i = 0; i < n; i++){
      cin >> row;
      //cout << row << endl;
      for(int j = 0; j < n; j++){
        if(row[j] == '1'){
          unoY.push_back(i);
          unoX.push_back(j);
        }
        if(row[j] == '3'){
          tresY.push_back(i);
          tresX.push_back(j);
        }
      }
    }

    int ans = -1;
    for(int i = 0; i < unoX.size(); i++){
      int aux = -1;
      for(int j = 0; j < tresX.size(); j++){
        int steps = manhattan(tresX[j], tresY[j], unoX[i], unoY[i]);
        //cout << steps << " alala " << aux << endl;
        if(aux == -1 || aux > steps)
          aux = steps;
      }
      //cout << aux << endl;
      ans = max(aux, ans);
    }
    cout << ans << endl;
  }
  return 0;
}