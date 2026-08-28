class Solution {
    char midchar = '#';

private:
    bool fun(vector<int>& count, string& target, bool flag, int idx,
             string& ans) {
        if (idx == target.size() / 2) {
            string right = ans;
            reverse(right.begin(), right.end());
            string temp = ans;
            if (midchar != '#')
                temp += midchar;
            temp += right;
            if (target < temp) {
                ans = temp;
                return true;
            }
            return false;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] == 0)
                continue;
            if (flag == 0 && (i + 'a') < target[idx])
                continue;
            ans += i + 'a';
            count[i]--;
            bool newflag = false;
            if (i + 'a' > target[idx])
                newflag = true;
            if (fun(count, target, (flag | newflag), idx + 1, ans)) {
                return true;
            }
            ans.pop_back();
            count[i]++;
        }
        return false;
    }

public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);
        for (auto& x : s) {
            count[x - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] > 0 && count[i] % 2 == 1) {
                if (midchar == '#') {
                    midchar = i + 'a';
                } else {
                    return "";
                }
            }
            count[i] /= 2;
        }
        string ans = "";
        bool check = fun(count, target, 0, 0, ans);
        if (!check)
            return "";
        return ans;
    }
};