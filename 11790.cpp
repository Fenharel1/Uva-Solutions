#include <bits/stdc++.h>
using namespace std;

int main(){
  int TC;
  scanf("%d", &TC);
  for(int tc = 1; tc <= TC; tc++){
    int n;
    scanf("%d", &n);
    int height[n], width[n];
    for(int i = 0; i < n; i++) cin >> height[i];
    for(int i = 0; i < n; i++) cin >> width[i];

    int lis[n], lds[n];
    for(int i = 0; i < n; i++) lis[i] = lds[i] = width[i];

    for(int i = 1; i < n; i++)
      for(int j = 0; j < i; j++)
        if(height[j] < height[i]) lis[i] = max(lis[i], lis[j] + width[i]);
    
    for(int i = 1; i < n; i++)
      for(int j = 0; j < i; j++)
        if(-height[j] < -height[i]) lds[i] = max(lds[i], lds[j] + width[i]);
    
    int LIS = 0, LDS = 0;
    for(int i = 0; i < n; i++){
      LIS = max(LIS, lis[i]);
      LDS = max(LDS, lds[i]);
    }

    if(LIS >= LDS)
      printf("Case %d. Increasing (%d). Decreasing (%d).\n",tc,LIS,LDS);
    else
      printf("Case %d. Decreasing (%d). Increasing (%d).\n",tc,LDS,LIS);

  }
  return 0;
}