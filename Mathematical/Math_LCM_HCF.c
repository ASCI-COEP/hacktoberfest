Ashutoshsingh Jitendrasingh Pardeshi
FY COEP Computer Engineering
MIS No. :- 111903141

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

int main()
{
	int opt;
	printf("Select the Option for which you would like to run this program:\n");
	printf("\tOption 1 : Finding the Least Common Multiple.\n");
	printf("\tOption 2 : Finding the Highest Common Divisor.\n");
	printf("Your choice :- Option ");
	scanf(" %d", &opt); //Taking input from user

	if(opt!=1 && opt!=2) //Input validation
    {
		printf("You entered the wrong option. Please try later by re-running the program.\nThank you!\n");
		return 0;
	}

    int n1, n2 ; //Initializing the two numbers and taking input from the user
	printf("Enter the first number :- ");
	scanf(" %d", &n1);
	printf("Enter the second number :- ");
	scanf(" %d", &n2);

    int num_Num, num_test, i;

	if(opt == 1)
	{
		for(i=1;i<=1000;i++)
		{
			num_Num = 0 ;
			num_Num = n2*i ;
			num_test = num_Num%n1 ;
			if(num_test==0)
			{
				printf("The Least Common Multiple pf the numbers %d and %d is %d.", n1, n2, num_Num);
				break; //Once the LCM is found, the loop is broken so that the other higher multiples are not calculated.
			}
		}
	}
	else if(opt==2)
	{
	    int j;
		for (j=n1;j>=1;j--)
		{
			int div_1, div_2 = 0 ;
			div_1 = n1 % j ;
			div_2 = n2 % j ;
			if (div_1==0 && div_2==0)//Condition for the number 'j' to be the HCF
			{
				printf("The Highest Common Factor of the numbers %d and %d is %d.\n",n1, n2, j);
				break ;
			}
		}
	}
	return 0;
}