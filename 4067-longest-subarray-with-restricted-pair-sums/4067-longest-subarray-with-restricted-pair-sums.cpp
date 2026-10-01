class Solution {
private:
    bool fun(vector<int>& freq, int x) {
        for (int i = 0; i <= 500; i++) {
            int y = x - i;
            if (freq[i] == 0)
                continue;
            if (y >= 0 && y <= 500) {
                if (y == i && freq[y] >= 2)
                    return true;
                if (y != i && freq[y] > 0)
                    return true;
            }
            y = x + i;
            if (y >= 0 && y <= 500 && freq[y] > 0)
                return true;
        }
        return false;
    }

public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> freq(501);

        int ans = 0;
        for (int j = 0; j < n; j++) {
            while (fun(freq, nums[j])) {
                freq[nums[i]]--;
                i++;
            }
            freq[nums[j]]++;
            ans = max(ans, j - i + 1);
        }
        return ans;
    }
};