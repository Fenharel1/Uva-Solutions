/*#include <bits/stdc++.h>
using namespace std;

int inicio[5005];
int fin[5005];
int height[5005];

int main(){
  int l,h,r;
  memset(inicio, 0, sizeof(inicio));
  memset(fin, 0, sizeof(fin));
  memset(height, 0, sizeof(height));
  int idx = 0;
  int tam = 0;
  int maxFin = -1;
  while(cin >> l >> h >> r){
    inicio[idx] = l;
    height[idx] = h;
    fin[idx] = r;
    maxFin = max(maxFin, r);
    idx++;
    tam++;
  }
  vector<int> coords;

  int xactual=inicio[0], bactual = 0, tmp = 0;
  while(inicio[tmp] == inicio[bactual]){
    if(height[tmp] > height[bactual])bactual = tmp;
    tmp++;
  }
  //cout << "ter" << endl;
  xactual = inicio[bactual];
  //cout << "maxfin " << maxFin << endl;
  while(xactual < maxFin){
    //cout << ">>>>> " << xactual << " " << bactual << endl;
    coords.push_back(xactual);
    coords.push_back(height[bactual]);
    int i = bactual;
    int altMinMax = -1, idMinMax;
    bool noenc = 1, noHaymas=1;
    for(int j = 0; j < tam; j++){
      if(i == j) continue;
      if(fin[j] <= xactual) continue;
      if(inicio[j] < fin[i] && inicio[i] < fin[j]){
        if(height[j] > height[i] && fin[i] != fin[j]){
          //cout << "Primera altura mayor: " << height[j] << " " << j << endl;
          //coords.push_back(inicio[j]);
          //coords.push_back(height[j]);
          int tmp = j;
          bactual = j;
          while(inicio[tmp] == inicio[bactual]){
            if(height[tmp] > height[bactual]) bactual = tmp;
            tmp++;
          }

          xactual = inicio[j];
          //bactual = j;
          noenc = 0;
          noHaymas = 0;
          break;
        }
        if(fin[j] > fin[i]){
          noHaymas = 0;
          if(altMinMax == -1 || altMinMax < height[j]){
            altMinMax = height[j];
            idMinMax = j;
          }
        }
      }
    }
    if(noHaymas){
      coords.push_back(fin[bactual]);
      coords.push_back(0);
      int aux = bactual+1;
      while(inicio[aux] <= fin[bactual])
        aux++;
      int tmp = aux;
      bactual = aux;
      while(inicio[tmp] == inicio[bactual] && tmp < tam){
        if(height[tmp] > height[bactual]) bactual = tmp;
        tmp++;
      }
      xactual = inicio[bactual];
      continue;
    }
    if(noenc){
      //cout << "Maxima altura por debajo: " << height[idMinMax] << " " << idMinMax << " ori " << i << endl;
      //coords.push_back(fin[i]);
      //coords.push_back(height[idMinMax]);
      xactual = fin[i];
      bactual = idMinMax;
    }
  }
  int tamCoords = coords.size();
  for(int i = 0; i < tamCoords; i++){
    cout << coords[i];
    if(i < tamCoords-1) cout << " ";
  }
  cout << endl;
  return 0;
}
*/

#include <bits/stdc++.h>
using namespace std;

int coord[10005];

int main(){
  int l,h,r;
  memset(coord, 0, sizeof(coord));
  int Min = 100000, Max = -1;
  while(cin >> l >> h >> r){
    Min = min(Min, l);
    Max = max(Max, r);
    for(int i = l; i < r; i++) coord[i] = max(coord[i],h);
  }

  for(int i = Min; i <= Max; i++){
    if(coord[i] != coord[i-1]){
      if(i > Min) cout << " ";
      cout << i << " " << coord[i];
    }
  }
  cout << endl;
  return 0;
}