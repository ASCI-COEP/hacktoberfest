def palindrome(n):
    temp=n
    rev=0
    while(n!=0):
        rev=rev*10+n%10
        n//=10
    print("Palindrome Number") if rev==temp else print("Not a Palindrome Number")
    return 0


n=int(input('Enter the number to check whether it is palindromic or not: '))
palindrome(n)     
