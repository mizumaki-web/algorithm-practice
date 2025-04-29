#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main(){
  int user, page, query;
  cin >> user >> page >> query;
  
  unordered_map<int,unordered_set<int>> map;
  unordered_map<int,bool> all; //すべての権限を持った人を管理
  for(int i = 0; i < query; i++){
    int Q;
    cin >> Q;
    if(Q == 1){
      int key, value;
      cin >> key >> value;
      map[key].insert(value); //set.insert(i) -> setに i を追加
    }
    if(Q == 2){
     int key;
     cin >> key;
     all[key] = true;
    }
    if(Q == 3){
      int key, value;
      cin >> key >> value;
      if((map.count(key) && map[key].count(value))  || all[key]) cout << "Yes" << endl; //map.count(i) -> map に i が存在するか? set.count(i) -> set に i が存在するか？
      else cout << "No"  << endl;
    }
  }
  return 0;
}

/*
問題リンク：https://atcoder.jp/contests/abc403/tasks/abc403_c
提出リンク：https://atcoder.jp/contests/abc403/submissions/65282852
問題概要 :
N 人のユーザーがおり、1 から N までの番号がつけられています。また、M 個のコンテストページがあり、1 から M までの番号がつけられています。 はじめ、すべてのユーザはどのコンテストページの閲覧権限も持っていません。
Q 個のクエリが与えられるので、順に処理してください。クエリは 3 種類あり、以下のいずれかの形式で与えられます。
1 X Y: 
ユーザ X にコンテストページ Y の閲覧権限を付与する。
2 X: 
ユーザ X にすべてのコンテストページの閲覧権限を付与する。
3 X Y: 
ユーザ X がコンテストページ Y を閲覧できるかを答える。

1 ≤ N ≤ 2 × 10^5
1 ≤ M ≤ 2 × 10^5 
1 ≤ Q ≤ 2 × 10^5

アルゴリズム・考え方：
- 飛び飛びの添え字ごとに値などを保存したい場合は map コンテナを使うと便利です。
ユーザーは int で保存し、見れるページは set コンテナで保存します(setはある値が存在するかの計算量が O(1) で便利)。
- クエリ 2 で ユーザ X にすべての権限を与えるとき、さきほどの map に保存してしまうと M * Q <= 4 × 10^10 となってしまいます。これでメモリオーバーになってしまいました。
なのでクエリ 2 は ユーザにすべての権限を持つフラグを与え、 bool で管理します。これでメモリの節約と高速化ができます。
 */
