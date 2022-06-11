#include <bits/stdc++.h>
using namespace std;
int n,m;
char op;
string rep;

int matrix[205][205];

string conv(int a){
  return a?"1":"0";
}

string solveB(int i, int j, int dim1, int dim2){
  if(dim1==0 || dim2 ==0) return "";
  //cout << i << " " << j << " " << dim1 << " " << dim2 << endl;
  // if(dim1 == 2 && dim2 == 1){
  //   if(matrix[i][j] != matrix[i+1][j]) return "D" + conv(matrix[i][j]) + conv(matrix[i+1][j]);
  //   else return conv(matrix[i][j]);
  // }
  // if(dim1 == 1 && dim2 == 2){
  //   if(matrix[i][j] != matrix[i][j+1]) return "D" + conv(matrix[i][j]) + conv(matrix[i][j+1]);
  //   else return conv(matrix[i][j]);
  // }
  if(dim1 == 1 && dim2 == 1) return conv(matrix[i][j]);
  
  string op1="",op2="",op3="",op4="";

  if(dim1>1 && dim2>1)
    op4 = solveB(i+(dim1+1)/2, j+(dim2+1)/2, dim1/2,     dim2/2);
  if(dim1>1)
    op3 = solveB(i+(dim1+1)/2, j,       dim1/2,     (dim2+1)/2);
  if(dim2>1)
    op2 = solveB(i,       j+(dim2+1)/2, (dim1+1)/2, dim2/2);
  op1 = solveB(i,       j,       (dim1+1)/2, (dim2+1)/2);

  vector<string> aux;

  if(op1!="") aux.push_back(op1);
  if(op2!="") aux.push_back(op2);
  if(op3!="") aux.push_back(op3);
  if(op4!="") aux.push_back(op4);

  for(int i = 1; i < aux.size(); i++){
    if(aux[i]!=aux[i-1]){
      string resul = "";
      for(int j = 0; j < aux.size(); j++) resul+=aux[j];
      return "D"+resul;
    }
  }
  return op1;
  // if(op4==op3 && op3==op2 && op2==op1) return op1;
  // else return "D"+op1+op2+op3+op4;
}

void solveD(int i, int j, int dim1, int dim2){
  //cout << i << " " << j << " " << dim1 << " " << dim2 << " " << rep << endl;
  if(rep[0]!='D'){
    for(int i_ = i; i_ < i+dim1; i_++){
      for(int j_ = j; j_ < j+dim2; j_++){
        matrix[i_][j_] = rep[0]=='0'?0:1;
      }
    }
    rep = rep.substr(1);
    return;
  }else if(rep[0] == 'D'){
    rep = rep.substr(1);
    solveD(i,       j,       (dim1+1)/2, (dim2+1)/2);
    if(dim2 == 1) return;
    solveD(i,       j+(dim2+1)/2, (dim1+1)/2, dim2/2);
    if(dim1 == 1) return;
    solveD(i+(dim1+1)/2, j,       dim1/2,     (dim2+1)/2);
    solveD(i+(dim1+1)/2, j+(dim2+1)/2, dim1/2,     dim2/2);
  }
}

int main(){
  while(cin >> op, op!='#'){
    memset(matrix, 0, sizeof(matrix));
    cin >> n >> m;
    //string aux;
    //rep = "";
    //while(cin >> aux){
    //  rep += aux;
    //}
    //cout << rep << endl;
    cin >> rep;
    //cout << rep.size() << " tamanio: " << endl;
    if(op == 'B'){
      for(int j=0,i = 0; i < rep.size(); i++){
        if(i%(m)==0 && i!=0) j++;
        matrix[j][i%m] = rep[i]=='0'?0:1;
      }
      printf("D%4d%4d\n",n,m);
      string answer = solveB(0,0,n,m);
      for(int i = 0; i < answer.size(); i++){
        if(i%50==0 && i!=0) cout << endl;
        cout << answer[i];
      }
    }else if(op=='D'){
      solveD(0,0,n,m);
      
      printf("B%4d%4d\n",n,m);
      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          cout << matrix[i][j];
      cout << endl;
    }
  }
  return 0;
}