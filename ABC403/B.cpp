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
問題リンク：https://atcoder.jp/contests/abc403/tasks/abc403_b
提出リンク：https://atcoder.jp/contests/abc403/submissions/65264165

問題概要 : 
英小文字と ? からなる文字列 T と、英小文字のみからなる文字列 U が与えられます。
T は、英小文字のみからなる文字列S のちょうど4 文字を ? で置き換えることで得られた文字列です
S が U を連続部分文字列として含んでいた可能性があるかどうか判定してください。。

実行例
入力:
tak??a?h?
nashi
出力: Yes
例えば、S が takanashi である場合、これは nashi を連続部分文字列として含みます。

入力：
h??h??o
hina
出力：No
? がどのような文字であっても、S は hina を連続部分文字列として含むことがありません。

アルゴリズム・考え方：
- まず ? の存在や字数は無視して考えます。 
abcdef に def が含まれるかを調べる場合 abc と def を比較します。
次に bcd, cde, def と def を比較します。
つまり文字列を比較するには T をスライドしていきます。 その回数は (T の長さ) - (U の長さ) +1 回になりそうです。先ほどは 6(abcdef) - 3(def) +1 = 4 回でした。
また、文字列は一度に比較するのではなく、1 文字目が一致していたら2文字目、それも一致していたら３文字目...としていき、 (U の長さ) 回一致していたらよさそうです。
- 次に ? ですが、これはすべての文字になれる文字なので、T に ? があったら一致とします。
 */
