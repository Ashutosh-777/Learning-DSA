//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string str)
{
    int n = str.length();
    if(n%2==1) return -1;
	stack<char> s;
	stack<char> t;
	for(int i=0;i<n;i++){
		if(str[i]=='{'){
			s.push(str[i]);
		}
		if(str[i]=='}'){
			if(s.size()==0){
				t.push(str[i]);
			}else{
				s.pop();
			}
		}
	}
	int a = t.size();
	int b = s.size();
	//cout<<"hi"<<a<<b<<endl;
	if(a==0){
		return b/2;
	}else{
		if(a%2==0){
		    return (a+b)/2;
		}else{
		    return (b+a+2)/2;
		}
	}
}