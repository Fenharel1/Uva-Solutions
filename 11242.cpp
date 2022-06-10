#include <bits/stdc++.h>
using namespace std;

float spread(float d2, float d1){
  return d2 / d1;
}

float ratio(float n, float m){
  return n/m;
}

float round_(float conver){
  conver = roundf(conver*100.0f)/100.0f;
  return conver;
}

int main(){
  int f,r;
  while(cin >> f, f != 0){
    cin >> r;
    float front[f], rear[r];
    for(int i = 0; i < f; i++){
      cin >> front[i];
    }
    for(int i = 0; i < r; i++){
      cin >> rear[i];
    }
    int tam = f*r;
    float driveR[tam];
    int idx = 0;
    for(int i = 0; i < f; i++){
      for(int j = 0; j < r; j++){
        driveR[idx++] = rear[j] / front[i];
      }
    }
    sort(driveR, driveR + tam);
    float ans = -1;
    for(int i = 1; i < f*r; i++){
      if(ans == -1 || spread(driveR[i], driveR[i-1]) > ans){
        ans = spread(driveR[i], driveR[i-1]);
      }
    }
    printf("%.2f\n", round_(ans));
  }
  return 0;
}