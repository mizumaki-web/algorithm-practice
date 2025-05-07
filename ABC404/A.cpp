#include <iostream>
#include <set>
using namespace std;

int main(){
  string S;
  cin >> S;
  set<char> A;
  for(int i = 0; i < S.size(); i++) A.insert(S.at(i));
  
  char c = 'a';
  while(1){
    if(!A.count(c)){
      cout << c << endl;
      return 0;
    }
    c++; //'a' -> 'b' と次の文字へ
  }

  return 0;
}

/*
問題リンク：https://atcoder.jp/contests/abc404/tasks/abc404_a
提出リンク：https://atcoder.jp/contests/abc404/submissions/65437757
問題概要：
英小文字からなる長さ 1 以上 25 以下の文字列 S が与えられます。
S に含まれない英小文字をひとつ出力してください。
但し、そのようなものが複数ある場合はどれを出力しても構いません。

実行例：
入力: abcdfhijklmnopqrstuvwxyz
出力：e (e,g が S に含まれない)

アルゴリズム・考え方：
- setを使うと以下の二つを実現できる
  かぶりを無視してコンテナに入れる。
  特定の文字があるかを判断する(set.count(c))。
- 文字を 'a' から確認していき、もしその文字を含んでいなかったら、その文字を出力して終了する
*/
