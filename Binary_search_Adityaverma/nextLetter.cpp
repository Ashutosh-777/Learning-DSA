#include <iostream>
using namespace std;
char nextLetter(char a[],int n,char x){
    int start = 0;
    int end = n-1;
    char ans = -1;
    if(x>=a[n-1]){
        return a[0]; 
    }
    while(start<=end){
        int middle = start + (end-start)/2;
        if(a[middle]>x){
            ans = a[middle];
            end = middle-1;
        }else{
            start = middle +1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    char c[n];
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    char x;
    cin>>x;
    cout<<nextLetter(c,n,x);
    return 0;
}