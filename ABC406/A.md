```
#include <iostream>
using namespace std;

int main(){
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  if(A > C) cout << "Yes" << endl;
  else if(C > A) cout << "No" << endl;
  else {
    if(B > D) cout << "Yes";
    else cout << "No" << endl;
  }

  return 0;
}
```

問題リンク：https://atcoder.jp/contests/abc406/tasks/abc406_a

提出リンク：https://atcoder.jp/contests/abc406/submissions/65861761

問題概要：
高橋君は 2025 年 5 月 17 日 A 時 B 分締切のレポートを、 2025 年 5 月 17 日 C 時 D 分に提出しました。
ここで、「A 時 B 分」と「C 時 D 分」は異なる時刻であることが保証されます。
高橋君が締切前にレポートを提出しているならば Yes を、そうでないならば No を出力してください。

実行例：

入力: 22 40 22 30

出力：Yes

レポートの締切は 
22 時 40 分であり、高橋君は 22 時 30 分に提出しているため、締切前にレポートを提出しています。
よって、Yes を出力します。

## アルゴリズム・考え方：
- A と C, B と D を比較することで判定を行う

## pair による比較
pair<int, int>を比較する場合、1番目の値を基準に比較され、もし1番目の値が等しい場合は2番目の値を基準に比較されます。
```
#include <iostream>
using namespace std;
#define rep(i,n) for(int i =0; i< (n); ++i)

int main(){
  int A,B,C,D;
  cin >> A >> B >> C >> D;
  pair<int,int> p(A,B), q(C,D);
  
  if(p > q) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
```
参考：https://atcoder.jp/contests/abc406/submissions/65930354
