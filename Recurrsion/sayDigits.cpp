// i/p -> 412 output four one two
#include <iostream>
using namespace std;
void printDigit(string arr[10],int n){
    if(n/10==0){
        cout<<arr[n%10]<<"  ";
        return;
    } 
    printDigit(arr,n/10);
    cout << arr[n % 10] << "    ";



}
int main(){
    int n;
    cout<<"enter digit";
    cin>>n;
    string arr[10]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    printDigit(arr,n);

}