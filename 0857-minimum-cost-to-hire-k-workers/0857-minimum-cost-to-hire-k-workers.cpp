class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        int n = quality.size();
        vector<pair<double, int>> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back({1.0 * wage[i] / quality[i], i});
        }
        sort(temp.begin(), temp.end());
        priority_queue<int> q;
        double ans = 1e18;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            q.push({quality[temp[i].second]});
            cnt += quality[temp[i].second];
            if(i==k-1){
                ans=min(ans,cnt*temp[i].first);
            }
            if (i > k - 1) {
                cnt -= q.top();
                q.pop();
                ans = min(ans, cnt * temp[i].first);
               
            }
           
        }
        return ans;
    }
};