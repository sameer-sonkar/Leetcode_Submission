class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if(n%2==1)return false;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n; i++) {
            int x = s[i] == ')' ? -1 : 1;
            if (locked[i] == '0')
                cnt1 ++;
            else {
                cnt1 += x;
            }
            if (cnt1 < 0)
                return false;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (locked[i] == '0')
                cnt2++;
            else {
                if (s[i] == ')')
                    cnt2++;
                else {
                    cnt2--;
                }
            }
            if (cnt2 < 0)
                return false;
        }
        return true;
    }
};