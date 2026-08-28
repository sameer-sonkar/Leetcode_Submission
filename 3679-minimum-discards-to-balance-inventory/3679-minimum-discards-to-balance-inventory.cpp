class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        int n = arrivals.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        int i = 0;
        for (int j = 0; j < n; j++) {
            mp[arrivals[j]]++;
            if (mp[arrivals[j]] > m) {
                cnt++;
                mp[arrivals[j]]--;
                arrivals[j] = 0;
            }
            while (j - i + 1 >= w) {
                mp[arrivals[i]]--;
                i++;
            }
        }
        // while (i < n) {
        //     if (mp[arrivals[i]] > m)
        //         cnt++;
        //     mp[arrivals[i]]--;
        //     i++;
        // }
        return cnt;
    }
};