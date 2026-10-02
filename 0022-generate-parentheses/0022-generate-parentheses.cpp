class Solution {
public:
    void fun(vector<string>&ans,string &s,int n,int sum1,int sum2,int sum){
        if(sum1==0&&sum2==0){
            ans.push_back(s);
            return;

        }
        if(sum1>0){
            s+='(';
        fun(ans,s,n,sum1-1,sum2,sum+1);
        s.pop_back();
       

        }
        
        
        if(sum2>sum1){
           
            s+=')';
            fun(ans,s,n,sum1,sum2-1,sum+1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        int sum1=n,sum2=n,sum=0;
        string s;
        fun(ans,s,n,sum1,sum2,sum);
        return ans;
        
    }
};