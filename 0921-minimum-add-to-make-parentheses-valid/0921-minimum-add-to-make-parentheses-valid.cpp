class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        vector<int> stk;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                stk.push_back(1);
            else {
                if (stk.size() == 0) {
                    cnt++;
                } else {
                    stk.pop_back();
                }
            }
        }
        cnt += stk.size();
        return cnt;
    }
};