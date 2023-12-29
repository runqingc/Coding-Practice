import java.util.ArrayList;
import java.util.HashMap;


public class Solution {

    public Node copyRandomList(Node head) {


        HashMap<Node, Integer> originalMap = new HashMap<>();
        // traverse, construct map
        Node i = head;
        if(i==null){
            return null;
        }
        int cnt = 0;
        for( ; i!=null; i = i.next){

            originalMap.put(i, cnt++);
        }
        int[] randomPointer = new int[cnt];
        cnt = 0;
        for(i=head ; i!=null; i = i.next){
            if(i.random==null){
                randomPointer[cnt] = -1;
            }else{
                randomPointer[cnt] = originalMap.get(i.random);
            }
            ++cnt;
        }

        // copy the list first
        ArrayList<Node> original = new ArrayList<>();
        Node j;
        Node last = null;
        for(i=head ; i!=null; i = i.next){
            j = new Node(i.val);
            if(last!=null){
                last.next = j;
            }
            last = j;
            original.add(j);
        }

        // then copy random pointer
        cnt = 0;
        for(j=original.get(0); j!=null; j = j.next){

            if(randomPointer[cnt]!=-1){
                j.random = original.get(randomPointer[cnt]);
            }
            ++cnt;
        }


        return original.get(0);
    }

}

