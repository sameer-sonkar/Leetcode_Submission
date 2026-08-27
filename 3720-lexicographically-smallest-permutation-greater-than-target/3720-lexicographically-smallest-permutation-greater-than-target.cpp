class Solution {
private:
    string fun(string& s, string& target, int idx, int& flag) {
        int n = s.size();
        multiset<int> m;
        string ans = "";
        for (auto& x : s) {
            m.insert(x);
        }
        for (int i = 0; i < idx; i++) {
            auto it = m.lower_bound(target[i]);
            if (it == m.end() || target[i] < *it) {
                flag = 0;
                return "";
            }
            ans += *it;
            m.erase(it);
        }
        auto it = m.upper_bound(target[idx]);
        if (it == m.end()) {
            flag = 0;
            return "";
        }
        ans += *it;
        m.erase(it);
        while (m.size()) {
            ans += *m.begin();
            m.erase(m.begin());
        }
        return ans;
    }

public:
    string lexGreaterPermutation(string s, string target) {
        string ans = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int flag = 1;
            string temp = fun(s, target, i, flag);
            if (flag) {
                if (ans == "" || ans > temp) {
                    ans = temp;
                }
            }
        }
        return ans;
    }
};