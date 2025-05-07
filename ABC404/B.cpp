#include <iostream>
using namespace std;

int main(){
  string T, U;
  cin >> T >> U;
  
  bool ans = false;
  for(int i = 0; i < (int)T.size() - (int)U.size() + 1; i++){
    int count = 0;
    for(int j = 0; j < (int)U.size(); j++){
      if(T.at(i + j) != U.at(j) && T.at(i + j) != '?') break; 
      count ++;
      if(count == U.size()) ans = true;
    }
  }
  
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

/*
問題リンク：https://atcoder.jp/contests/abc404/tasks/abc404_b
提出リンク：https://atcoder.jp/contests/abc404/submissions/65466827

問題概要: グリッドの一致操作最小化
- 縦横 N×N の 2 つのグリッド S, T が与えられる。
- 各マスは '.'（白）または '#'（黒）で塗られている。
次の 2 種類の操作を好きな順序で好きな回数行うとき、グリッド S をグリッド T と一致させるために必要な操作回数の最小値を求めてください。
- グリッド S のマスを1 つ選び、色を変更する
- グリッド S 全体を 90 度右に回転する

実行例
入力:
4
###.
..#.
..#.
..#.
...#
...#
###.
....

出力: 2
下図のようにして 2 回の操作で S を T と一致させることができます。
###.
..#.
..#.
..#.
↓
...#
...#
####
....
↓
...#
...#
###.
....




アルゴリズム・考え方：
- まず ? の存在や字数は無視して考えます。 
abcdef に def が含まれるかを調べる場合 abc と def を比較します。
次に bcd, cde, def と def を比較します。
つまり文字列を比較するには T をスライドしていきます。 その回数は (T の長さ) - (U の長さ) +1 回になりそうです。先ほどは 6(abcdef) - 3(def) +1 = 4 回でした。
また、文字列は一度に比較するのではなく、1 文字目が一致していたら2文字目、それも一致していたら３文字目...としていき、 (U の長さ) 回一致していたらよさそうです。
- 次に ? ですが、これはすべての文字になれる文字なので、T に ? があったら一致とします。
 */
