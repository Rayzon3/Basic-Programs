import java.util.HashMap;

public class canConstruct {

    static HashMap<String, Boolean> memo = new HashMap<>();
    public static Boolean canConstructString(String target, String[] wordBank){
        if(memo.get(target) != null) return memo.get(target);
        if(target == "") return true;
        for(String word : wordBank){
            if(target.indexOf(word) == 0){
                String suffix = target.substring(word.length());
                if(canConstructString(suffix, wordBank) == true) {
                    memo.put(target, true);
                    return true;
                }
            }
        }
        memo.put(target, false);
        return false;
    }

    public static void main(String[] args) {
        String[] wordBank = {"ab", "abc", "cd", "def", "abcd"};
        System.out.println(canConstructString("abcdef", wordBank));
    }
}
