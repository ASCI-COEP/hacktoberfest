// C Program to convert string into upper case without using inbuild functions

#include <stdio.h>

void stringUpr(char *s){
    int i=0;
    while(s[i]!='\0')
    {
        if(s[i]>='a' && s[i]<='z'){
            s[i]=s[i]-32;
        }
        ++i;
    }
}
 
int main()
{
    char str[100];
 
	printf("Enter any string : ");
    scanf("%[^\n]s",str);
    
    stringUpr(str);
    printf("String after stringUpr : %s\n",str);
    return 0;
}
 

