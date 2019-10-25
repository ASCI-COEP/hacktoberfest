/*Made by Sameer Kavthekar COEP*/
#include<stdio.h>
#include<math.h>
float detrm(float[25][25],float);

void main()
 {
 float a[25][25],k,d;
 int i,j;
 printf("Enter the order of the matrix\n");
 scanf("%f",&k);
 printf("Enter the elements of the matrix\n");
 for(i=0;i<k;i++)
  {
  for(j=0;j<k;j++)
   {
    int row = i+1;
    int column = j+1;
   printf("A[%d][%d]: ",row,column);  
   scanf("%f",&a[i][j]);
   }
  }
 d=detrm(a,k);
 printf("Deteminant = %f",d);
 }

float detrm(float a[25][25],float ord)
 {
 float s=1,det=0,b[25][25];
 int i,j,m,n,c;
 if(ord==1)
  {
  return(a[0][0]);
  }
 else
  {
  det=0;
  for(c=0;c<ord;c++)
   {
   m=0;
   n=0;
   for(i=0;i<ord;i++)
    {
    for(j=0;j<ord;j++)
     {
     b[i][j]=0;
     if(i!=0&&j!=c)
      {
      b[m][n]=a[i][j];
      if(n<(ord-2))
      n++;
      else
       {
       n=0;
       m++;
       }
      }
     }
    }
   det=det+s*(a[0][c]*detrm(b,ord-1));
   s=-1*s;
   }
  }
 return(det);
 }
