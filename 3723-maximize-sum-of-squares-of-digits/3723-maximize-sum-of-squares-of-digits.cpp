class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (9 * num < sum)
            return "";
        int dig = 9;
        string ans = "";
        while (sum && dig) {
            while (dig > sum)
                dig--;
            int x = sum / dig;
            sum -= dig * x;
            num -= x;
            string temp(x, dig + '0');
            ans += temp;
            dig--;
        }
        if (num != 0) {
            string temp(num, '0');
            ans += temp;
        }
        return ans;
    }
};