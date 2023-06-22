#include <iostream>
using namespace std;
class BST{
    BinaryTreeNode<int>* root;
    public:
    BST(){
        root=NULL;
    }
    ~BST(){
        delete root;
    }
    private:
    bool hasData(int data,BinaryTreeNode<int>* root){
        if(root==NULL){
            return false;
        }
        if(root->data==data){
            return true;
        }else if(data>root->data){
            return hasData(data,root->right);
        }else{
            return hasData(data,root->left);
        }
    }
    public:
    bool hasData(int data){
        return hasData(data,root);
    }
    private:
    // void insert(int data,BinaryTreeNode<int>* root){
    //     if(root==NULL){
    //         return;
    //     } 
    //     if(data>root->data){
    //         if(root->right==NULL){
    //             BinaryTreeNode<int>* child =new BinaryTreeNode<int>(data);
    //             root->right=child;
    //             return ;
    //         }
    //         insert(data,root->right);
    //     }else{
    //         if(root->left==NULL){
    //             BinaryTreeNode<int>* child =new BinaryTreeNode<int>(data);
    //             root->left=child;
    //             return ;
    //         }
    //         insert(data,root->left); 
    //     }
    // }
    BinaryTreeNode<int>* insert_1(int data,BinaryTreeNode<int>* node){
        if(node==NULL){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(data);
            return child;
        }
        if(node->data>data){
           BinaryTreeNode<int>* temp =  insert_1(data,node->left);
           node->left=temp;
        }
        if(node->data<data){
            BinaryTreeNode<int>* temp = insert_1(data,node->right);
            node->right = temp;
        }
           return node;
    }
    public:
    void insert(int data){
       this->root =  insert_1(data,this->root);
    }
    private:
    BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>* node){
        if(node==NULL){
            return NULL;
        }
        if(node->data==data){
            if(node->right==NULL&&node->left==NULL){
                delete(node);
                return NULL;
            }
            if(node->right==NULL){
                BinaryTreeNode<int>* temp = node->left;
                node->left=NULL;
                delete(node);
                return temp;
            }
            if(node->left==NULL){
                BinaryTreeNode<int>* temp = node->right;
                node->right=NULL;
                delete(node);
                return temp;
            }
            BinaryTreeNode<int>* temp = node->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            int rightMin = temp->data;
            node->data=rightMin;
            node->right = deleteData(rightMin,node->right);
            return node;

        }
        if(node->data>data){
            node->left = deleteData(data,node->left);
        }
        if(node->data<data){
            node->right = deleteData(data,node->right);
        }
        return node;
    }
    void printTree(BinaryTreeNode<int>* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<":";
        if(root->left!=NULL){
            cout<<"L"<<root->left->data<<",";
        }
        if(root->right!=NULL){
            cout<<"R"<<root->right->data<<";";
        }
        cout<<endl;
        printTree(root->left);
        printTree(root->right);
        }
    public:
    void deleteData(int data){
        root = deleteData(data,root);
        return ;
    }
    void printTree(){
        printTree(root);
        return ;
    }
};