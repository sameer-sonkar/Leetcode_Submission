class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<tuple<double, int, int>, vector<tuple<double, int, int>>,
                       greater<tuple<double, int, int>>>
            q;
        for (int i = 0; i < n - 1; i++) {
            q.push({1.0 * arr[i] / arr[n - 1], i, n - 1});
        }
        while (k > 1) {
            auto [fr, i, j] = q.top();
            q.pop();
            if (j - 1 >= i) {
                q.push({1.0 * arr[i] / arr[j - 1], i, j - 1});
            }

            k--;
        }
        auto [fr, row1, row2] = q.top();
        return {arr[row1], arr[row2]};
    }
};