#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<vector>
int main(){
    vector <int> v {10,20,40};
    cout<<v[0]<<" ";
    
    vector <string> v1 {"aawesh","patanwala"};
    cout<<v1[0]<<" ";
    
    vector <char> v4 {'A','B'};
    cout<<v4[0]<<" ";
    
    vector <char> v3 {5};                          //created a vector of size 5, type char
    v3[0] = 'A';
    v3[1] = 'B';
    v3[2] = 'C';
    v3[3] = 'D';
    v3[4] = 'E';
    cout<<v3[0]<<" "<<v3[1]<<" "<<v3[2]<<" "<<v3[3]<<" "<<v3[4]<<" "<<endl;
    cout<<"ok";
}