/* this code takes a decimal number and the base to which user wants to convert given decimal number
   as input*/ 
/* this code also handels hexadecimal base*/ 
#include<stdio.h>
#include<string.h>
#define MAX 20
char dec_to_char(int rem){
	if(rem >= 0 && rem<=9)
		return rem + '0';
	else
		return rem - 10 + 'A';
	
}
char* changebase(int decimal, int base){
	int rem,quotient,i,j;
    	char str[MAX];
        static char rev[MAX];
 	char* ptr;
	ptr = rev; 
	quotient = decimal;
	rem =0;
	i = 0;
	while(quotient >= 1){
		rem = quotient % base;
		quotient = quotient / base;
		str[i] =dec_to_char(rem);
		
		i++;
	}
	
	str[i] = '\n';

	i--;
	j=0;
	
	while(i>=0){
		rev[j] = str[i];
		j++;
		i--;
	}
	rev[j] = '\n';
	
	
	return ptr;
}
int main(){
	int decimal,base;
	char *p;
	//take decimal number and the desired base as input
	scanf("%d%d",&decimal, &base);
	p = changebase(decimal, base);
	printf("%s",p);
	return 0;
}
