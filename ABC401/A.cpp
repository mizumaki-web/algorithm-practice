#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    if(N >= 200 && 299 >= N) cout << "Success" << endl;
    else cout << "Failure" << endl;
    
    return 0;
}

/*
問題リンク：https://atcoder.jp/contests/abc400/tasks/abc401_a
提出リンク：https://atcoder.jp/contests/abc401/submissions/64735291
問題概要：正の整数 N (100 <= N <= 999) が与えられる。
N が 200 以上 299 以下のとき Success 、そうでないとき Failure と出力する。
実行例：入力 200 出力 Success 、 入力 401 出力 Failure

アルゴリズム・考え方：
- N が 200 以上かつ N が 299 以下というのは条件式で &&(かつ) を使うことであらわされる。
- 別解として N を string 型で受け取り、 (N[0] == '2')(N の最初の文字が 2) と書くことでも今回は正解になる。
*/
