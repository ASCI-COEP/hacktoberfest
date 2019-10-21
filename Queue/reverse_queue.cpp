#include<bits/stdc++.h>
using namespace std;
void reverse(queue<int>& q){
    if(q.empty()){
        return;
    }
    int x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}
void print(queue<int> q){
    if(q.empty()){
        return;
    }
    cout << q.front();
    int x = q.front();
    q.pop();
    print(q);
    q.push(x);
}
int main(){
    queue<int> q;
    q.push(0); q.push(1); q.push(2); q.push(3); q.push(4); q.push(5); q.push(6);
    cout << "Queue before reversing \n";
    print(q);
    cout << endl;
    reverse(q);
    cout << "Queue after reversing \n";
    print(q);
   return 0;
}
