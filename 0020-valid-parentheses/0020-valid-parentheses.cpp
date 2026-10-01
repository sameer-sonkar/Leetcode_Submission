class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        vector<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i]=='['){
                stk.push_back(s[i]);
            }
            else {
                if (s[i] == ')') {
                    if (stk.size() == 0 || stk.back() != '(')
                        return false;
                    else {
                        stk.pop_back();
                    }
                }
                if (s[i] == '}') {
                    if (stk.size() == 0 || stk.back() != '{')
                        return false;
                    else {
                        stk.pop_back();
                    }
                }
                if (s[i] == ']') {
                    if (stk.size() == 0 || stk.back() != '[')
                        return false;
                    else {
                        stk.pop_back();
                    }
                }
            }
        }
        if(stk.size()>0)return false;
        return true;
    }
};