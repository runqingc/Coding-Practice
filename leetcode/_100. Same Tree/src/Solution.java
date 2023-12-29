

public class Solution {

    public boolean result = true;


    public void inOrder(TreeNode p, TreeNode q){

        if(result){
            if((p==null && q!=null) || (p!=null && q==null)){
                result = false;
            }else if(p!=null && q!=null){
                // both p and q are not null
                if(p.val!= q.val){
                    result = false;
                }else{
                    inOrder(p.left, q.left);
                    inOrder(p.right, q.right);
                }
            }
        }
    }


    public boolean isSameTree(TreeNode p, TreeNode q) {
        inOrder(p, q);
        return result;
    }
}
