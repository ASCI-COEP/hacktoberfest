//remove Duplicate
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[1000], n, i, j;
    
    cin>>n;

    for(i=0; i<n; i++){
        cin>>arr[i];
    }

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(arr[i] != arr[i+1]){
                cout<<arr[i]<<" ";
                cout<<arr[j]<<" ";
            }
            else{
                cout<<i<<" ";
            }

            //i++;
            //j++;

        }
    }
    
    for(i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    
}