#include<bits/stdc++.h>
using namespace std;
void rec(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int p = s.top();
    s.pop();
    rec(s, x);
    s.push(p);
}
void reverse(stack<int>& s){
    if(s.empty()){
        return;
    }
    int x = s.top();
    s.pop();
    reverse(s);
    rec(s, x);
}
void print(stack<int> s){
    if(s.empty()){
        return;
    }
    cout << s.top();
    int x = s.top();
    s.pop();
    print(s);
    s.push(x);
}
int main(){
    stack<int> s;
    s.push(0); s.push(1); s.push(2); s.push(3); s.push(4); s.push(5); s.push(6);
    cout << "Stack before reversing \n";
    print(s);
    cout << endl;
    reverse(s);
    cout << "Stack after reversing \n";
    print(s);
   return 0;
}
