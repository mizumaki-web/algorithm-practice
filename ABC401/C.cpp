#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long N,K;
    cin >> N >> K;
    vector<long long> A(N+1);
    long long sum = 0 ;

  
    if(N < K){
      cout << "1" << endl;
      return 0;
    }
    
     for(int i = 0; i < K; ++i) {
        A[i] = 1;
    }
    
    // 最初の K 個の合計を sum に蓄える
    for(int i = 0; i < K; i++){
        sum = (sum + A[i]);
    }

    // i = K から N までスライディングウィンドウ
    for(int i = K; i <= N; i++){
      A[i] = sum;
      sum = (sum + A[i] - A[i-K] + 1000000000) % 1000000000;
    }
    
    cout << A[N]%1000000000 << endl;
    return 0;
}

/*
問題リンク：https://atcoder.jp/contests/abc401/tasks/abc401_c
提出リンク：https://atcoder.jp/contests/abc401/submissions/64768254
問題概要 : 
長さ N+1 の数列 A を次のルールで定義する:
1) 0 ≤ i < K のとき A[i] = 1
2) i ≥ K のとき A[i] = A[i-K] + ... + A[i-1]
求めるのは A[N] を 10^9 で割った余り
アルゴリズム・考え方：
- 最初の K 個は 1 として初期化 (A[0]..A[K-1] = 1)
- 直近 K 項の合計を "sum" で管理 (スライディングウィンドウ)
- i = K..N について, A[i] = sum (過去 K個の合計)
- sum をアップデートする際は sum = sum + A[i] - A[i-K] (区間を1つスライド)
*/
