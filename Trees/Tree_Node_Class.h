#include <vector>
using namespace std;
template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;//not necessary to mention T here it will assume data type of its parent node
    TreeNode(T data){
        this->data=data;
    }
    ~TreeNode(){
        for(int i=0;i<children.size();i++){
            delete children[i];
        }
    }
};