import java.util.Random;

class dice{
    public static void main(String args[]){

        Random dice = new Random();
        int num;

  
            num = 1 + dice.nextInt(6);
            System.out.println(num + " ");
        

    }
}