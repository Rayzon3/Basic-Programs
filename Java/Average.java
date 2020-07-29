import java.util.Scanner;

public class Average {
    private static final int MAX = 100;
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int array[] = new int[MAX];
        int n; 
        double s = 0, avg;

        System.out.println("Enter the number of elements: ");
        n = input.nextInt();
        System.out.println("Enter the elements: ");
        for(int i = 0; i < n; i++){
            array[i] = input.nextInt();
        }
        for(int i = 0; i < n; i++){
            s = array[i] + s;
        }
        
        avg = s/n;
        System.out.println("The average of the numbers is " + avg);

    }
}
