#include <bits/stdc++.h>
using namespace std;
int func(int rows,int col,int **a){
    if(rows==1&&col==1){
        return a[0][0];
    }
    if(rows<1||col<1){
        return INT_MAX;
    }
    int ans1 = func(rows-1,col-1,a);
    int ans2 = func(rows-1,col,a);
    int ans3 =func(rows,col-1,a);
    int finalAns = min(ans1,min(ans2,ans3)) + a[rows-1][col-1];
    return finalAns;
}
int func_dp(int rows,int col,int **a){
    int ans[rows][col];
    ans[0][0]=a[0][0];
    for(int i=0;i<rows;i++){
        for(int j=0;j<col;j++){
            if(i==0&&j==0){
                continue;
            }
        int ans1 =INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
        if(i-1>=0){
            ans1=ans[i-1][j];
        }
        if(j-1>=0){
            ans2 =ans[i][j-1];
        }
        if(i-1>=0&&j-1>=0){
            ans3 = ans[i-1][j-1];
        }
        ans[i][j]=min(ans1,min(ans2,ans3))+a[i][j];
        }
    }
    return ans[rows-1][col-1];
}
int func_helper(int rows,int col,int**a,int **ans){
    if(rows==1&&col==1){
        ans[0][0] = a[0][0];
        return ans[rows-1][col-1];
    }
    if(rows==0){
        return INT_MAX;
    }
    if(ans[rows-1][col-1]!=-1){
        return ans[rows-1][col-1];
    }
        int ans1  = func_helper(rows-1,col,a,ans);
        int ans2 = func_helper(rows,col-1,a,ans);
        int ans3 = func_helper(rows-1,col-1,a,ans);
    ans[rows-1][col-1]=min(ans1,min(ans2,ans3))+a[rows-1][col-1];
    return ans[rows-1][col-1];
}
int func_memo(int rows,int col,int **a){
    int ** ans = new int*[rows];
    for(int i=0;i<rows;i++){
         ans[i] = new int[col]; 
        for(int j =0;j<col;j++){
            ans[i][j]= -1;
        }
    }
    return func_helper(rows,col,a,ans);
}
int main(){
    int rows,col;
    cin>>rows>>col;
     int** a = new int*[rows];
    for (int i = 0; i < rows; i++) {
        a[i] = new int[col];
    }
    for(int i=0;i<rows;i++){
        for(int j =0;j<col;j++){
            cin>>a[i][j];
        }
    }
    //cout<<func_dp(rows,col,a);
    cout<<func_memo(rows,col,a);
    //cout<<"DONE"<<endl;
    return 0;
}