import java.util.ArrayList;
import java.util.List;

// Press Shift twice to open the Search Everywhere dialog and type `show whitespaces`,
// then press Enter. You can now see whitespace characters in your code.
public class Main {

    StringBuilder sb;
    List<String> ans;
    public void dfs(int l, int r){

        if(l>0){
            sb.append('(');
            --l;
            if(l==0 && r==0){
                ans.add(sb.toString());
                ++l;
                sb.deleteCharAt(sb.length() - 1);
                return;
            }else{
                dfs(l, r);
                ++l;
                sb.deleteCharAt(sb.length() - 1);
            }
        }
        if(r>0 && r>l){
            sb.append(')');
            --r;
            if(l==0 && r==0){
                ans.add(sb.toString());
                ++r;
                sb.deleteCharAt(sb.length() - 1);
                return;
            }else{
                dfs(l, r);
                ++r;
                sb.deleteCharAt(sb.length() - 1);
            }

        }

    }

    public List<String> generateParenthesis(int n) {
        sb = new StringBuilder();
        ans = new ArrayList<>();
        dfs(n, n);
        return ans;
    }



    public static void main(String[] args) {

        Main mainObj = new Main();

        List<String> result = mainObj.generateParenthesis(3);
        // Now you can use the result list as needed, for example print it
        System.out.println(result);

    }
}