class Solution {
public:
    int mod = 1e9+7;
    int function(int i, int n, int k, vector<vector<vector<int>>>& dp, bool val){
        if (k == 0){
            return 1;
        }
        if (i == n){
            return 0;
        }
        if (dp[i][k][val] != -1){
            return dp[i][k][val];
        }
        int count = function(i+1,n,k,dp,val);
        if (val){
            count += function(i,n,k-1,dp,!val);
        } else {
            count += function(i+1,n,k,dp,!val);
        }
        return dp[i][k][val] = count%mod;
    }

    int numberOfSets(int n, int k) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return function(0,n,k,dp,false);
    }
};