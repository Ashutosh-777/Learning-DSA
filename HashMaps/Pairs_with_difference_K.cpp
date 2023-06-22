#include <bits/stdc++.h>
using namespace std;
int getPairsWithDifferenceK(int *a, int n, int k) {
	unordered_map<int,int> m;
	sort(a,a+n);
	for(int i=0;i<n;i++){
		m[a[i]]++;
	}
	int count=0;
	for(auto it=m.begin(); it!=m.end();it++){
		int p=it->second;
		int key=it->first;
		int q;
        if(m.count(key+k)){
            q=m[key+k];
        }else{q=0;}
        // cout<<key<<"key"<<m[key]<<endl;
        // cout<<m[key+k]<<endl;
        // //cout<<"p:"<<p<<"q:"<<q<<endl;
		if(k==0){
			count+=p*(p-1)/2;
		}else{
			count+=p*q;
		}
		
	}
	return count;
	
}
int main(){
    int a[]={5,1,2,4};
    cout<<getPairsWithDifferenceK(a,4,3);
    return 0;
}