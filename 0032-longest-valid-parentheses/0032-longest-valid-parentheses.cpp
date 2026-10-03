class Solution {
public:
    int longestValidParentheses(string s) {
        int  n=s.size();
        stack<int>st;
        vector<int>temp(n,0);
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else if(s[i]==')'&&st.empty()==false){
                temp[i]=1;
                temp[st.top()]=1;
                st.pop();
            }
        }
        int ans=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(temp[i]==0){
                ans=max(ans,cnt);
                cnt=0;
            }
            else{
                cnt++;
            }
        }
        ans=max(ans,cnt);
        return ans;
        
    }
};