class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> pre;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                pre.push(i + 1);
            } else if (s[i] == ')') {
                int idx = pre.top();
                pre.pop();
                reverse(s.begin() + idx, s.begin() + i);
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && s[i] != ')')
                ans += s[i];
        }
        return ans;
    }
};