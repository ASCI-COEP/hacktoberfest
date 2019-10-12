    #include <stdio.h>
    int main(){
        int n1, n2;
        int prod;
        printf("Enter two positive integers: ");
        scanf("%d %d",&n1,&n2);
        prod = n1 * n2;
        while(n1 != n2){
            if(n1 > n2)
                n1 -= n2;
            else
                n2 -= n1;
        }
        printf("GCD = %d\n",n1);
        printf("LCM = %d\n",prod/n1);
        return 0;
    }
