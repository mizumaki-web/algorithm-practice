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
