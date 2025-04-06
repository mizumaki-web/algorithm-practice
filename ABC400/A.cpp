#include <iostream>
using namespace std;

int main(){
  int N;
  cin >> N;
  
  //Nが400の約数か判定
  if (400 % N != 0){
    cout << "-1" << endl;
  }else{
    cout << 400 / N << endl;
  }
  
  return 0;
}

/*
問題リンク；https://atcoder.jp/contests/abc400/tasks/abc400_a
提出リンク：https://atcoder.jp/contests/abc400/submissions/64517265

問題概要：入力した数字で、400を割り切るか判定する問題。
割り切れられるなら商、割り切れないなら-1を出力する。

実行例：入力 10 出力　40、入力 11 出力 -1
*/
