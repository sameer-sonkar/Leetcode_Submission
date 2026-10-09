class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<int> stk;
        int cnt = 0;
        int i = 0;
        for (; i < n;) {
            if (s[i] == '(') {
                stk.push_back(i);
                i++;
            } else {
                if (s[i] == ')') {
                    if (stk.size() == 0) {
                        cnt++;
                        stk.push_back(i);
                    }
                   if ((i + 1 < n && s[i + 1] != ')') || i + 1 == n) {
                        cnt++;
                        i++;

                    } else {
                        i += 2;
                    }
                    stk.pop_back();
                }
            }
        }
        cnt += 2 * stk.size();
        return cnt;
    }
};