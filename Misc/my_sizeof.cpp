#include<bits/stdc++.h>
using namespace std;
#define my_sizeof(x) (char*)(&x + 1) - (char*)(&x)
int main(){
    int i;
    cout << my_sizeof(i) << endl;
    char c;
    cout << my_sizeof(c) << endl;
    float f;
    cout << my_sizeof(f) << endl;
    double d;
    cout << my_sizeof(d) << endl;
    return 0;
}
