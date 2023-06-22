#include <iostream>
using namespace std;
//first Method
int last_index(int a[],int n){
    if(n==0){
        return -1;
    }
    int ans=last_index(a+1,n-1);
    if(ans==-1){
        if(a[0]==8){
            return 0;
        }else{
            return -1;
        }
    }else{
        return ans+1;  
    }
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<last_index(a,n)<<endl;
    return 0 ;
}
//Second Method(reversed the array and found the first index)
// int first_index(int a[],int n){
//     if(n==0){
//         return -1;
//     }
//     if(a[0]==8){
//         return 0;
//     }
//     int ans;
//     ans=first_index(a+1,n-1);
//     if(ans==-1){
//         return -1;
//     }else{
//         return ans+1;
//     }
// }
// void swap(int *x,int *y){
//     int temp=*x;
//     *x=*y;
//     *y=temp;
// }
// int main(){
//     int n;
//     cin>>n;
//     int a[n];
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     for(int i=0;i<n/2;i++){
//         swap(a[i],a[n-i-1]);
//     }
//     int lastindex = n-1-first_index(a,n);
//     if(lastindex==n){
//         cout<<-1;
//     }else{    
//         cout<<lastindex;
//     }
//     return 0;
// }