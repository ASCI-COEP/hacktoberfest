#include<stdio.h>
#include<stdlib.h>

int main(){
        int n, i;
        char *str;
        printf("Enter the no. of characters\n");
        scanf("%d", &n);
        str = (char *)calloc(n, sizeof(char));
        for(i = 0; i < n; i++){
                scanf(" %c", &str[i]);
                if(96 <= str[i] <= 122){
                        str[i] = str[i] - 32;
                }
        }
        str[i] = '\0';
        printf("Converted string:\n");
        for(i = 0; i < n; i++){
                printf("%c", str[i]);
        }
        printf("\n");
        return 0;
}
