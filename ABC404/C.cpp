//今回は誤答を掲載しています
#include <bits/stdc++.h>
using namespace std;
#include "atcoder/dsu.hpp"

int main(){
  int N, M;
  cin >> N >> M;
  atcoder::dsu uf(N);
  int cycle_count =0;
  
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
     if(uf.same(u, v)) cycle_count ++;
     else uf.merge(u, v);
  }
  
  bool cycle = (M == N && cycle_count ==1);
  
  if(cycle) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}

/*
問題リンク：https://atcoder.jp/contests/abc404/tasks/abc404_c
提出リンク：https://atcoder.jp/contests/abc404/submissions/65474869

問題概要: サイクルグラフ判定
N 頂点 M 辺の無向グラフが与えられる。
このグラフが「サイクルグラフ」であるかどうかを判定する。

サイクルグラフとは、頂点の並べ替え (v1, v2, ..., vN) が存在して、
以下の条件をすべて満たすもの：
1. vi と vi+1（1 ≤ i < N）を結ぶ辺が存在する
2. vN と v1 を結ぶ辺が存在する
3. それ以外の辺は存在しない（＝各頂点の次数がちょうど 2）

制約:
- 3 ≤ N ≤ 2×10^5
- 0 ≤ M ≤ 2×10^5
- グラフは単純無向グラフ（自己ループ・多重辺なし）

アルゴリズム・考え方：
- ABC395 の C 問題がグラフ問題だったのでそこから思い出しながら解きました
- "atcoder/dsu.hpp"を使用。
(辺の数) == (頂点の数) && 連結　ならサイクルグラフだと思っていましたが、
4 4
1 2
2 3
3 1
1 4
この時サイクルグラフにならないので誤り。


 */
