#include <iostream>
using namespace std;
void solve(int n,string s,string h,string d,int count){
    if(n==1){
      cout<<"plate "<<n<<" from "<< s <<" to "<< d <<endl;  
      count++;
      return;
    }
    solve(n-1,s,d,h,count);
    cout<<"plate "<<n<<" from "<< s <<" to "<< d <<endl;
    count++;
    solve(n-1,h,s,d,count);
    return;
}
int main(){
    int n;
    cin>>n;
    int count=0;
    solve(n,"source","helper","destination",count);
    cout<<count<<endl;
    return 0;
}