#include <iostream>
using namespace std;
int fibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int b=fibo(n-1)+fibo(n-2);
    return b;
}
int main(){
    int n,Fibo;
    cin>>n;
    
    cout<<fibo(n);
}