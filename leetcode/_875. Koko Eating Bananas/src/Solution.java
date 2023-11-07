import java.util.Arrays;

class Solution {
    public int minEatingSpeed(int[] piles, int h) {

        long i=1, j= Arrays.stream(piles).max().getAsInt(), mid;
        long res = j;

        while(i<=j){
            mid = (i+j)/2;
            // calculate the time I need to eat up all the bananas at speed mid
            int this_time = 0;
            for (int pile : piles) {
                this_time += (int) Math.ceil((double) pile / mid);
            }
            if(this_time>=0 && this_time<=h){
                res = Math.min(res, mid);
                j = mid-1;
            }else {
                i = mid+1;
            }
        }

        return (int)res;
    }
}
