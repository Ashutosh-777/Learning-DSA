#include <iostream>
#include "Tree_Node_Class.h"
#include <queue>
//taking input recursively also Pre Order Traversal
TreeNode<int>* takeInput(){
    int rootData ;
    cin>>rootData;
    cout<<endl;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        root->children.push_back(takeInput());
    }
    return root;
}
//printing tree recursively
void printTree(TreeNode<int>* root){
    if(root==NULL){
    return;
    }
     cout<<root->data<<':';
    cout<<endl;
    for(int i=0;i<root->children.size();i++){
        printTree(root->children[i]);
    }
}
//take input level wise
TreeNode<int>* takeInput_LW(){
    queue<TreeNode<int>*> pendingNodes;
    int rootData;
    cout<<"Enter root Data "<<endl;
    cin>>rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        //cout<<"Enter Number of Children of "<<front->data;
        cin>>n;
        for(int i=0;i<n;i++){
            int data;
          //  cout<<"Enter data of "<<i<<"th child"<<"of "<<front->data;
            cin>>data;
            TreeNode<int>* child = new TreeNode<int>(data);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;

}
//printing tree level wise
void printTree_LW(TreeNode<int>* root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size()!=0){
        TreeNode<int>* front=pendingNodes.front();
        pendingNodes.pop();
        cout<<front->data<<endl;
        for(int i=0;i<front->children.size();i++){
            pendingNodes.push(front->children[i]);
        }
    }
}
//counting number of nodes
int numNodes(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int ans=1;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* child =root->children[i];
        ans=ans + numNodes(child);
    }
    return ans;
}
int sumNodes(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int sum=root->data;
    for(int i=0;i<root->children.size();i++){
        TreeNode<int>* child =root->children[i];
        sum=sum + sumNodes(child);
    }
    return sum;
}
int maxNodes(TreeNode<int>* root){
    int max= root->data;
    for(int i=0;i<root->children.size();i++){
        int max_child=maxNodes(root->children[i]);
         if(max<max_child){
            max=max_child;
         }
    }
    return max;
}
int heightTree(TreeNode<int>* root){
    if(root==NULL){
        return 0;
    }
    int max=0;
    for(int i=0;i<root->children.size();i++){
        int height_duplicate=heightTree(root->children[i]);
        if(height_duplicate>max){
            max=height_duplicate;
        }
    }
    return max+1;
}
int countLeaf(TreeNode<int>* root){
    if(root->children.size()==0){
        return 1;
    }
    int count=0;
    for(int i=0;i<root->children.size();i++){
        count+=countLeaf(root->children[i]);
    }
    return count;
}
//printing at level K
void printAt(TreeNode<int>* root,int k){
    if(k==1){
        cout<<root->data<<' ';
        return;
    }
    for(int i=0;i<root->children.size();i++){
        printAt(root->children[i],k-1);
    }
    return;
}
//post order traversal
void post_order(TreeNode<int>* root){
    for(int i=0;i<root->children.size();i++){
        post_order(root->children[i]);
    }
    cout<<root->data<<" ";
    return;
}
void delete_tree(TreeNode<int>* root){
    for(int i=0;i<root->children.size();i++){
        delete_tree(root->children[i]);
    }
    delete root;
}
int main(){
    TreeNode<int>* root = takeInput_LW();
    cout<<endl;
    cout<<"nnumber of nodes is "<<numNodes(root)<<endl;
    cout<<"sum of nodes is "<<sumNodes(root)<<endl;
    cout<<"maximum value of a node is  "<<maxNodes(root)<<endl;
    cout<<"height of given tree is  "<<heightTree(root)<<endl;
    cout<<"number of Leaf in the given tree is "<<countLeaf(root)<<endl;
    printAt(root,3);
    cout<<endl;
    post_order(root);
    return 0;
}
//input for my tree
// 1 3 2 3 4 2 5 6 1 7  2 8 9 0 0 1 10 0 0 0
// 1 3 40 3 4 2 5 6 1 7  2 8 9 0 0 1 10 0 0 0
//input for tree takeInput()
//1 3 2 2 5 0 6 0 3 0 4 1 7 1 8 0