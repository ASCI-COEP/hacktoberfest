import java.io.*;
import java.util.*;

public class Avl {
    static class Vertex{
        long val;
        Vertex left,right;
        int height,left_number,right_number,total;
        Vertex(long val){
            this.val=val;
            left=null;
            right=null;
            this.height=0;
            left_number = 0;
            right_number=0;
            total=1;
        }
    }

    public static void main(String args[])throws IOException{
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String first[]=br.readLine().split(" ");
        int n=Integer.parseInt(first[0]);
        int q=Integer.parseInt(first[1]);
        Vertex root=null;
        String second[]=br.readLine().split(" ");
        for(int i=0;i<n;i++){
            long x=Long.parseLong(second[i]);
            root=insert(root,x);
        }
        //preorder(root);
        //System.out.println();
        while(q-->0){
            String querie[]=br.readLine().split(" ");
            int type=Integer.parseInt(querie[0]);
            long val=Long.parseLong(querie[1]);
            if(type == 1){
                root=insert(root,val);
            }
            else if(type == 2){
                boolean status=find(root,val);
                if(status){
                    System.out.println(1);
                }
                else{
                    System.out.println(0);
                }
            }
            else if(type == 3){
                if(root.total < (int)val){
                    //System.out.println(-1);
                    continue;
                }
                long fnd = findKSmallest(root,(int)val);
                System.out.println(fnd);
                delete(root,fnd);
            }
            /*preorder(root);
            System.out.println();*/
        }
        //System.out.println(find(root,4));
        //root=delete(root,4);
        //System.out.println(find(root,4));
        //preorder(root);
    }

    public static long findKSmallest(Vertex root,int k){
        if(root == null){
            return Long.MIN_VALUE;
        }
        if(k == root.left_number + 1){
            return root.val;
        }
        else if(root.left_number >= k){
            return findKSmallest(root.left,k);
        }
        else{
            return findKSmallest(root.right,k-(root.left_number + 1));
        }
    }

    public static boolean find(Vertex root, long val){
        if(root == null){
            return false;
        }
        if(root.val == val){
            return true;
        }
        else if(val < root.val){
            return find(root.left, val);
        }
        else{
            return  find(root.right, val);
        }
    }

    public static void preorder(Vertex root){
        if(root == null){
            return;
        }
        System.out.println(root.val+" "+root.left_number + " "+root.right_number + " "+root.total);
        preorder(root.left);
        preorder(root.right);
    }

    public static Vertex delete(Vertex root,long val){
        if(root == null){
            return root;
        }
        if(val == root.val){
            if(root.left ==null && root.right == null){
                root=null;
                return root;
            }
            else if(root.left == null){
                Vertex dump=root;
                root=root.right;
                dump=null;
            }
            else if(root.right == null){
                Vertex dump=root;
                root=root.left;
                dump=null;
            }
            else{
                Vertex ios=findInorderSuccessor(root);
                root.val=ios.val;
                root.right=delete(root.right,root.val);
            }
        }
        else if(val < root.val){
            root.left=delete(root.left,val);
        }
        else{
            root.right=delete(root.right,val);
        }

        updateNumber(root);
        updateHeight(root);

        root=balanceForDelete(root);

        updateNumber(root);
        updateHeight(root);
        return root;
    }

    public static Vertex findInorderSuccessor(Vertex root){
        Vertex ios=root.right;
        while(ios.left != null){
            ios=ios.left;
        }
        return ios;
    }

    public static Vertex balanceForDelete(Vertex root){ // change it
        int left_height=-1,right_height=-1;
        if(root.left != null) {
            left_height = root.left.height;
        }
        if(root.right != null) {
            right_height = root.right.height;
        }

        if(left_height -right_height >= 2){
            int left_left_height=-1,left_right_height=-1;
            if(root.left.left != null){
                left_left_height = root.left.left.height;
            }
            if(root.left.right != null){
                left_right_height =root.left.right.height;
            }

            if(left_left_height >= left_right_height){
                return leftLeftCase(root);
            }
            else{
                return leftRightCase(root);
            }
        }
        else if(right_height-left_height >= 2){
            int right_left_height=-1, right_right_height=-1;

            if(root.right.left != null){
                right_left_height = root.right.left.height;
            }
            if(root.right.right != null){
                right_right_height =root.right.right.height;
            }

            if(right_right_height >= right_left_height){
                return rightRightCase(root);
            }
            else{
                return rightLeftCase(root);
            }
        }
        else{
            return root;
        }
    }
    public static Vertex insert(Vertex root,long val){
        if(root == null){
            Vertex ob=new Vertex(val);
            return ob;
        }
        if(val == root.val){
            return root;
        }
        else if(val < root.val){
            root.left=insert(root.left,val);
        }
        else{
            root.right=insert(root.right,val);
        }
        updateHeight(root);
        updateNumber(root);

        int left_height=-1,right_height=-1;
        if(root.left != null) {
            left_height = root.left.height;
        }
        if(root.right != null) {
            right_height = root.right.height;
        }
        root.height=Math.max(left_height,right_height) + 1;
        if(left_height -right_height >= 2){
            if(val < root.left.val){
                return leftLeftCase(root);
            }
            else{
                return leftRightCase(root);
            }
        }
        else if(right_height-left_height >= 2){
            if(val >root.right.val){
                return rightRightCase(root);
            }
            else{
                return rightLeftCase(root);
            }
        }
        else{
            return root;
        }
    }

    public static Vertex leftLeftCase(Vertex root){
        Vertex ver=rotateRight(root);
        updateHeight(ver);
        updateNumber(ver);
        return ver;
    }

    public static Vertex leftRightCase(Vertex root){
        root.left=rotateLeft(root.left);
        updateHeight(root.left);
        updateNumber(root.left);

        updateHeight(root);
        updateNumber(root);

        Vertex ver=rotateRight(root);

        updateHeight(ver);
        updateNumber(ver);

        return ver;
    }

    public static Vertex rightRightCase(Vertex root){
        Vertex ver=rotateLeft(root);
        updateHeight(ver);
        updateNumber(ver);
        return ver;
    }

    public static Vertex rightLeftCase(Vertex root){
        root.right=rotateRight(root.right);
        updateHeight(root.right);
        updateNumber(root.right);

        updateHeight(root);
        updateNumber(root);

        Vertex ver=rotateLeft(root);

        updateHeight(ver);
        updateNumber(ver);

        return ver;
    }

    public static Vertex rotateRight(Vertex root){
        Vertex left_child = root.left;
        root.left=left_child.right;
        left_child.right=root;
        updateHeight(root); // this must be done before upadating left_child height
        updateHeight(left_child);

        updateNumber(root);
        updateNumber(left_child);

        return left_child;
    }
    public static Vertex rotateLeft(Vertex root){
        Vertex right_child = root.right;
        root.right=right_child.left;
        right_child.left=root;
        updateHeight(root); // this must be done before upadating left_child height
        updateHeight(right_child);

        updateNumber(root);
        updateNumber(right_child);

        return right_child;
    }

    public static void updateHeight(Vertex root){
        int left_height=-1,right_height=-1;
        if(root.left != null) {
            left_height = root.left.height;
        }
        if(root.right != null) {
            right_height = root.right.height;
        }
        root.height=Math.max(left_height,right_height) + 1;
    }

    public static void updateNumber(Vertex root){
        int left_number=0 , right_number=0;
        if(root.left != null){
            left_number=root.left.total;
        }
        if(root.right != null){
            right_number = root.right.total;
        }
        root.left_number= left_number;
        root.right_number = right_number;
        root.total = left_number + right_number + 1;
    }
}

