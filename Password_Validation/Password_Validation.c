/*
Name :- Ashutoshsingh Jitendrasingh Pardeshi
FY Computer Engineering 
MIS No. :- 111903141 
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main ()
{
char username[50]; //Generating the username array
char password[16]; //Generating the password array

printf("Enter the Username :- ");
scanf(" %s", &username); //Stores the Username

printf("Now for creating a password, you must follow the following criteria :- \n"
		"\t1.It must contain an Upper-case alphabet. \n"
		"\t2.It must contain a Lower-case alphabet. \n"
		"\t3.It must contain a numberin it. \n"
		"\t4.The length must be between 8 to 15 characters ony.\n"
		"\t5.It must contain a symbol or a character among the following only :- \n"
		"\t\t1.@\t2.$\t3.&\n");
printf("Create a password :- ");
scanf(" %s", &password); //Stores the temporary value of the password

int i, num_Ualpha,num_Lalpha, num_Num, num_char, num_Total;
num_Ualpha=num_Lalpha=num_Num=num_char=num_Total = 0; //Initializing the values of all counting variables as 0
for(i=0;i<=15;i++)
{
	if(isalpha(password[i])) //Checking for alphabet input
	{
		if(isupper(password[i])) //Checking for Upper-case word input
		{ num_Ualpha += 1; }

		else if(islower(password[i])) //Checking for Lower-case letter input
		{ num_Lalpha += 1; }
	}

	if(isdigit(password[i])) //Checking for number input
	{ num_Num += 1 ; }

	if(password[i] == '@' || password[i] == '$' || password[i] == '&') //Checking for the special character input
	{ num_char += 1; }
}
num_Total = num_Ualpha + num_char + num_Num + num_Lalpha ;

if(num_Total>=8 && num_Total<=15) //Checking length condition
{
	if(num_Ualpha!=0 && num_Lalpha!=0 && num_Num!=0 && num_char!=0) //Checking whether all the conditions are satisfied
	{
		printf("Your Username %s and Password have been successfully created. Congratulations !!\n", username);
	}
}
else
{
	printf("You did not fulfill one of the criteria for creating the new password. Please try later sometime. Thank you.\n");
}
return 0 ;
}