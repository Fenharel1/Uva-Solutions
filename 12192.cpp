#include <bits/stdc++.h>
#define MAX 505
using namespace std;

int n, m, q, L, R;
vector<int> start, finish, matrix[MAX];

int idxLower(int row, int value){
  return lower_bound(matrix[row].begin(), matrix[row].end(), value) - matrix[row].begin();
}

int idxUpper(int row, int value){
  return upper_bound(matrix[row].begin(), matrix[row].end(), value) - matrix[row].begin()-1;
}

void sol(){
  for(int i = 0; i < n; i++){
    int aux;
    aux = idxUpper(i,R);
    finish.push_back(aux);
    aux = idxLower(i,L);
    start.push_back(aux);
  }
  int ans = -1;
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      ans = max(ans, min(finish[j] - start[i] + 1, j - i + 1));
    }
  }
  cout << ans << endl;
}

int main(){
  ios_base::sync_with_stdio(0);
	cin.tie(0);
  while(cin >> n >> m, n!=0 && m != 0){
    for(int i = 0; i < n; i++) matrix[i].clear();
    for(int i = 0; i < n; i++){
      for(int x,j = 0; j < m; j++){
        cin >> x;
        matrix[i].push_back(x);
      }
    }

    cin >> q;
    while(q--){
      start.clear();
      finish.clear();
      cin >> L >> R;
      sol();
    }
    cout << "-" << endl;
  }
  return 0;
}