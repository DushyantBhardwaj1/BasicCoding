#include<iostream>
using namespace std;
int pow(int n,int m){
    if(m==0) return 1;
    if(m==1) return n;


    if(m%2==0){
        return pow(n,m/2)*pow(n,m/2);
    }
    else{
        return n*pow(n,m/2)*pow(n,m/2);
    }
    return n;
}
int main(){
    int n,m;
    cout<<"Enter Base : ";
    cin>>n;
    cout<<"Enter Power : ";
    cin>>m;
    cout<<pow(n,m);
}