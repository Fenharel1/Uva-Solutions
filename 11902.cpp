#include <bits/stdc++.h>
#define MAX 105
using namespace std;

typedef vector<int> vi;

int graph[MAX][MAX];
char dominator[MAX][MAX];
bool visited[MAX];
bool initial[MAX];
int n;

void line(){
  cout << "+"; for(int i = 0; i < 2*n-1; i++ ) cout << "-"; cout << "+\n";
}
void dfs(int node, int node_ignore = -1){
  if(node == node_ignore) return;
  visited[node] = true;
  for(int i = 0; i < n; i++){
    if(graph[node][i]==0 || visited[i]==true) continue;
    dfs(i, node_ignore);
  }
}

int main(){
  int tc; cin >> tc;
  for(int q = 1; q <= tc; q++){
    cin >> n;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++)
        cin >> graph[i][j];
    }
    memset(visited,false,sizeof(visited));
    dfs(0);
    for(int i = 0; i < n; i++) initial[i] = visited[i];

    for(int i = 0; i < n; i++){
      memset(visited,false,sizeof(visited));
      dfs(0,i);
      for(int j = 0; j < n; j++){
        dominator[i][j] = (visited[j]||!initial[j])?'N':'Y';
      }
    }
    cout << "Case " << q << ":" << endl;
    line();
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n ; j++){
        if(j==0)cout << "|";
        cout << dominator[i][j] << "|";
      }
      cout << endl;
      line();
    }
  }    
  return 0;
}
