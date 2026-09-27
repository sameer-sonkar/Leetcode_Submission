class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> link(n), stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(')
                stk.push_back(i);
            else if (s[i] == ')') {
                link[i] = stk.back();
                stk.pop_back();
                link[link[i]] = i;
            }
        }
        string res;
        for (int i = 0, dir = 1; i < n; i += dir) {
            if (s[i] == '(' || s[i] == ')') {
                i = link[i];
                dir *= -1;

            } else {
                res += s[i];
            }
        }
        return res;
    }
};