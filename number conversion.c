
94
/**********************************************************
 Program to convert a decimal number to binary, 
 octal and hexadecimal using recursion 
 * 
 * Select conversion: 
 
 * 1. Decimal to binary. 
 * 2. Decimal to octal. 
 * 3. Decimal to hexadecimal. 
 * 4. Exit. 
 
 * Enter your choice: 1
 * Enter a number: 4
 * Result = 100
 **********************************************************/
 
#include<stdio.h> // include stdio.h library
void convert_to_x_base(int, int);
 
 
int main(void)
{
    int num, choice, base;
 
    while(1)
    {
        printf("Select conversion: \n\n");
        printf("1. Decimal to binary. \n");
        printf("2. Decimal to octal. \n");
        printf("3. Decimal to hexadecimal. \n");              
        printf("4. Exit. \n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice)
        {
            case 1:
                base = 2;
                break;
            case 2:
                base = 8;
                break;              
            case 3:
                base = 16;
                break;
            case 4:
                printf("Exiting ...");
                exit(1);
            default:
                printf("Invalid choice.\n\n");
                continue;
        }
        
        printf("Enter a number: ");
        scanf("%d", &num);
        
        printf("Result = ");
        
        convert_to_x_base(num, base);
                
        printf("\n\n");
    }        
    
    return 0; // return 0 to operating system
}
 
 
void convert_to_x_base(int num, int base)
{    
    int rem;
    
    // base condition
    if (num == 0)
    {
        return;
    }
    
    else
    {
        rem = num % base; // get the rightmost digit        
        convert_to_x_base(num/base, base);  // recursive call        
        if(base == 16 && rem >= 10)
        {
            printf("%c", rem+55);
        }
        
        else
        {
            printf("%d", rem);
        }
    }
   
}