#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;
    unordered_map<char,int> m;
    unordered_map<char,bool> map;
    unordered_map<char,int> index;
    m['A']=1;
    m['B']=10;
    m['C']=100;
    m['D']=1000;
    m['E']=10000;
    map['A']=false;
    map['B']=false;
    map['C']=false;
    map['D']=false;
    map['E']=false;
    index['A']=-1;
    index['B']=-1;
    index['C']=-1;
    index['D']=-1;
    index['E']=-1;
    int n = s.size();
    int sum = 0;
    sum+=m[s[n-1]];
    map[s[n-1]]=true;
    
    for(int i=n-2;i>=0;i--){
        switch (s[i]) {
    case 'E':
        sum += m['E'];
        //if(!map[s[i]]){
            index[s[i]]=i;
        //}
        map[s[i]] = true;
        break;
    case 'D':
        if (map['E']) {
            sum -= m['D'];
        } else {
            sum += m['D'];
        }
        //if(!map[s[i]]){
            index[s[i]]=i;
        //}
        map[s[i]] = true;
        break;
    case 'C':
        if (map['E'] || map['D']) {
            sum -= m['C'];
        } else {
            sum += m['C'];
        }
        //if(!map[s[i]]){
            index[s[i]]=i;
        //}
        map[s[i]] = true;
        break;
    case 'B':
        if (map['E'] || map['D'] || map['C']) {
            sum -= m['B'];
        } else {
            sum += m['B'];
        }
                //if(!map[s[i]]){
            index[s[i]]=i;
        //}
        map[s[i]] = true;
        break;
    case 'A':
        if (map['E'] || map['D'] || map['C'] || map['B']) {
            sum -= m['A'];
        } else {
            sum += m['A'];
        }
                //if(!map[s[i]]){
            index[s[i]]=i;
        //}
        map[s[i]] = true;
        break;
}
    }
    if(index['E']!=-1){
        if(index['D']<index['E']){
            sum += m['D']+m['E'];
        }else if(index['C']<index['E']){
            sum += m['C']+m['E'];
        }else if(index['B']<index['E']){
            sum += m['B']+m['E'];
        }else if(index['A']<index['E']){
            sum += m['A']+m['E'];
        }
    }else if(index['D']!=-1){
        if(index['C']<index['D']){
            sum += m['C']+m['E'];
        }else if(index['B']<index['D']){
            cout<<"hi"<<endl;
            cout<<sum<<endl;
            sum += m['B']+m['E'];
            cout<<sum<<endl;
        }else if(index['A']<index['D']){
            sum += m['A']+m['E'];
        }
    }else if(index['C']!=-1){
        if(index['B']<index['C']){
            sum += m['B']+m['E'];
        }else if(index['A']<index['C']){
            sum += m['A']+m['E'];
        }
    }else if(index['B']!=-1){
        if(index['A']<index['B']){
            sum += m['A']+m['E'];
        }
    }
    cout<<sum<<endl;
}
    return 0;
}