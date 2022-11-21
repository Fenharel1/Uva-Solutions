#include <bits/stdc++.h>
using namespace std;
int pc[10][2];

float dist(int i, int j){
  return sqrt(pow(pc[i][0]-pc[j][0],2) + pow(pc[i][1]-pc[j][1],2));
}

int main(){
  int tc = 1;
  int n;
  while(cin >> n, n){
    int idx[n];
    int ans[n];

    for(int i = 0; i < n; i++){
      idx[i] = i;
      cin >> pc[i][0] >> pc[i][1];
    }

    float total_cable = 1000000;
    do{
      float sum = 0;
      for(int i = 0; i < n; i++){
        if(i +1 != n)
          sum += dist(idx[i],idx[i+1])+16;
      }
      if(total_cable > sum){
        total_cable = sum;
        for(int i = 0; i < n; i++){
          ans[i] = idx[i];
        }
      }
    }while(next_permutation(idx, idx+n));

    cout << "**********************************************************" << endl;
    cout << "Network #" << tc++ << endl;
    for(int i = 0; i < n-1; i++){
      printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",
      pc[ans[i]][0], pc[ans[i]][1], pc[ans[i+1]][0], pc[ans[i+1]][1], 16+dist(ans[i], ans[i+1]));
    }
    printf("Number of feet of cable required is %.2f.\n",total_cable);
  }

  return 0;
}