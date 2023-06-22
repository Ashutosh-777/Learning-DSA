#include <iostream>
#include "binary_tree_class.h"
#include <queue>
using namespace std;
void solve(int a[],int b[],int n,BinaryTreeNode<int>* root){
    if(n==0){
        return;
    }
        BinaryTreeNode<int>* left=new BinaryTreeNode<int>(a[1]);
        for(int i=0;i<n;i++){
            if(b[i]==)
        }
        BinaryTreeNode<int>* right=new BinaryTreeNode<int>(a[0]);
}
int main(){
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(a[0]);
    solve(a,b,n,root);
    return 0;
}