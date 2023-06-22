#include <bits/stdc++.h>
#include <math.h>
using namespace std;
long long int lucky_spaceship(int x){
    long long int temp=x;
    int digit=0;
    digit=log10(x)+1;
   
    int a[digit];
    for(int i=0;i<digit;i++){
        a[i]=x%10;
        //cout<<a[i]<<' ';
        x=x/10;
    }
    int maxi =*max_element(a, a + digit);
    //cout<<maxi;
    int mini =*min_element(a, a + digit);
    // cout<<' '<<mini;
    
    return maxi-mini;
}
int main(){
    int m;
    cin>>m;
    while(m--){
         int x,y;
    cin>>x>>y;
    int n=y-x+1;
    long long int a[n];
    long long int b[n];
    bool printed=false;
    for(int i=0;i<n;i++){
        b[i]=x;
        a[i]=lucky_spaceship(x);
        if(lucky_spaceship(x)==9){
            cout<<b[i]<<endl;
            printed=true;
            break;
        }
        x++;
    }
   
    if(!printed){
        int max=*max_element(a, a + n);
    for(int i=0;i<n;i++){
        if(lucky_spaceship(b[i])==max){
            cout<<b[i]<<endl;
            break;  
        }
    }
    }
    }  

    return 0;
}