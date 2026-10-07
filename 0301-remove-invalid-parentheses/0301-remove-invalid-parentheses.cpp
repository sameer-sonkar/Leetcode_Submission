class Solution {
private:
    void fun(string &s,int idx,int open,int close,unordered_set<string>&ans,int cnt,string curr){
        if(idx==s.size()){
            if(cnt==0&&open==0&&close==0)ans.insert(curr);
            return;
        }
        char x=s[idx];
        if(x=='('){
            if(open>0){
                fun(s,idx+1,open-1,close,ans,cnt,curr);

            }
            fun(s,idx+1,open,close,ans,cnt+1,curr+x);

        }
        else if(x==')'){
            if(close>0){
                fun(s,idx+1,open,close-1,ans,cnt,curr);
            }
            if(cnt>0){
                fun(s,idx+1,open,close,ans,cnt-1,curr+x);
            }

        }
        else{
            fun(s,idx+1,open,close,ans,cnt,curr+x);

        }
    
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        int open=0,close=0;
        for(auto &x:s){
            if(x=='(')open++;
            if(x==')'){
                if(open>0)open--;
                else{
                    close++;
                }
            }
        }
        unordered_set<string>ans;
        fun(s,0,open,close,ans,0,"");
        vector<string>ans2(ans.begin(),ans.end());
        return ans2;

        
    }
};