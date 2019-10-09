
public class Main {

	public static void main(String[] args) {
    String wrd = "dabalearrozalazorraelabad";
		boolean res = isPalindrome("dabalearrozalazorraelabad");
		if (res)
			System.out.println("The word " + wrd  + " is palindrome");
		else
			System.out.println("The word is not palindrome");
	}

	public static boolean isPalindrome(String givenword){
		int wordlength = givenword.length() - 1; //Arrays starts at zero
		for (int i=0; i<=wordlength/2; i++)
			if(givenword.charAt(i) != givenword.charAt(wordlength-i))
				return false;
		return true;
	}
}