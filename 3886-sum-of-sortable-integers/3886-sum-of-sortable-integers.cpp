class Solution {

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> fact;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                fact.push_back(i);
                if ((n / i) != i)
                    fact.push_back(n / i);
            }
        }
        int ans = 0;
        for (auto& x : fact) {
            cout << x << " ";
        }
        int a=0;
        cout << endl;
        for (auto& x : fact) {

            int mn = -1, mx = -1, k = x;
            bool flag = true;
            for (int i = 0; i <= n - k; i+=k) {
                int cnt = 0;
                int temp = -1, temp2 = INT_MAX;
                for (int j = i; j < i + k; j++) {
                    int idx=(j==i+k-1?i:j+1);
                    if (nums[j] > nums[idx])
                        cnt++;
                    temp = max(temp, nums[j]);
                    temp2 = min(temp2, nums[j]);
                }
               
                
                if (cnt >= 2 || mx > temp2) {
                    flag = false;

                    break;
                }
                mx = temp;
                mn = temp2;
            }
            if (flag)
                ans += k;
        }
        return ans;
    }
};