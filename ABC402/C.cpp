#include <iostream>
#include<vector>
using namespace std;

int main(){
  int N,M;
  cin >> N >> M;
  vector<vector<int>> use(N + 1);  //料理とそれに使われる食材A
  vector<int> bad_use(M); //料理ごとの苦手な食材の個数
  
  for(int i = 0; i < M; i++){
    int K;
    cin >> K;
    for(int j = 0; j < K; j++){
      int A;
      cin >> A;
      use[A].push_back(i); //食材を保存する
      bad_use[i]++; //bad_use[i] = K;
    } 
  }
  
  vector<int> like(N); //克服する食材
  for(int i = 0; i < N; i++) cin >> like[i];
  
  int ans = 0;
  //処理・出力
  for(int i = 0; i < N; i++){ //一日ごとに食べられる食材が増える
    int now = like[i];
    for(int meal : use[now]){ //"今日食べられるようになった食材" を含む料理についてループ
      bad_use[meal]--;
      if(bad_use[meal] == 0) ans++; //苦手な食材がなくなったら答えを +1
    }
    cout << ans << endl;
  }
  
  return 0;
}

/*
問題リンク：https://atcoder.jp/contests/abc401/tasks/abc402_c
提出リンク：https://atcoder.jp/contests/abc402/submissions/65038367
問題概要 : 
- N種類の食材と、M個の料理がある。
- 各料理は複数の食材を用いており、すぬけ君は初め、すべての食材が苦手。
- 料理は、苦手な食材を1つでも含むと食べられない。
- すぬけ君は、N日間で1日1つずつ食材を克服していく。
- 各日ごとに、克服した食材により「新たに食べられるようになった料理」を数えて、その累積で出力する。


アルゴリズム・考え方：
- 毎回 苦手な食材 を含まない料理を数えると計算量が大きくなる。
- そのため料理ごとに今苦手な食材の数を保存し、さらに克服した食材を含む料理についてループを回せば計算量も抑えられる。
*/
