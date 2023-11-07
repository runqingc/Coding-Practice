class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int m = matrix.length;
        int n = matrix[0].length;
        int i = 0, j = m*n-1;
        int mid, c, r;
        while(i<=j){
            mid = (i+j)/2;
            r = mid/n;
            c = mid%n;
            if(matrix[r][c]==target){
                return true;
            }else if(matrix[r][c]<target){
                i = mid+1;
            }else{
                j = mid-1;
            }
        }
        return false;
    }
}