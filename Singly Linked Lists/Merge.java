
import javax.sound.sampled.SourceDataLine;


class ListNode {
    int val;
    ListNode next;
    ListNode(){}
    ListNode(int x) { val = x; }
}
public class Merge {
    public static ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode nueva = new ListNode(0);
        ListNode aux = nueva;

        while(l1!=null && l2!=null){
            if(l1.val <= l2.val){
                aux.next= new ListNode(l1.val);
                l1=l1.next;
            }
            else{
                aux.next=new ListNode(l2.val);
                l2=l2.next;
            }
            aux=aux.next;
        }
        if(l1==null) aux.next = l2;
        if(l2==null) aux.next = l1;

        return nueva.next;
    }

    public static void print(ListNode l){
        while(l!=null){
            System.out.print(l.val);
            l=l.next;
        }
        System.out.println("");
    }
    public static void main(String[] args){
        ListNode l1 = new ListNode(1);
        ListNode l2 = new ListNode(1);

        l1.next = new ListNode(2);
        l1.next.next = new ListNode(4);

        l2.next = new ListNode(3);
        l2.next.next = new ListNode(4);

        print(l1);
        print(l2);

        print(mergeTwoLists(l1,l2));

    }
}
