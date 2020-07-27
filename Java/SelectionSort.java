public class SelectionSort {

    public static void main(String agrs[]){

        int a[] = {6,3,2,1,5,4};
        int n = a.length;
        int temp;


        for(int i = 0; i < n - 1; i++){
            int min = i;
            for(int j = i + 1; j < n; j++){
                if(a[j] < a[min]){
                    min = j;
                }
               
            }
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }

        for(int i : a){
            System.out.print(i + " ");
        }






    }
    
}