#include <iostream>
using namespace std;

int main() {
    int N;
    string S,T;
    cin >> N >> S >> T;
    
    int count = 0;
    for(int i = 0; i < N; i++) if(S[i] != T[i]) count++;
    
    cout << count << endl;
    return 0;
}


/*
問題リンク；https://atcoder.jp/contests/abc399/tasks/abc399_a
提出リンク：https://atcoder.jp/contests/abc399/submissions/64282161

問題概要：整数 N と長さ N からなる文字列 S,Tが与えられる。
S の i 文字目と T の i 文字目が異なる個数を出力。

実行例：
入力 
6
abcarc
agcahc
出力　2 (2,5文字目が違う)

アルゴリズム:一字ずつ比較して、もし違ったら答えのカウントを+1する。
*/
