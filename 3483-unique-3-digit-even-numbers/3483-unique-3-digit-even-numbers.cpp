class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> s;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || i == k || digits[i] == 0 ||
                        digits[k] % 2 == 1)
                        continue;
                    int no = 100 * digits[i] + 10 * digits[j] + digits[k];
                    s.insert(no);
                }
            }
        }
        return s.size();
    }
};