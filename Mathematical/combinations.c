#include <stdio.h>

long int factorial(long int n);

long int calcomb(long int n,long int r);

int main(){

    long int n=0,r=0;

    printf("This is a Program to calculate the combinations of r things out of n things\nEnter the value of n and r\n");

    scanf("%ld%ld", &n, &r);

    if(r>n){

        printf("Wrong input detected\nGive input in the range 0<=r<=n\n");

        return 0;
    }

    printf("The combinations of r things out of n things is\t%ld",calcomb(n,r));

    return 0;
}

long int factorial(long int n){

    if(n<=0){
        return 1;
    }

    else{

        return (n)*factorial(n-1);
    }
};

long int calcomb(long int n,long int r){

    return (factorial(n)/(factorial(r)*factorial(n-r)));
};
