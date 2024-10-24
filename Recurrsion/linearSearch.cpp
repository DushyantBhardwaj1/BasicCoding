#include <iostream>
using namespace std;
int main(){
    int arr[8]={32,45,67,22,56,66,87,54};
    int n=8;
    int var;
    cout<<"Tell me Number to Find";
    cin>>var;
    for(int i=0; i<n; i++){
        if(arr[i]==var){
            cout<<"Found at the location "<<i+1;
            return 0;
        }
    }
    cout<<" not Found";
    return 0;
}