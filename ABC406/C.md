今回はアルゴリズムが分からなかったので解答例を掲載しています。
```
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i = 0; i < n; i++) cin >> p[i];

  vector<int> d;
  for(int i = 0; i < n-1; i++) d.push_back((p[i] < p[i+1]) ? 0 : 1);

  using P = pair<int,int>;
  vector<P> rle; //first:variety,second:quantity
  for (int x : d) {
    if (rle.size() && rle.back().first == x) rle.back().second++; //rleが空でない かつ 最後の要素が今の要素と同じｘであったら、今の個数を+1
    else rle.emplace_back(x,1); //新しく (x, 1) を作って末尾に追加
  }

  long long ans = 0;
  for(int i = 0; i < rle.size(); i++) {
    if (rle[i].first == 1) {
      long long l = 0, r = 0;
      if (0 < i) l = rle[i-1].second; //(i != 0) -> l に前の添え字の second を代入
      if (i+1 < rle.size()) r = rle[i+1].second; //(i != rle.size()) -> r に次の数字の second を代入
      ans += l*r; 
    }
  }
  cout << ans << endl;
  return 0;
}
```

問題リンク：https://atcoder.jp/contests/abc406/tasks/abc406_c

## 問題文

整数列 A=(A1 ,A2 ,…,A∣A∣ ) に対し、A が チルダ型 とは以下の4 つの条件をすべて満たすことであると定義します。
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

## アルゴリズム・考え方：
- 横軸 i, 縦軸 数 とすると N の形になるものが条件を満たす
  N の左右を伸ばす, また別の N 字を探すことでチルダ型配列の個数を探す
- RLE(増加を 0, 減少を 1 などで表記)で効率化
- pair(0 or 1, first の個数) で管理
- (first == 1(減少ペア)) の時、(前の増加数) * (後ろの増加数) を ans に増加させる

参考: https://atcoder.jp/contests/abc406/submissions/65931762
