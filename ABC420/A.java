import java.util.*;

public class A {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int X = sc.nextInt();
        int Y = sc.nextInt();
        int ans = (X + Y) % 12;
        if(ans==0) System.out.println("12");
        else System.out.println(ans);
    }
}