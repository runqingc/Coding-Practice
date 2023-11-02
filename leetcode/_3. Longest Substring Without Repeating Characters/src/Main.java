import java.util.HashMap;

import static java.lang.Math.max;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {



    public static int lengthOfLongestSubstring(String s) {
        int max_cnt = 0;
        HashMap<Character, Integer> dict = new HashMap<>();
        int i=0, j=0;

        while(i<s.length() && j<s.length()){
            // Use the computeIfPresent method to update the character count
            if(dict.containsKey(s.charAt(i))){
                dict.computeIfPresent(s.charAt(i), (key, val) -> val + 1);
                if(dict.get(s.charAt(i))>1){
                    // move j right until it is legal
                    while(j+1<=i && dict.get(s.charAt(i))>1){
                        dict.computeIfPresent(s.charAt(j), (key, val) -> val - 1);
                        ++j;
                    }
                }
            }else{
                // If the character is not present, put it in the map with a count of 1
                dict.putIfAbsent(s.charAt(i), 1);
            }
            max_cnt = Math.max(max_cnt, i-j+1);
            ++i;
        }

        return max_cnt;
    }


    public static void main(String[] args) {
        System.out.println(lengthOfLongestSubstring("pika pikachu"));
    }
}