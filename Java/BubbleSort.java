public class BubbleSort{
    public static void main(String args[]){

        int a[] = {4,5,3,8,1,2};
        int temp;

        for(int i = 0; i < a.length - 1 ; i++){

            boolean sorted = true;
            
            for(int j = 0; j < a.length - 1; j++){
                if(a[j] > a[j + 1]){
                    temp = a[j + 1];
                    a[j + 1] = a[j];
                    a[j] = temp;

                    sorted = false;

                }
            }
        
            if(sorted)
                break;
        }
    
    
        for(int i : a){
            System.out.print(i + " ");
        }
    
    
    }

}