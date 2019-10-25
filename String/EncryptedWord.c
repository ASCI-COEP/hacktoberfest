#include <stdio.h> 
#include <string.h> 

void encrypt(char input[100]) 
{ 
    char evenPos = '@', oddPos = '!'; 
  
    int repeat, ascii; 
  
    printf("\nThe encrypted word is: ");
    for (int i = 0; i <= strlen(input); i++) { 
        ascii = input[i]; 
        repeat = ascii >= 97 ? ascii - 96 : ascii - 64; 

        for (int j = 0; j < repeat; j++) { 
            if (i % 2 == 0) 
                printf("%c", oddPos); 
            else
                printf("%c", evenPos); 
        } 
    } 
} 
  
void main() 
{ 
    char input[100];
    printf("Enter the word: ");
    scanf("%s", input);
    printf("Your word is: %s",input);

    encrypt(input); 
} 