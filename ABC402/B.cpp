#include <iostream>
#include <queue>
using namespace std;

int main(){
  int Q;
  cin >> Q;
  queue<int> answer;
  
  for(int i = 0; i < Q; i++){
    int a;
    cin >> a;
    //クエリ1　メニュー番号 b を持った客が並ぶ
    if(a == 1){ 
      int b;
      cin >> b;
      answer.push(b);
    }
    //クエリ2 先頭の客を処理してメニュー番号を出力
    if(a == 2){
      cout << answer.front() << endl;;
      answer.pop();
    }
  }
  
  return 0;
}


/*
問題リンク：https://atcoder.jp/contests/abc402/tasks/abc402_b
提出リンク：https://atcoder.jp/contests/abc402/submissions/65014637

問題概要 : クエリの回数 Q と、クエリの処理を Q 回与えられます。
クエリは2種類あります。
1 X: メニュー番号 X の食券を持った客が行列の末尾に並ぶ。
2: 行列の先頭にいる人を案内し、メニュー番号を出力する。

実行例
入力:
6
1 3
1 1
1 15
2
1 3
2
出力: 3 1

アルゴリズム・考え方：
- データ構造の queue<int> を使用して待ち行列を実装する。
- 都度クエリの種類を認識し、クエリに合わせた処理を実装する。
- クエリ１では末尾に数字を追加する push() のみ行う。
- クエリ２では front()で先頭を出力した後 pop() で先頭を削除する。
*/
