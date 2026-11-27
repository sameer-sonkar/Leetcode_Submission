class Solution {
private:
    int fun(vector<vector<int>>& items, int budget,vector<int>&scores,
            int idx, int leastprice,vector<vector<int>>&dp) {
        if (idx < 0)
            return budget / leastprice;
        int a = fun(items, budget, scores, idx - 1, leastprice,dp);
        if (budget >= items[idx][1]) {
            int b = fun(items, budget - items[idx][1], scores, idx - 1, leastprice,dp) +
                    scores[idx];
            a = max(a, b);
        }

        return a;
    }

public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int leastprice = 1600;
        sort(items.begin(), items.end());
        vector<int> scores(n, 0);
        for (int i = 0; i < n; i++) {
            leastprice = min(leastprice, items[i][1]);
            for (int j = 0; j < n; j++) {
                if (items[i][0] != 0 && items[j][0] % items[i][0] == 0) {
                    scores[i]++;
                }
            }
        }
        vector<int>dp(budget+1,0);
        for(int idx=0;idx<=n;idx++){
            for(int j=budget;j>=0;j--){
                if(idx==0)dp[j]=j/leastprice;
                else{
                    int a=dp[j];
                    if(j>=items[idx-1][1]){
                        a=max(a,dp[j-items[idx-1][1]]+scores[idx-1]);
                    }
                     dp[j]=a;
                }
               

            }
        }
        int ans = dp[budget];
        return ans;
    }
};