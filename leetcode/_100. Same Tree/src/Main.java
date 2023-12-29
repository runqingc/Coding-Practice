// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {
    public static void main(String[] args) {

        TreeNode t12 = new TreeNode(2);
        TreeNode t11 = new TreeNode(1, t12, null);
        TreeNode t22 = new TreeNode(2);
        TreeNode t21 = new TreeNode(1, null, t22);
        Solution solution = new Solution();
        System.out.println(solution.isSameTree(t11, t21));

    }
}