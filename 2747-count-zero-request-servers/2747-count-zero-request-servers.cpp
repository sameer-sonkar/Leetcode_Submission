class Solution {
public:
    vector<int> countServers(int b, vector<vector<int>>& logs, int a,
                             vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });
        //  for(auto&x:logs){
        //     cout<<x[0]<<" "<<x[1]<<endl;
        //  }

        unordered_map<int, int> s;
        int i = 0, j = 0, n = logs.size();
        vector<int> ans(queries.size());
        vector<pair<int, int>> temp;
        for (int i = 0; i < queries.size(); i++) {
            temp.push_back({queries[i], i});
        }
        sort(temp.begin(), temp.end());

        for (int k = 0; k < queries.size(); k++) {
            int x=temp[k].first;
            while (j < n && logs[j][1] <= x) {
                s[logs[j][0]]++;
                j++;
            }
            while (i < n && logs[i][1] < x - a && s.size() > 0) {
                s[logs[i][0]]--;
                if (s[logs[i][0]] == 0) {
                    s.erase(logs[i][0]);
                }
                i++;
            }
            ans[temp[k].second]=b - s.size();
        }
        return ans;
    }
};