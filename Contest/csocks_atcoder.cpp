#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int a[n];
    long long int count[n];
    for(long long int i=0;i<n;i++){
        count[i]=1;
    }
    for(long long int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    long long int j=0;
    for(long long int i=0;i<n-1;i++){
        if(a[i]==a[i+1]){
            count[j]++;
        }else{
            j++;
        }
    }
    long long int sum=0;
    for(long long int i=0;i<n;i++){
        sum=sum+count[i]/2;
    }
    cout<<sum;
    return 0;
}