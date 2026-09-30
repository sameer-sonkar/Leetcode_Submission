class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, -1), last(26, n);
        for (int i = 0; i < n; i++) {
            int curr = (char)(s[i] - 'a');
            if (first[curr] == -1)
                first[curr] = i;

            last[curr] = i;
        }
        vector<pair<int, int>> arr;
        for (int i = 0; i < 26; i++) {
            int l = first[i], r = last[i];
            if (l == -1)
                continue;
            bool flag = true;
            for (int j = l; j <= r; j++) {
                int curr = (int)(s[j] - 'a');
                int nl = first[curr], nr = last[curr];
                if (nl < l) {
                    flag = false;
                    break;
                }
                r = max(r, nr);
            }
            if (flag == true)
                arr.push_back({r, l});
        }
        sort(arr.begin(), arr.end());
        int prev = -1;
        vector<string> ans;
        for (auto [r, l] : arr) {
            if (prev < l) {
                ans.push_back(s.substr(l, r - l + 1));
                prev = r;
            }
        }
        return ans;
    }
};