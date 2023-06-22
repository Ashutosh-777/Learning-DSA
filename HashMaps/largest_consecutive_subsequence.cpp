#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) {
    n=arr.size();
    sort(arr.begin(),arr.end());
    int max[n]={0};
    int count=1;
    for(int i=0;i<n-1;i++){
        if(arr[i+1]=arr[i]+1){
            count++;
            cout<<"hi";
        }else{
            max[i]=count;
            cout<<count<<"hello"<<endl;
            count=0;
        }
    }
    if(n==1){
        return arr[0];
    }
    for(int i=0;i<n;i++){
        cout<<max[i];
    }
    int p = *max_element(max,max+n);
    return p;
    // Write your code here.
}
int main(){
    vector<int> v;
    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    int print = lengthOfLongestConsecutiveSequence(v,5);
    cout<<print<<endl;
}