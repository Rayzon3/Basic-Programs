public class countConstruct {

    public static int countConstructString(String target, String[] wordBank){
        if(target == "") return 1;

        int total = 0;
        for(String word : wordBank){
            if(target.indexOf(word) == 0){
                String suffix = target.substring(word.length());
                int numWays = countConstructString(suffix, wordBank);
                total += numWays;
            }
        }

        return total;
    }

    public static void main(String[] args) {
        String[] wordBank = {"purp", "p", "ur", "le", "purpl"};
        System.out.println(countConstructString("purple", wordBank));
    }
}
