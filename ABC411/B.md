```
import java.util.*;
public class B {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        // 駅の数
        int a = sc.nextInt();
        //配列を作成
        int[] scores = new int[a-1];
        // for文で駅を保存
        for(int i = 0; i < a-1; i++){
            scores[i] = sc.nextInt();
        }
        // 出力
        for(int i = 0; i < a-1; i++){
            int b = 0;
            for(int j = i; j < a-1; j++){
                b += scores[j];
                System.out.print(b);
                System.out.print(" ");
            }
            System.out.println(" ");
        }
    }
}
```
問題リンク：https://atcoder.jp/contests/abc411/tasks/abc411_b

提出リンク：https://atcoder.jp/contests/abc411/submissions/66972157

## 問題概要（要約）

N 個の駅が直線上に 1 から N の順に並んでいます。
各駅 i と 駅 (i+1) の間には距離 D\_i があり、全体で (N−1) 個の距離が与えられます。

このとき、1 ≤ i < j ≤ N を満たすすべての組 (i, j) に対して、駅 i と駅 j の間の合計距離を出力してください。

出力は N−1 行あり、i 行目 (1 ≤ i ≤ N−1) には、駅 i から駅 j (j > i) への距離が、空白区切りで (N−i) 個出力されます。

## 制約

* 2 ≤ N ≤ 50
* 1 ≤ D\_i ≤ 100
* 入力はすべて整数

## 入力形式

N
D₁ D₂ ... D\_{N−1}

## 出力形式

N−1 行出力せよ。
i 行目には、(N−i) 個の整数を空白区切りで出力する。
i 行目の j 番目の値は、駅 i から駅 (i+j) までの距離とする。

## 入力例

4
1 2 3

## 出力例

1 3 6
2 5
3

## 考え方・アルゴリズム

* 与えられた D をそのまま配列に格納
* 外側のループで始点 i を決めて、内側で i+1 〜 N までの合計距離を累積して出力
* 典型的な累積和（部分和）の構築パターン


