#include <bits/stdc++.h>
using namespace std;

int main(){
  int tc;
  char aux[2];
  gets(aux);
  cin >> tc;
  while(tc--){
    char input[30][30];
    int n=0;
    for(int i=0; i < 25; i++){
      char aux[30];
      gets(aux);
      if(aux[0] == 'A') break;
      n++;
      strcpy(input[i],aux);
    }
    int m = strlen(&input[0][0]);
    cout << n << " aquiii " << m << endl;
    for(int i = 0; i < n; i++){
      printf("%s\n",input[i]);
    }
  }
  return 0;
}