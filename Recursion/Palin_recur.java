import java.io.*;
public class Palin_recur
{
    int palin(int l,int r,String s)
    {
        if(l>r)
        {
            return 0;
        }
        if(l==r)
        {
            return 1;
        }
        else
        {
            if(s.charAt(l)==s.charAt(r)&&l+1==r)
            {
                return 1;
            }
            else if(s.charAt(l)==s.charAt(r))
            {
                return palin(l+1,r-1,s);
            }
            else
            {
                return 0;
            }
        }
    }
    
    public static void main(String args[])throws IOException
    {
        BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the word");
        String s=buf.readLine().toUpperCase();
        Palin_recur obj=new Palin_recur();
        int a=obj.palin(0,s.length()-1,s);
        if(a==1)
        {
            System.out.println("Palindrome");
        }
        else
        {
            System.out.println("Not Palindrome");
        }
    }
}
        
                
        
    