public class enhancedForLoop {

    public static void main(String agrs[]){
        int asuna[] = {3, 4, 6, 7, 9};
        change(asuna);

        //Enhance For Loop
        for(int y : asuna){
            System.out.println(y);
        }

    }

    public static void change(int x[]){
        for(int i = 0; i < x.length; i++){
            x[i] += 2;
        }
    }
    
}