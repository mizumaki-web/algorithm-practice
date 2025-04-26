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
    for(int i = 0; i < N; i++) count[P[i]]++; //出現回数を追加
    
    vector<int> rank(N); //順位(回答)の配列
    int r = 1;
    for(auto [score,key]: count){ //map count の高得点順に，score は点, key は　人数
      for(int i = 0; i < N; i++) { //最高点を持っている人を全員から探す
          if(P[i] == score) rank[i] = r;
          r += key;
      }
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
- 添え字順に順位を出力するが、点数の高い人を並べる必要もある。
- map　の　greater を用いることで降順に並べることができる

別解:
今回は計算量 O(N^2) を行っても実行時間には間に合うので二流ループを回してよい。
for (int i = 0; i < n; i++) {
    int rank = 1;
    for (int j = 0; j < n; j++) {
        if (p[j] > p[i]) rank++;
    }
    cout << rank << endl;
}
このように (自分より高い点数の人数) + 1 とすれば実装できる。

参照 https://atcoder.jp/contests/abc399/editorial/12563
*/
