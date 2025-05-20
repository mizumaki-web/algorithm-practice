今回はアルゴリズムが分からなかったので解答例を掲載しています。
```
#include <bits/stdc++.h>
using namespace std;
#include "atcoder/dsu.hpp"

int main(){
  int N, M;
  cin >> N >> M;
  atcoder::dsu uf(N);
  int cycle_count = 0;
  
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
```

問題リンク：https://atcoder.jp/contests/abc406/tasks/abc406_c

## 問題文

整数列 A=(A 1 ,A 2 ,…,A∣A∣ ) に対し、A が チルダ型 とは以下の4 つの条件をすべて満たすことであると定義します。
- A の長さ ∣A∣ は 4 以上である 
- A1 < A2 ​である
- Ai−1 < Ai > Ai+1​  を満たす 2 ≤ i <∣A∣ なる整数 i はちょうど 1 個である　
- Ai−1 > Ai​ < Ai+1​  を満たす 2 ≤ i <∣A∣ なる整数 i はちょうど 1 個である　
数列 (1,2,…,N) を並べ替えて得られる数列 P = (P1 P2 ,…,PN ) が与えられます。

P の連続部分列であってチルダ型である数列の個数を求めてください。



## 制約
- 4 ≤ N ≤ 3×10^5
- P = (P1 P2 ,…,PN ) は (1,2,…,N) を並べ替えて得られる数列
- 入力される値はすべて整数

アルゴリズム・考え方：
- 

- 今回は次数 (頂点から伸びている辺)がすべて 2 && 連結 を満たすもの
正解例
#include <bits/stdc++.h>
using namespace std;
#include "atcoder/dsu.hpp"

int main(){
  int N, M;
  cin >> N >> M;
  atcoder::dsu uf(N);
  int cycle_count = 0;
    vector<int> deg(N);
  
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    deg[u]++;
    deg[v]++;
    if(uf.same(u, v)) cycle_count ++;
    else uf.merge(u, v);
  }
  
  bool cycle = ( cycle_count ==1 && deg == vector<int>(N,2));
  
  if(cycle) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}

- deg == vector<int>(N,2) によりすべての次数が 2 である を実現
参考：https://atcoder.jp/contests/abc404/submissions/65483271
 */
