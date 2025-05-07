#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<vector<char>> S(N, vector<char>(N)); // 元のグリッド
  vector<vector<char>> T(N, vector<char>(N)); // 目標グリッド

  // 入力
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> S[i][j];
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) cin >> T[i][j];

  int min_cost = 10009; //最大は 100*100

  // 回転0回（そのまま比較）
  int cost_0rot = 0;
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
    if (S[i][j] != T[i][j]) cost_0rot++;
  min_cost = cost_0rot;

  // 回転1回（90度右）
  int cost_1rot = 1;
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
    if (S[N - 1 - j][i] != T[i][j]) cost_1rot++;
  min_cost = min(min_cost, cost_1rot);

  // 回転2回（180度）
  int cost_2rot = 2;
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
    if (S[N - 1 - i][N - 1 - j] != T[i][j]) cost_2rot;
  min_cost = min(min_cost, cost_2rot);

  // 回転3回（270度）
  int cost_3rot= 3;
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)
    if (S[j][N - 1 - i] != T[i][j]) cost_3rot++;
  min_cost = min(min_cost, cost_3rot);

  cout << min_cost << endl;
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
- 回転数（0~3）+ 書き換え回数(つまり不一致数) を足せばよさそうです
- そのうち(回転数0~3のうち)、最も合計値の少ないものが答え
grid の回転は今回毎回行いましたが、行っている操作は 90度回転 + 操作数を +1 することなので、関数として表せます。
例えば
 for(int i = ri; ri < 4; ri++) {
    // calc
    {
      int now = ri;
      for(int i; i < N; i++)for(int j; j < N; j++) {
        if (S[i][j] != T[i][j]) now++;
      }
      ans = min(ans, now);
    }
    // rotate
    {
      vector<vector<char>> NS = S;
      rep(int i = 0; i < N; i++)for(int j; j < N; j++) {
        NS[j][N-1-i] = S[i][j];
      }
      S = NS; //元のSを更新(回転)
    }
  }
 このようにすればすべての回転を1度に表されます(参考:https://atcoder.jp/contests/abc404/submissions/65482831)。
 */
