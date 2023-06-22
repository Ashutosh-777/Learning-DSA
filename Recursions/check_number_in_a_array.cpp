#include <iostream>
using namespace std;
bool is_present(int a[],int x,int n){
  if(n==0){
    return false;
  }
  if(a[0]==x){
    return true;
  }
  bool ans = is_present(a+1,x,n-1);
  return ans;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(is_present(a,13,n)){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    return 0;
}