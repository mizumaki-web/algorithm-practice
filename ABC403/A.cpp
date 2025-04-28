#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  
  int ans = 0;
  for(int i = 0; i < N; i++){
    cin >> A[i];
    if(i %2 == 0) ans += A[i];
  } 
  
  cout << ans << endl;
  return 0;
}

/*
問題リンク：https://atcoder.jp/contests/abc403/tasks/abc403_a
提出リンク：https://atcoder.jp/contests/abc403/submissions/65244053
問題概要：長さ N の正整数列が与えられるます。その奇数番目の数を足した総和を求めてください。
実行例：
入力: 
7
3 1 4 1 5 9 2
出力：14 (3 + 4 + 5 + 2)

アルゴリズム・考え方：
- 列の長さ N と 整数列の要素を N 回読み取り、i 回目が 偶数(添え字が 0 始まりなので) のとき 答えに加算します。
つまり A[0] (1番目), A[2], A[4], ... を答えに加算します。 
*/
