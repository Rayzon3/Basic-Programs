public class InsertionSort {
    public static void main(String args[]){

        int a[] = {3,4,5,1,2,6};
        int n = a.length;
        int value, hole;

        for(int i = 1; i < n -1; i++){
            hole = i;
            value = a[i];
            while(hole > 0 && a[hole - 1] > value){
                a[hole] = a[hole -1];
                hole = hole - 1;
            }
            a[hole] = value;
        }

        for(int i : a){
            System.out.print(i + " ");
        }



    }
}