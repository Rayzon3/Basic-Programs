import java.util.Scanner;

public class Factorial {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int n;
        System.out.println("Enter the number: ");
        n = input.nextInt();
        System.out.println(Fact(n));
    }

    public static int Fact(int n){
        if(n <= 1)
            return 1;
        else{
            return n * Fact(n - 1);
        }
    }
}
