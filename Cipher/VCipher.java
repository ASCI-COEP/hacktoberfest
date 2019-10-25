
import java.io.*;
public class VCipher
{
    public static void main(String args[])throws IOException
    {
        BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter the word to be encrypted:");
        String s=buf.readLine().toUpperCase();
        System.out.println("Enter the keyword:");
        String key=buf.readLine().toUpperCase();
        int a[]=new int[key.length()];
        for(int i=0;i<key.length();i++)
        {
            a[i]=(int)key.charAt(i)-65;
        }
        String s1="";
        int c=0,t=0;
        
        for(int i=0;i<s.length();i++)
        {
            if(Character.isLetter(s.charAt(i)))
            {
                if(c==key.length())
                {
                    c=c-key.length();
                }
                t=(int)s.charAt(i)+a[c];
                if(t>90||t>122)
                {
                    t=t-26;
                }
                s1=s1+(char)t;
                c++;
            }
            else
            {
                s1=s1+s.charAt(i);
            }
            
        }
        
        System.out.println("Ciphertext:"+s1);
    }
}
        
        
    