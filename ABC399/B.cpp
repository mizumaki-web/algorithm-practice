#include <iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];
    
    map<int, int, greater<int>> count; //出現回数を保存するmap、降順（点数が高い順に並ぶ）
    for(int i = 0; i < N; i++) count[P[i]]++;
    
    vector<int> rank(N); 
    int r =1;
    for(auto [score,k]: count){
      for(int i = 0; i < N; i++) if(P[i] == score) rank[i] = r;
      r += k;
    }
    
    for(int i = 0; i < N; i++) cout << rank[i] << endl;
    return 0;
}


/*
問題リンク：https://atcoder.jp/contests/abc399/tasks/abc399_b
提出リンク：https://atcoder.jp/contests/abc399/submissions/64312225

問題概要 : N 人の人がコンテストに参加します。
N と i 番目の人の点数 Pi が与えられるので、N 行、i 番目の人の順位を出力してください。

実行例
入力:
4
3 12 9 9

出力: 
4
1
2
2

アルゴリズム・考え方：
- 問題の(問題文URL先参照)導入に合わせて実装している。
- 
*/
