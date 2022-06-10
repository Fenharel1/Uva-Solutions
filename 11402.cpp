#include <bits/stdc++.h>
#define MAX 1024005
#define REP(n) for(int i = 0; i < n; i++)
using namespace std;

int n;
int input[MAX], tree[MAX*4], lazy[MAX*4];

void build(int node, int start, int end){
  if(start == end){
    tree[node] = input[end];
    return;
  }
  int mid = (start + end) / 2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void updateLazyChildren(int node, int start, int end, int op){
  if(op == 0) tree[node] = 0;
  if(op == 1) tree[node] = end - start + 1;
  if(op == 2) tree[node] = end - start + 1 - tree[node];
  if(start != end){
    if(op != 2){
      lazy[node * 2] = op;
      lazy[node * 2 + 1] = op;
    }else{
      if(lazy[node * 2] == 0) lazy[node * 2] = 1;
      else if(lazy[node * 2] == 1) lazy[node * 2] = 0;
      else if(lazy[node * 2] == 2) lazy[node * 2] = -1;
      else lazy[node * 2] = 2;
      
      if(lazy[node * 2 + 1] == 0) lazy[node * 2 + 1] = 1;
      else if(lazy[node * 2 + 1] == 1) lazy[node * 2 + 1] = 0;
      else if(lazy[node * 2 + 1] == 2) lazy[node * 2 + 1] = -1;
      else lazy[node * 2 + 1] = 2;
    }
  }
}

void updateRange(int node, int start, int end, int l, int r, int op){
  if(start > end) return;

  if(lazy[node] != -1){
    updateLazyChildren(node, start, end, lazy[node]);
    lazy[node] = -1;
  }

  if(l > end || r < start) return;

  if(l <= start && r >= end){
    updateLazyChildren(node, start, end, op);
    return;
  }

  int mid = (start + end) / 2;
  updateRange(node * 2, start, mid, l, r, op);
  updateRange(node * 2 + 1, mid + 1, end, l, r, op);
  tree[node] = tree[node*2] + tree[node*2+1];
}

int queryRange(int node, int start, int end, int l, int r){
  if(start > end) return 0;
  if(lazy[node] != -1){
    updateLazyChildren(node, start, end, lazy[node]);
    lazy[node] = -1;
  }

  if(l > end || r < start) return 0;

  if(l <= start && r >= end){
    return tree[node];
  }
  
  int mid = (start + end) / 2;
  int op1 = queryRange(node * 2, start, mid, l, r);
  int op2 = queryRange(node * 2 + 1, mid + 1, end, l, r);
  return op1 + op2;

}

int main(){
  int t, k = 1;
  cin >> t;
  while(t--){
    memset(lazy, -1, sizeof(lazy));
    memset(tree, 0, sizeof(tree));
    int m, index = 0;
    cin >> m;
    string str, endless = "";
    
    int tam = 0;
    for(int T,i = 0; i < m; i++){
      cin >> T;
      cin >> str;
      int len = str.size();
      tam += T*len;
      for(int r = 0; r < T; r++){
        for(int b = 0; b < len; b++){
          input[index++] = str[b]=='0'?0:1;
        }
      }
    }

    build(1, 0, tam-1);
    
    int q, qq = 1;
    char opcion;
    int a, b;
    cin >> q;
    cout << "Case " << k << ":\n";
    for(int i = 0; i < q; i++){
      cin >> opcion >> a >> b;
      if(opcion == 'S'){
        cout << "Q" << qq << ": " << queryRange(1, 0, tam-1, a, b) << endl;
        qq++;
      }
      else if(opcion == 'F') updateRange(1, 0, tam-1, a, b, 1);
      else if(opcion == 'E') updateRange(1, 0, tam-1, a, b, 0);
      else if(opcion == 'I') updateRange(1, 0, tam-1, a, b, 2);
    }
    k++;
  }
  return 0;
}