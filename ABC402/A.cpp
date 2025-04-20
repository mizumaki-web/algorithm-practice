#include <iostream>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  string ans;
  for(int i = 0; i < s.size(); i++){
    if('A'  <= s.at(i) && s.at(i)  <= 'Z' ) ans.push_back(s[i]);
  }
  
  cout << ans << endl;
  return 0;
}

/*
問題リンク：https://atcoder.jp/contests/abc402/tasks/abc402_a
提出リンク：https://atcoder.jp/contests/abc402/submissions/65009625
問題概要：英大文字と英小文字からなる文字列 S が与えられます。
S の英大文字のみを元の順序で連結して得られる文字列を出力してください。
実行例：
入力: AtCoderBeginnerContest → 出力: ACBC
入力: PaymentRequired → 出力: PR

アルゴリズム・考え方：
- 入力を"配列の大きさ回"ループを回す、もしくは for(char c : s)でのような範囲for文でループを回す。
- 'A' <= s.at[i] <= 'Z'を満たすものが大文字のアルファベットである(実際の表記はコードの通り)。
- もしくは標準ライブラリ関数 isupper(c) を用いると大文字であればtrueが返る。
参考: https://atcoder.jp/contests/abc402/editorial/12729
*/
