class Solution {
private:
    long long fun(vector<int>& requests, int left, int right, int dir,
                  vector<vector<vector<long long>>> &dp) {
        int n = requests.size();
        if (left == 0 && right == n - 1)
            return 0;
        if (dp[left][right][dir] != -1)
            return dp[left][right][dir];
        int curr;
        if (dir == 0)
            curr = requests[left];
        else {
            curr = requests[right];
        }
        long long cnt = n - (right - left + 1);
        long long ans = 1e15;
        if (left != 0)
            ans = fun(requests, left - 1, right, 0, dp) +
                  1LL * cnt * (curr - requests[left - 1]);
        if (right != n - 1) {
            long long b = fun(requests, left, right + 1, 1, dp) +
                          1LL * cnt * (requests[right + 1] - curr);
            ans = min(ans, b);
        }

        return dp[left][right][dir] = ans;
    }

public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        int idx = -1;
        for (int i = 0; i < requests.size(); i++) {
            if (requests[i] == start) {
                idx = i;
                break;
            }
        }
        if (idx == -1) {
            requests.push_back(start);
        }
        sort(requests.begin(), requests.end());
        for (int i = 0; i < requests.size(); i++) {
            if (requests[i] == start) {
                idx = i;
                break;
            }
        }
        int size = requests.size();
        vector<vector<vector<long long>>> dp(
            size + 1,
            vector<vector<long long>>(size + 1, vector<long long>(2, -1)));
        long long ans = fun(requests, idx, idx, 0, dp);
        return ans;
    }
};