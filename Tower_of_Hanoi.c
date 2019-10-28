#include<stdio.h>
TOH(int,char,char,char);
void main()
{
    int n;
  printf("Enter n :");
  scanf("%d",&n);
  TOH(n,'A','B','C');
}
TOH(int n , char i , char aux , char f)
{
    if(n==1)
    {
        printf("Move disk  from rod %c to rod %c\n",i,f);
        return;
    }
    TOH(n-1,i,f,aux);
    TOH(1,i,aux,f);
    TOH(n-1,aux,i,f);
}
