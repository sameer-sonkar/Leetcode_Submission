class Solution {
private:
    long long MOD = 1e9 + 7;
    long long modadd(long long& a, long long b) {
        a = (a % MOD + b % MOD) % MOD;
        return a;
    }
    long long fun(long long idx, string& s, char prev, vector<vector<long long>>& dp) {
        if (idx == s.size())
            return 1;
        if (dp[idx][prev - 'a']!=-1)
            return dp[idx][prev - 'a'];
        long long a = fun(idx + 1, s, prev,dp);
        long long b = 0;
        if (s[idx] != prev) {
            b = fun(idx + 1, s, s[idx],dp);
        }
        modadd(a, b);
        return dp[idx][prev - 'a'] = a;
    }

public:
    int distinctSubseqII(string s) {
        long long n = s.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(27, -1));
        long long ans = fun(0, s, 'a' + 26, dp);
        ans--;
        ans+=MOD;

        modadd(ans, MOD);
        (int)ans;
        return ans;
    }
};