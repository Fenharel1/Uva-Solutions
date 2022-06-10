#include <bits/stdc++.h>
using namespace std;

bool find(vector<int> arr, int value){
  for(int i = 0; i < arr.size(); i++){
    if(arr.at(i) == value) return 1;
  }
  return 0;
}

int main(){
  vector<int> pjBase = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  for(int i = 1; i < 21; i++){
    if(!find(pjBase, pjBase[i]*2)) pjBase.push_back(pjBase[i]*2);
  }
  for(int i = 1; i < 21; i++){
    if(!find(pjBase, pjBase[i]*3)) pjBase.push_back(pjBase[i]*3);
  }
  pjBase.push_back(50);

  int score;
  while(cin >> score, score > 0){
    int perm = 0;
    set<vector<int>> comb;
    for(int i = 0; i < pjBase.size(); i++){
      for(int j = 0; j < pjBase.size(); j++){
        for(int q = 0; q < pjBase.size(); q++){
          if(pjBase[i] + pjBase[j] + pjBase[q] == score){
            perm++;
            vector<int> aux = {pjBase[i], pjBase[j], pjBase[q]};
            sort(aux.begin(), aux.end());
            comb.insert(aux);
          } 
        }
      }
    }
    if(perm == 0) printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score);
    else {
      printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", score, comb.size());
      printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, perm);
    }
    printf("**********************************************************************\n");
  }
  printf("END OF OUTPUT\n");
  return 0;
}