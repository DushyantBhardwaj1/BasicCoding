#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int sum=0;
    for(int i=n;i>0;i=i/10){
        sum=sum+i%10;
    }
    if(n%sum==0){
        cout<<"Yes";
    }
    else cout<<"No";
    return 0;
}
