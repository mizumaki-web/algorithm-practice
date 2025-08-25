import java.util.*;

public class B {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Integer people = sc.nextInt();
        Integer round = sc.nextInt();
        String[] votes = new String[people];
        //確認の投票を記録
        for(int i = 0; i < people; i++) {
            votes[i] = sc.next();
        }
        int[] score = new int[people];

        for(int r = 0; r < round; r++){
            int zeros = 0, ones = 0;
            //このラウンドの0,1の人数数え上げ
            for(int j = 0; j < people; j++){
                if(votes[j].charAt(r) == '0') zeros++;
                else ones++;
            }

            if(ones == 0|| zeros == 0) {
                for(int j = 0; j < people; j++) {
                    score[j]++;
                }
            } else if (ones > zeros) {
                for(int j = 0; j < people; j++) {
                    if(votes[j].charAt(r) == '0') score[j]++;
                }
            } else {
                for(int j = 0; j < people; j++) {
                    if(votes[j].charAt(r) == '1') score[j]++;
                }
            }
        }
        //最大をほぞん
        int max = -1;
        for(int j = 0; j < people; j++){
            if(score[j] > max) {
                max = score[j];
            }
        }
        //最大を出力
        for(int j = 1; j <= people; j++){
            if(score[j-1] == max) System.out.print(j + " ");
        }
    }
}