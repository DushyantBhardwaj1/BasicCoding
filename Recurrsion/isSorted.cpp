#include <iostream>
using namespace std;
void isSorted(int arr[],int n,int i){
    if(arr[i]>arr[i+1]){
        cout<<"Not sorted";
        return;
    }
    if (i==n-1){
        cout<<"is sorted";
        return;
    }
    i++;
    isSorted(arr,n,i);
}
int main(){
    int n;
    cout<<"Enter Size of Array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int i=0;
    isSorted(arr,n,i);
}