import java.util.Scanner;
public class FindAsciiVal {
    public static void main(String[] agrs){
        Scanner input = new Scanner(System.in);
        char character;
        
        System.out.println("Enter the character of which you want ASCII value: ");
        character = input.next().charAt(0);
        
        int ascii = (int) character; // casting char as int

        System.out.println("The ASCII value for " + character + " is " + ascii);
    }
}
