import java.io.*;
public class Duplicate
{
    public static void main(String args[])throws IOException
    {
        BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the size of the array");
        int n=Integer.parseInt(buf.readLine());
        int a[]=new int[n];
        int a1[]=new int[n];
        System.out.println("Enter numbers in the array");
        for(int i=0;i<n;i++)
        {
            a[i]=Integer.parseInt(buf.readLine());
        }
        int c=0,c1=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<c1;j++)
            {
                if(a[i]==a1[j])
                {
                    c++;
                }
            }
            if(c==0)
            {
                a1[c1]=a[i];
                c1++;
            }
            c=0;
        }
        
        System.out.println("The array after removing multiple entries is:");
        for(int i=0;i<c1;i++)
        {
            System.out.println(a1[i]);
        }
    }
}
                
        
    