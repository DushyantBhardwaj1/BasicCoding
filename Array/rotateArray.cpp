#include <bits/stdc++.h>
using namespace std;
void rotateArray(int arr[],int k,int n){
    vector<int> ko;
    for(int i=0;i<k;i++){
        ko.push_back(arr[i]);
    }
    for(int i=0;i<n-k;i++){
        arr[i]=arr[i+k];
    }
    for(int i=n-k;i<n;i++){
        arr[i]=ko[i-(n-k)];
    }
}
int main(){
    int n;
    
    int k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    rotateArray(arr,k,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}