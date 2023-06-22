#include <bits/stdc++.h>
using namespace std;
int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
int hamming_distance(int s1,int s2,int l,int min){
    // int ans=0;
    // int n=l;
    // while(l--){
    //     if(s1[l]!=s2[l]){
    //         ans++;
    //     }
    //     if(ans>=min){
    //         break;
    //     }
    // }
    int ans;
    ans=__builtin_popcount(s1^s2);
    cout<<ans<<"   ";
    return ans;
}
int main(){
    int x,y;
    cin>>x>>y;
    string str[x];
    for(int i=0;i<x;i++){
        cin>>str[i];
    }
    int j=0;
    int k=1;
    long long int p=x*(x-1)/2;
    int hammingdis_min=hamming_distance(binaryToDecimal(str[0]),binaryToDecimal(str[0]),y,y);
    for(long long int i=0;i<p;i++){
        // if(j==k){
        //     continue;
        // }
        int mk=hamming_distance(binaryToDecimal(str[j]),binaryToDecimal(str[k]),y,hammingdis_min);
        cout<<mk<<' ';
        if(mk<hammingdis_min){
            hammingdis_min=mk;
        }
        if(hammingdis_min==0){
            break;
        }
        k++;
        if(j==x){
            break;
        }
        if(k==x){
        j++;
            k=j+1;
        }

    }
     cout<<hammingdis_min;
    return 0;
}