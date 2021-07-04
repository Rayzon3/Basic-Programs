import java.util.HashMap;

public class gridTraveler {

    static HashMap<String, Integer> memo = new HashMap<>();
    public static int grid(int m, int n){
        String key = m + "," + n;
        if(memo.get(key) != null){
            return memo.get(key);
        }
        if(m == 1 && n == 1) return 1;
        if(m == 0 || n == 0) return 0;
        memo.put(key, grid(m - 1, n) + grid(m, n - 1));
        return memo.get(key);
    }

    public static void main(String[] args) {
        System.out.println(grid(15, 15));
    }
}
