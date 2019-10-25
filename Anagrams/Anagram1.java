import java.io.*;
public class Anagram1
{
    public static void main(String args[])throws IOException
    {
        BufferedReader buf=new BufferedReader(new InputStreamReader(System.in));
        System.out.print("Enter the first word:");
        String s1=buf.readLine();
        System.out.print("Enter the second word:");
        String s2=buf.readLine();
        if(s1.length()==s2.length())
        {
            s1=s1.toUpperCase();
            s2=s2.toUpperCase();
            String s3="",s4="";
            for(int i=65;i<=90;i++)
            {
                for(int j=0;j<s1.length();j++)
                {
                    if(s1.charAt(j)==(char)i)
                    {
                        s3=s3+(char)i;
                    }
                    if(s2.charAt(j)==(char)i)
                    {
                        s4=s4+(char)i;
                    }
                }
            }
            if(s3.equals(s4))
            {
                System.out.println("Anagram words");
            }
            else
            {
                System.out.println("Not anagram words");
            }
        }
        else
        {
            System.out.println("Not anagram words");
        }
    }
}
            