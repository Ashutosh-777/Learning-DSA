int Solution::braces(string str) {
    stack<char> s;
    int n = str.size();
    if(n==0) return 0;
    int count = 0;
    for(int i=0;i<n;i++){
        if(str[i]==')'){
            //no need already taken care of 
            // if(s.top()==')'){
            //     count = 1;
            //     break;
            // }
            bool ans = true;
            while(s.top()!='('){
                if(s.top()=='+'||s.top()=='*'||s.top()=='-'||s.top()=='/'){
                    ans = false;
                }
                s.pop();
            }
            s.pop();
            if(ans){
                count=1;
                break;
            }
        }else{
            while(str[i]!=')'&&i<n){
                s.push(str[i]);
                i++;
            }
            i--;
        }
        
    }
    return count;
    
}
