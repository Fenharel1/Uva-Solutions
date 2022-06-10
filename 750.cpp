#include <bits/stdc++.h>
using namespace std;

int solutions[92][8];
int rows[8];
int idx = 0;

bool place(int r, int c){
  for(int i = 0; i < c; i++){
    if(rows[i] == r || abs(rows[i]-r) == abs(i-c)) return false;
  }
  return true;
}

void Precalc(int c){
  if(c == 8){
    memcpy(solutions[idx], rows, sizeof(rows));
    idx++;
    return;
  }
  for(int r = 0; r < 8; r++){
    if(place(r,c)){
      rows[c] = r;
      Precalc(c+1);
    }
  }
}

int main(){
  Precalc(0);
  int tc;
  cin >> tc;
  while(tc--){
    int r,c; cin >> r >> c; 
    r--; c--;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    int cont = 1;
    for(int i = 0; i < 92; i++){
      if(solutions[i][c]==r){
        printf("%2d      ", cont);
        for(int j = 0; j < 8; j++)cout << solutions[i][j] << " ";
        cout << endl;
        cont++;
      }
    }
  }
  cout << endl;
  return 0;
}