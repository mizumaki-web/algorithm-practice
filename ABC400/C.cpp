//この回答は不正解だった。アルゴリズムの方向性は正しく、計算量の最適化が課題。
#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
  long long N;
  cin >> N;
  unordered_set<long long> ans;
  
  // 2^a * b^2 の形を持つものを全て列挙(重複はunordered_setにより除外)
  for(long long b = 1; b*b <= N; b++){
    long long B = b*b;
    long long C = 2*B;
    while(C <= N){
      ans.insert(C);
      C *= 2;
    }
  }
  
  cout << ans.size() << endl;
}

/*
問題リンク：https://atcoder.jp/contests/abc400/tasks/abc400_c
提出リンク：https://atcoder.jp/contests/abc400/submissions/64554980
問題概要：正の整数 N (1 <= N <= 10^18) が与えられる。
N 以下の自然数のうち、2^a × b^2 の形で表せる数が何個あるかを求める。
実行例：入力 20 出力 5 (2 = 2^2 * 1^2, 4 = 2^2 * 1^2, 8 = 2^1 * 2^2, 16 = 2^2 * 2^2, 18 = 2^1 * 3^2 の5個)
結果：不正解(時間制限超過)

アルゴリズム・考え方：
- 2 × b^2 × 2^k = b^2 × 2^{k+1} の形で表せる自然数を全て列挙する
- b^2 を固定し、2倍・4倍・8倍…と繰り返して N 以下の値を全て求め、集合に追加する
- 重複が発生する可能性があるため、unordered_set を使って一意な値のみカウントした

問題点：入力 N ( <= 10^18 ) の制約では全列挙は計算量が多ぎる問題。

正解の考え方：
- a < 60, b^2 < 10^19 なのでaを全て試す方針。
  またbの条件は
  - 奇数であること(2^aを全列挙するため、重複しないようにするため)
  - b <= (N/a)^(1/2)
  
for(int a = 1; a < 60; a++){
  long long x = N;
  for(int i = 0; i < a; i++) x /= 2;
  long long m = sqrtl(x);　 //sqrtlは精度の高い平方根(参照 https://learn.microsoft.com/ja-jp/cpp/c-runtime-library/reference/sqrt-sqrtf-sqrtl?view=msvc-170 
  ans += (m+1)/2; //x以下の奇数の平方根の個数
}
たとえば x = 50, a = 1の時、x /= 2 より　ｘ = 25
m = sqrlt(x=25) = 5 つまり b^2 =25
このとき、bの奇数の数は 1,3,5 の3つ ((m=5 + 1)/2 = 3)
参考：https://atcoder.jp/contests/abc400/submissions/64568119

今回の学び：全列挙の前に計算量の見積もりを付ける
*/
