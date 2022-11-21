#include <bits/stdc++.h>
#define MAX 21
#define INF 1<<30
using namespace std;

int graph[MAX][MAX];
int memo[MAX][1<<MAX];
int points[20][2];
int n;

int tsp(int pos, int mask){
  if(mask==pow(2,n)-1) return graph[pos][0];
  if(memo[pos][mask]!=-1) return memo[pos][mask];  
  int ans=INF;
  for(int i = 0; i < n; i++){
    if(mask&(1<<i)) continue;
    ans = min(ans, graph[pos][i] + tsp(i,mask|(1<<i)));
  }
  return memo[pos][mask] = ans;
}

int main(){

  int tc; cin >> tc;
  while(tc--){
    memset(graph,-1,sizeof(graph));
    memset(memo,-1,sizeof(memo));
    int xsize, ysize;
    cin >> xsize >> ysize;
    cin >> points[0][0] >> points[0][1];
    cin >> n;
    for(int i = 1; i <= n; i++){
      int x,y;
      cin >> points[i][0] >> points[i][1];
    }
    n++;
    for(int i = 0; i < n; i++){
      for(int j = i+1; j < n; j++){
        int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
        graph[i][j] = graph[j][i] = dist;
      }
    }
    cout << "The shortest path has length " << tsp(0,1) << endl;
  }
  return 0;
}

/*
6
8
0 1 2
0 2 7
0 3 9
1 5 8
2 3 1
3 4 2
3 5 4
4 5 5
*/