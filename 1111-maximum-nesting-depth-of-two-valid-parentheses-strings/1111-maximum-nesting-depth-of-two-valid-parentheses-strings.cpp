class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<pair<int, int>> stk;
        int n = seq.size();
        vector<int> ans(n);
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (seq[i] == '(') {
                stk.push_back({i, flag});
                flag ^= 1;

            } else {
                auto [idx, tog] = stk.back();
                stk.pop_back();
                ans[idx] = tog;
                ans[i] = tog;
                flag = tog;
            }
        }
        return ans;
    }
};