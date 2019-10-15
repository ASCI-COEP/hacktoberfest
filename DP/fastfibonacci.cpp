#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll a,b,c,d;
void fibo(ll A[],ll n)
{
    if(n==0)
    {
        A[0]=0;
        A[1]=1;
        return ;
    }
    fibo(A,n/2);
    a=A[0];
    b=A[1];
    c=2*b-a;
    c=a*c;
    d=a*a+b*b;
    if(n%2==0)
    {
        A[0]=c;
        A[1]=d;
    }
    else
    {
        A[0]=d;
        A[1]=c+d;
    }   
}
int main()
{
    ll n,a[2];
    cout<<"Enter n :";
    cin>>n;
    fibo(a,n);
    cout<<"fibonacci number  required is "<<a[0]<<"\n";
    return 0;
}
