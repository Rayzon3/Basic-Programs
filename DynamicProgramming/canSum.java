import java.util.HashMap;

public class canSum {
    //targetSum is the key
    static HashMap<Integer, Boolean> memo = new HashMap<>();
    static boolean isPossible(int targetSum, int[] numbers){
        if(memo.get(targetSum) != null){
            return memo.get(targetSum);
        }
        if(targetSum == 0) return true;
        if(targetSum < 0) return false;
        for(int i = 0; i < numbers.length; i++){
            int difference = targetSum - numbers[i];
            if(isPossible(difference, numbers) == true){
                memo.put(targetSum, true);
                return true;
            }
        }
        memo.put(targetSum, false);
        return false;
    }

    public static void main(String[] args) {
        int[] numbers = {7, 14};
        System.out.println(isPossible(300, numbers));
    }
}
