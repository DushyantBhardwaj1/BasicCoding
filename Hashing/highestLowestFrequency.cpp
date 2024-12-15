#include <bits/stdc++.h>
using namespace std;

void highestLowestFrequency(int nums[],int n){
    map<int,int> frequency;
    for(int i=0;i<n;i++){
        frequency[nums[i]]++;
    }
    int maxFreq=0, minFreq=n;
    int maxElement=0,minElement=0;

    for(auto x:frequency){
        int i=x.first;
        int j=x.second;
        // to check for max frequency
        if(j>maxFreq){
            maxFreq=j;
            maxElement=i;
        }
        if(j<maxFreq){
            minFreq=j;
            minElement=i;
        }
    }
    cout<<"max frecuency is "<<maxFreq<<" of "<<maxElement<<endl;
    cout<<"min frequency is "<<minFreq<<" of "<<minElement<<endl;
}

int main(){
    cout<<"No of elements in array";
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    highestLowestFrequency(nums,n);

}