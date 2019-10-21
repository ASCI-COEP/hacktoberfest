#include <stdio.h>

long int factorial(long int n);

long int calcomb(long int n,long int r);

int main(){

    long int i=0,j=0,k=0,rows=0;

    printf("This is a program to print the pascal's triangle\nEnter the number of rows upto ehich you want to print pascal's triangle\n");

    scanf("%ld", &rows);

    for(j=0;j<rows;++j){  

        for(i=rows;i>0;--i){

            if(j<i){
                printf(" ");
            }
            
        }

        for(k=0;k<rows;++k){            
            
            if(k<=j){
                
                printf("%ld ",calcomb(j,k));
            
            }
   
        }
    
        printf("\n");

    }


    return 0;
}
long int factorial(long int n){

    if(n==0){
        return 1;
    }

    else{

        return (n)*factorial(n-1);
    }
}

long int calcomb(long int n,long int r){

    return (factorial(n)/(factorial(r)*factorial(n-r)));
}
