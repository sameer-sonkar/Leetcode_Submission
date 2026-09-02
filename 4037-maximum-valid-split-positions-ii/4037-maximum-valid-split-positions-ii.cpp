class Solution {
private:
    int fun(int idx, vector<int> nums) {
        int n = nums.size();
        vector<int> left;
        vector<int> right;
        for (int i = 0; i < n; i++) {
            if (i == idx)
                continue;
            left.push_back(nums[i]);
            right.push_back(nums[i]);
        }
        n = left.size();
        for (int i = 1; i < n; i++) {
            left[i] = __gcd(left[i - 1], left[i]);
        }
        int cnt = 0;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = __gcd(right[i + 1], right[i]);
        }
        for (int i = 1; i < n; i++) {
            if (left[i - 1] == right[i])
                cnt++;
        }
        return cnt;
    }

public:
    int maxValidSplits(
        vector<int>& nums) { // the key idea here  gcd always
                             // dropping as we move from left to right so we can store
                             // that position bcz only removing them might get
                             // us new left arr or right arr and there can be at
                             // max 60 size of that arr kaise pata nhi and this
                             // trick also work for or and and operation also
                             // xor toh aur easy h mathematical approach it has
        int n = nums.size();
        vector<int> left(n);
        vector<int> right(n);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];
        for (int i = 1; i < n; i++) {
            left[i] = __gcd(left[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            right[i] = __gcd(right[i + 1], nums[i]);
        }
        int ans = fun(-1, nums);
        vector<int> possible;
        for (int i = 1; i < n; i++) {
            if (left[i] != left[i - 1]){
                 possible.push_back(i);
                 possible.push_back(i-1);

            }
               
            if (right[i] != right[i - 1]){
                 possible.push_back(i);
                 possible.push_back(i-1);

            }
               
        }
        for (int i = 0; i < possible.size(); i++) {
            ans = max(ans, fun(possible[i], nums));
        }
        return ans;
    }
};