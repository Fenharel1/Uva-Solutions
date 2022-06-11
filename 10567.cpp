#include <bits/stdc++.h>
using namespace std;

int n;
string input, query;
map<char,int> mpIn, mpQu, start;

void greedy(){
  int j = 0;
  int inicio = -1, fin = -1;
  for(int i = 0; i < input.size(); i++){
    if(input[i] == query[j]){
      if(j == query.size()) break;
      if(j == 0) inicio = i;
      if(j == query.size()-1) fin = i;
      j++;
    }
  }
  if(inicio != -1 && fin != -1){
    cout << "Matched " << inicio << " " << fin << endl;
  }else{
    cout << "Not matched" << endl;
  }
}

int main(){
  cin >> input >> n;
  for(int i = 0; i < input.size(); i++){
    mpIn[input[i]]++;
    if(start.count(input[i]) == 0) start[input[i]] = i;
  }
  while(n--){
    mpQu.clear();
    cin >> query;
    greedy();
  }
  return 0;
}

void sol(){
  for(int i = 0; i < query.size(); i++) mpQu[query[i]]++;
  int inicio, fin;
  char chIn, chFn;
  for(map<char,int>::iterator it = mpQu.begin(); it != mpQu.end(); it++){
    if(it == mpQu.begin()) chIn = it->first;
    chFn = it->first;
    if(mpIn[it->first] < it->second){
      //cout << mpIn[it->first] << " " << it->second << " " << it->first << endl;
      cout << "Not matched" << endl;
      return;
    }
  }
  cout << "Matched " << start[chIn] << " " << start[chFn] + mpQu[chFn] - 1 << endl;
  return;
}