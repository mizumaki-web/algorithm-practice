//この回答は不正解だった。アルゴリズムの方向性は正しく、計算量の最適化が課題。
#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
  long long N;
  cin >> N;
  unordered_set<long long> ans;
  
  // 2^a * b^2 の形を持つものを全て列挙(重複はunordered_setにより除外)
  for(long long b = 1; b*b <= N; b++){
    long long B = b*b;
    long long C = 2*B;
    while(C <= N){
      ans.insert(C);
      C *= 2;
    }
  }
  
  cout << ans.size() << endl;
}

/*
問題リンク：
提出リンク：
結果：不正解(時間制限超過)

アルゴリズム・考え方：
*/
