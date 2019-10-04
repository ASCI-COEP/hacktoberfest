#include<bits/stdc++.h>

using namespace std;

void pietbl(string str,int pie[]){
    int i=0;
    fill_n(pie,str.length(),-1);
    
    while(str[i]!='\0'){
        i++; int flag=0,k=0;
        while(str[i] == str[k]){
            pie[i] = flag;
            flag++; i++; k++;
        }
    }
}

int KMP(string series, string pattern){
    int i=0,j=-1;
    int flag=0;
    int pie[pattern.length()];
    pietbl(pattern,pie);

    while(i<series.length()){

        while(series[i] == pattern[j+1]  && i<series.length()){
            i++; j++;
            if(j == pattern.length()-1){
                flag = 1;
                break;
            }
        }    
        
        if(flag == 1) break;

        j = pie[j];
        
        if(j==-1)    
            i++;    
    }
    
    return flag==0?-1:(i-pattern.length());    
}

int main(){
    string series("ababcabcabababd");
    string patt("ababd");

    cout<<KMP(series,patt);
}
