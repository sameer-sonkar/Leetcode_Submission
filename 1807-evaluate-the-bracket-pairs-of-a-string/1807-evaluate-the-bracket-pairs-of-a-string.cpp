class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string, string> m;
        for (auto& x : knowledge) {
            m[x[0]] = x[1];
        }
        string ans = "";
        int n = s.size();
        int i = 0;
        while (i < n) {
            if (s[i] == '(') {
                i++;
                string key = "";
                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }
                i++;
                if (m.find(key) != m.end())
                    ans += m[key];
                else {
                    ans += '?';
                }
            } else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
};