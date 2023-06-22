#include <iostream>
#include <vector>
using namespace std;
void insert1(vector<int>& v,int target){
    if(v.size()==0||v[v.size()-1]<=target){
        v.push_back(target);
        return;
    }
    int temp=v[v.size()-1];
    v.pop_back();
    insert1(v,target);
    v.push_back(temp);
}
void sort(vector<int>& v){
    if(v.size()==1){
        return;
    }
    int temp=v[v.size()-1];
    v.pop_back();
    sort(v);
    insert1(v,temp);
}

int main(){
    vector<int> v;
    for(int i=0;i<5;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<<v.size()<<endl;
    sort(v);
    cout<<endl;
    for(int i=0;i<5;i++){
        cout<<v[i]<<' ';
    }
    return 0;
}