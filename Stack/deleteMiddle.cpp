void helper(stack<int> &s,int middle){
    if(middle==0){
        s.pop();
        return;
    }
    int val = s.top();
    s.pop();
    helper(s,middle-1);
    s.push(val);
}
void deleteMiddle(stack<int>& s){
    int n = s.size();
    int middle = (n)/2;
    helper(s,middle);
}