import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        //持ち物数と容量を入力
        int N = sc.nextInt();
        int M = sc.nextInt();
        //重さを入力して合計値を算出
        int sum = 0;
        for(int i = 0; i < N; i++) {
            sum += sc.nextInt();
        }
        //出力
        if(sum <= M) System.out.println("Yes");
        else System.out.println("No");
    }
}
