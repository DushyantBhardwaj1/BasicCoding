#include <bits/stdc++.h>
using namespace std;
string check(int n){
    if(n==2) return "abc";
    else if(n==3) return "def";
    else if(n==4) return "ghi";
    else if(n==5) return "jkl";
    else if(n==6) return "mnop";
    else if(n==7) return "qrst";
    else if(n==8) return "uvw";
    else if(n==9) return "xyz"; 
}
void solve(vector<vector<string>>& answer,vector<string> output,int index,vector<int> arr){
    //Base Case
    if(index>=arr.size()){
        if(output.size()>0) answer.push_back(output);
        return;
    }
    //Process
    string str=check(arr[index]);
    for(int i=0;i<str.size();i++){
        string temp="";
        temp=temp+str[i];
        output.push_back(temp);
        solve(answer,output,index+1,arr);
        output.pop_back();
    }

}
int main(){
    int n;
    cout<<"Enter Size of Array";
    cin>>n;
    vector<int> arr;
    vector<vector<string>> answer;
    vector<string> output;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    int index=0;
    solve(answer,output,index,arr);
    for(int i=0;i<answer.size();i++){
        cout<<"{";
        for(int j=0;j<answer[i].size();j++){
            cout<<answer[i][j];
            if(j!=answer[i].size()-1) cout<<",";
        }
        cout<<"}";
        if(i!=answer.size()-1) cout<<",";

    }
    
}