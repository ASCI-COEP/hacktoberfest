#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll interpolationSort(ll A[],ll n,ll x)
{
    ll min=0,max=n-1;
    while(min<=max && A[min]<=x && A[max]>=x)
    {
        if(min==max)
        {
            if(A[min]==x)
            return min;
            else
            return -1;
        }
        ll index= min +(double)(x-A[min])*(max-min)/(A[max]-A[min]) ;
        if(A[index]<x)
            min=index+1;
        else if(A[index]>x)
            max=index-1;
        else
            return index;
    }
    return -1;
}
int main()
{
    ll n,x,index;
    cout<<"Enter array size ";
    cin>>n;
    ll A[n];
    cout<<"Enter elements :";
    for(ll i=0;i<n;i++)
    cin>>A[i];
    sort(A,A+n);
    cout<<"Enter element to be searched ";
    cin>>x;
    index=interpolationSort(A,n,x);
    if(index>-1)
    cout<<"Element found at index "<<index<<"\n";
    else
    cout<<"Element not found";   
}
