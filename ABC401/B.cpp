#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];
    
    bool login = false;
    int ans = 0; 
    
    for(int i = 0; i < N; i++){
      if(S[i] == "login") login = true;
      if(S[i] == "logout") login = false;
      if(S[i] == "private" && login == false) ans++;
    }
    
    cout << ans << endl;
    
    return 0;
}

/*
問題リンク：https://atcoder.jp/contests/abc400/tasks/abc401_2
提出リンク：https://atcoder.jp/contests/abc401/submissions/64746324
問題概要 : (複雑のため割愛、問題リンクから確認お願いします。)
アルゴリズム・考え方：
- login/logout の切り替えは bool型　を用いれば表される。
- (login == false) の時にprivateにアクセスするとエラーになるので、この時に答えを+1 する。
- publicの入力は今回関係がない。
*/
