#include<iostream>
using namespace std;
int climbS(int n){
    if (n<=0) return 0;
    if (n==1) return 1;
    if (n==2) return 2;
    int ans=climbS(n-1)+climbS(n-2);
    return ans;
    
}
int main(){
    int n;
    cout<<"Number of stairs";
    cin>>n;
    int ans=climbS(n);
    cout<<ans;

}