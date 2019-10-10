
class ListNode {
     int val;
     ListNode next;
      ListNode(int x) { val = x;}
 }


class RemoveElements {
    public static ListNode removeElements(ListNode head, int val) {
        
        if(head==null){
            return head;
        }
        
       while(head!=null && head.val == val){
            head=head.next;
        }
        
        if(head!=null){
            ListNode aux = head;

            while(aux.next!=null){
                if(aux.next.val==val){
                    aux.next = aux.next.next;
                }
                else aux=aux.next;
            }
        }
        return head;
        
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
        l1.next=new ListNode(2);
        l1.next.next=new ListNode(2);
        l1.next.next.next=new ListNode(3);
        l1.next.next.next.next=new ListNode(4);
        l1.next.next.next.next.next=new ListNode(2);
        l1.next.next.next.next.next.next=new ListNode(1);

        print(l1);
        print(removeElements(l1, 2));
    }
}