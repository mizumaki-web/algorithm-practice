#include <iostream>
#include <cmath> 
using namespace std;

int main(){
  long long N, M;
  cin >> N >> M;
  long long sum = 0;
  
  for(int i = 0; i <= M; i++){
    long long a = pow(N,i); //pow関数はNのi乗を返す関数
    sum += a;
  }
  
  if(sum > 1000000000LL || sum < 0){ //オーバーフローを考慮し、負の値が出力されてもinfとする
    cout << "inf" << endl;
  } else {
    cout << sum << endl;
  }
  
  return 0;
}

/*
問題：https://atcoder.jp/contests/abc400/tasks/abc400_b
提出；https://atcoder.jp/contests/abc400/submissions/64523965
入力N・Mから、Nの0乗からM乗までの和を求める問題。
出力は10^9以下ならば和を、それより大きかったらinfを出力する。

10^9と大きな数が与えられるので、int型ではなくlong long型を用いる。

累乗はpow関数、もしくは
long long x;
for(int i = 0; i <= M; i++){
  ans += x;
  x *= N;
  }
このようにすればpow関数を使わずに書くことができる(参考；https://atcoder.jp/contests/abc400/submissions/64567417)。

出力をそのままするとlong long型でもオーバーフローしてしまう恐れがあるので、負の値が出力されてもinfと出力するようにした。
*/
