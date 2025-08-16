import java.util.*;

public class B419 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        // 文字の数
        int N = sc.nextInt();
        sc.nextLine();
        //配列を作成
        List<Integer> balls = new ArrayList<>();
        Integer[] query = new Integer[N];
        // for文で文字を保存
        for (int i = 0; i < N; i++) {
            query[i] = sc.nextInt();
            if (query[i].equals(1)) {
                Integer x = sc.nextInt();
                balls.add(x);
            } else {
                balls.sort(Comparator.naturalOrder());
                int min = balls.remove(0);
                System.out.println(min);
            }
        }
    }
}
