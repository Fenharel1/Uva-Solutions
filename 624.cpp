#include <bits/stdc++.h>
using namespace std;

int duration[25];
int n, ans, maskAns, Cap;

void CDs(int i, int mask, int total){
  if(total > Cap) return;
  if(total > ans) {
    ans = total;
    maskAns = mask;
  }
  if(i == n){
    return;
  }
  CDs(i+1, mask, total);
  CDs(i+1, mask|(1<<i), total + duration[i]);
}

int main(){
  while(cin >> Cap >> n){
    ans = 0;
    maskAns = 0;
    memset(duration, 0, sizeof(duration));
    for(int i = 0; i < n; i++) cin >> duration[i];
    CDs(0,0,0);
    for(int i = 0; i < n; i++){
      if(maskAns&(1<<i)) cout << duration[i] << " ";
    }
    cout << "sum:" << ans << endl;
  }
  return 0;
}