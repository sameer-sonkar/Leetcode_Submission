class Solution {
public:
    int minRotations(int n, string s) {
        int ans = 0;
        int temp = 0;
        int b = 0;
        for (int i = 0; i < n; i++) {
            int a = s[i] - '0';

            int x = min(abs(a - b), 10 - abs(a - b));

            ans += x;
            int c = s[n - 1] - '0';
            temp = max(temp, x - min(abs(c - b), 10 - abs(c - b)));
            b = s[i] - '0';
        }
        ans -= temp;
        return ans;
    }
};