#include <iostream>
using namespace std;
int peak(int a[],int n){
    int start=0;
    int end = n-1;
    while(start<=end){
        int middle = start + (end-start)/2;
        if(middle>0&&middle<n-1){
        int middle = start + (end-start)/2;
        if(a[middle]>a[middle-1]&&a[middle]>a[middle+1]){
            return middle;
        }else 
        if(a[middle]>a[middle-1]){
            start =  middle +1 ;
        }else{
            end  = middle - 1; 
        }
        }
        if(middle == 0  ){
            //if only one input then middle + 1 also not  available
            if(n==1){
                return middle;
            }

            if(a[middle]>a[middle+1]){
                return middle;
            }else if(a[middle]<a[middle+1]){
                return middle+1;
            }
            break;
        }
        if(middle == n-1  ){
            if(a[middle]>a[middle-1]){
                return middle;
            }else if(a[middle]<a[middle-1]){
                return middle-1;
            }
            break;
        }
    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<peak(a,n);
    return 0;
}