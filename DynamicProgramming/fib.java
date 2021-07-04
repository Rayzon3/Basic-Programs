import java.util.HashMap;

class fib{

    //naive approach
    public static int naiveFib(int n){
        if(n <= 2) return 1;
        int f = naiveFib(n - 1) + naiveFib(n - 2);
        return f;
    }

    
    // using memoization
    // using hashMaps keys -> arg to the function, value -> return value
    static HashMap<Integer, Integer> memo = new HashMap<Integer, Integer>();
    public static int dynamicFib(int n){
        if(memo.get(n) != null){
            return memo.get(n);
        }
        if(n <= 2) return 1;
        memo.put(n, dynamicFib(n - 1) + dynamicFib(n - 2));
        return memo.get(n);
    }

    public static void main(String[] args) {
        // long startTime = System.nanoTime();
        // System.out.println(naiveFib(6));
        // long stopTime = System.nanoTime();
        // System.out.println(stopTime - startTime);


        // long startTime = System.nanoTime();
        // System.out.println(naiveFib(35));
        // long stopTime = System.nanoTime();
        // System.out.println(stopTime - startTime);

        long startTime = System.nanoTime();
        System.out.println(dynamicFib(35));
        long stopTime = System.nanoTime();
        System.out.println(stopTime - startTime);
    }
}