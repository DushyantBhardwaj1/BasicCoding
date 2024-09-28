#include <iostream>
using namespace std;
void binarySearch(int *arr,int key,int start,int mid,int end){
    if(arr[mid]==key){
        cout<<key<<" is at positon "<<mid;
        return;
    }
    if(start>end){
        cout<<"Not Found";
        return;
    }
    if(arr[mid]>key){
        start=mid+1;
    }
    if(arr[mid]<key){
        end=mid;
    }
    mid=start+(end-start)/2;

}
int main(){
    int n;
    cout<<"Enter Size of Array";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cout<<"Enter the Target";
    cin>>key;
    int start=0,end=n-1,mid=start+(end-start)/2;
    binarySearch(arr,key,start,mid,end);
}