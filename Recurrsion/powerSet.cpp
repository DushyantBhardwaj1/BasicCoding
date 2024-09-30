#include <bits/stdc++.h>
using namespace std;
void powerSet(vector<int> arr,vector<int> output, vector<vector<int>>& answer,int n,int index){
    //base case
    if(index>=n){
        if(output.size()>0) answer.push_back(output);
        return;
    }
    //exclude
    powerSet(arr,output,answer,n,index+1);
    //include
    output.push_back(arr[index]);
    powerSet(arr,output,answer,n,index+1);
}
int main(){
    int n;
    cout<<"Enter Size of Array";
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int index=0;
    vector<vector<int>> answer;
    vector<int> output;
    powerSet(arr,output,answer,n,index);
    for(int i=0;i<answer.size();i++){
        cout<<"{";
        for(int j=0;j<answer[i].size();j++){
            cout<<answer[i][j];
            if (j != answer[i].size() - 1) 
                cout << ",";  
        }
        cout<<"}";
    }
    
}