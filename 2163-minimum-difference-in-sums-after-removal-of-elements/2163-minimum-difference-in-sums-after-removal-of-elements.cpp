class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> left(n);
        vector<long long> right(n);
        n = n / 3;
        long long sumf = 0, sums = 0;
        multiset<int> lefts;
        multiset<int> rights;
        for (int i = 0; i < n; i++) {
            sumf += nums[i];
            lefts.insert(nums[i]);
            sums += nums[3 * n - i - 1];
            rights.insert(nums[3 * n - i - 1]);
        }
        left[n - 1] = sumf;
        for (int i = n; i < 2 * n; i++) {

            lefts.insert(nums[i]);
            sumf += nums[i];
            int x = *lefts.rbegin();
            lefts.erase(lefts.find(x));
            sumf -= x;
            left[i] = sumf;
        }
        long long ans = sumf - sums;
        for (int i = 2 * n - 1; i >= n; i--) {
            rights.insert(nums[i]);
            sums += nums[i];
            sums -= *rights.begin();
            rights.erase(rights.begin());
            ans = min(ans, left[i - 1] - sums);
        }
        return ans;
    }
};