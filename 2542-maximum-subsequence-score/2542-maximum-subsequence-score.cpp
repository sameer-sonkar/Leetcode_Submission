class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> temp;
        for (int i = 0; i < nums1.size(); i++) {
            temp.push_back({nums2[i], nums1[i]});
        }
        sort(temp.rbegin(), temp.rend());
        priority_queue<int, vector<int>, greater<int>> q;
        long long sum = 0;
        long long x = -1;
        for (int i = 0; i < k; i++) {
            q.push(temp[i].second);
            sum += temp[i].second;
            x = temp[i].first;
        }
        long long ans = sum * x;
        for (int i = k; i < temp.size(); i++) {

            sum -= q.top();
            q.pop();
            sum += temp[i].second;
            q.push(temp[i].second);
            x = temp[i].first;
            ans = max(ans, sum * x);
        }
        ans=max(ans,sum*x);
        return ans;
    }
};