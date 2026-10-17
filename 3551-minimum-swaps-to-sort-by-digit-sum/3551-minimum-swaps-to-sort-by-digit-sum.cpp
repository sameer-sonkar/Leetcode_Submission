
class Solution {
public:
    using ll = long long;

    int digit(int x) {
        int s = 0;
        while(x > 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> v = nums;

        sort(v.begin(), v.end(), [&](int a, int b) {
            int x = digit(a);
            int y = digit(b);

            if(x == y) {
                return a < b;
            }
            return x < y;
        });

        unordered_map<int,int> mpp;

        for(int i = 0; i < n; i++) {
            mpp[v[i]] = i;
        }

        vector<int> vis(n, 0);
        int res = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i]) {
                continue;
            }

            int j = i;
            int cnt = 0;

            while(!vis[j]) {
                vis[j] = 1;
                j = mpp[nums[j]];
                cnt++;
            }

            if(cnt > 1) {
                res += cnt - 1;
            }
        }
        return res;
    }
};