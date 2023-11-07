// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {

    public static boolean checkInclusion(String s1, String s2) {

        int[] charCounts = new int[26];
        for(int i=0; i<s1.length(); ++i){
            ++charCounts[s1.charAt(i)-'a'];
        }

        int i=0, j=0;
        for( ; j<s2.length(); ){
            --charCounts[s2.charAt(j)-'a'];
            if(charCounts[s2.charAt(j)-'a']>=0){
                if(j-i+1==s1.length()) return true;
                ++j;
            }else{
                // move i right until it is legal
                while(charCounts[s2.charAt(j)-'a']<0){
                    ++charCounts[s2.charAt(i)-'a'];
                    ++i;
                }
                if(i>j) j=i;
                else ++j;
            }
        }
        return false;

    }


    public static void main(String[] args) {

        String s1 = "adc", s2 = "dcda";
        System.out.println(checkInclusion(s1, s2));

    }
}