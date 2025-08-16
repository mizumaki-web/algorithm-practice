import java.util.Scanner;

public class A419 {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String A = sc.next();

        if(A.equals("red")) System.out.println("SSS");
        else if(A.equals("blue")) System.out.println("FFF");
        else if(A.equals("green")) System.out.println("MMM");
        else System.out.println("Unknown");
    }
}
