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
	int opt, Ar, Ac, Br, Bc, i, j, k;
	int A[10][10] ;
	int B[10][10] ;
	int Intm[10][10] ;
	int Final[10][10] ;
	
	printf("\tTo perform Matrix operation of Multiplication\n\n");

	printf("How many rows do you want the Matrix A to have (1 to 10) :- ");
	scanf(" %d", &Ar);
	printf("How many columns do you want the Matrix A to have (1 to 10) :- ");
	scanf(" %d", &Ac);
	printf("How many rows do you want the Matrix B to have (1 to 10) :- ");
	scanf(" %d", &Br);
	printf("How many columns do you want the Matrix B to have (1 to 10) :- ");
	scanf(" %d", &Bc);

	while (Ac!=Br) //Verifying the condition of Matrix multiplication
	{
		printf("For Matrix Multiplication, the number of columns of Matrix A should be identical to the number of rows of Matrix B.\n");
		printf("Please try again.\n");
		printf("How many rows do you want the Matrix A to have (1 to 10) :- ");
		scanf(" %d", &Ar);
		printf("How many columns do you want the Matrix A to have (1 to 10) :- ");
		scanf(" %d", &Ac);
		printf("How many rows do you want the Matrix B to have (1 to 10) :- ");
		scanf(" %d", &Br);
		printf("How many columns do you want the Matrix B to have (1 to 10) :- ");
		scanf(" %d", &Bc);
	}

	for (i=1;i<=Ar;i++) //Creating Matrix A
	{
		for (j=1;j<=Ac;j++)
		{
			printf("Enter the value of A%d%d :- ", i, j);
			scanf(" %d", &A[i][j]);
		}
	}

	printf("\nMatrix A :-\n");
	for (i=1;i<=Ar;i++) //Printing Matrix A
	{
		for (j=1;j<=Ac;j++)
		{
			printf("%d  ", A[i][j]);
			if (j==Ac)
			{
				printf("\n");
			}
		}
	}

	for (i=1;i<=Br;i++) //Creating Matrix B
	{
		for (j=1;j<=Bc;j++)
		{
			printf("Enter the value of B%d%d :- ", i, j);
			scanf(" %d", &B[i][j]);
		}
	}

	printf("\nMatrix B :-\n");
	for (i=1;i<=Br;i++) //Printing Matrix B
	{
		for (j=1;j<=Bc;j++)
		{
			printf("%d  ", B[i][j]);
			if (j==Bc)
			{
				printf("\n");
			}
		}
	}

	for (i=1;i<=Ar;i++) //Pre-multiplying the matrix B by A i.e., generating AB.
	{
		for (j=1;j<=Bc;j++)
		{
		    Final[i][j] = 0 ;//Initializing That perticular element as 0, to avoid problems that occurred on my PC.
			for (k=1;k<=Ac;k++)
			{
				Intm[i][j] = A[i][k]*B[k][j] ;
				Final[i][j] += Intm[i][j] ;
			}
		}
	}

	printf("\nThe Final Matrix AB looks like :-\n");
	for (i=1;i<=Ar;i++) //Printing Matrix AB
	{
		for (j=1;j<=Bc;j++)
		{
			printf("%d  ", Final[i][j]);
			if (j==Bc)
			{
				printf("\n");
			}
		}
	}

	return 0;
}