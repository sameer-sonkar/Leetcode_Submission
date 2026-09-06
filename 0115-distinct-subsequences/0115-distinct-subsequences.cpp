class Solution {
private:
    int fun(string &s,string &t,int n,int m,vector<vector<int>>&dp){
        if(m<0)return 1;
        if(n<0)return 0;
        if(s[n]==t[m]){

          
            if(dp[n][m]==-1){
                int a=fun(s,t,n-1,m,dp);
           
            int b=fun(s,t,n-1,m-1,dp);
            dp[n][m]=a+b;

            }
            
            return dp[n][m];
            
        }
        else {
            if(dp[n][m]==-1)
            dp[n][m]=fun(s,t,n-1,m,dp);
            
            return dp[n][m];
        }
        return 0;
    }
public:
    int numDistinct(string s, string t) {
        int n=s.size(),m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans= fun(s,t,n-1,m-1,dp);
        return ans;

        
    }
};