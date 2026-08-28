class Solution {
public:
    vector<vector<int>> generateSchedule(int n) {
        if (n <= 4)
            return {};
        vector<vector<int>> allmatch;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    allmatch.push_back({i, j});
                }
            }
        }
        vector<vector<int>> ans;
        while (allmatch.size() > 0) {
            vector<vector<int>> temp;

            for (int i = 0; i < allmatch.size(); i++) {
                if (ans.size() == 0) {
                    ans.push_back(allmatch[i]);
                    continue;
                }
                auto curr = allmatch[i];
                int currhome = curr[0];
                int curraway = curr[1];
                int nexthome, nextaway, prevhome, prevaway;
                nexthome = ans[ans.size() - 1][0],
                nextaway = ans[(ans.size() - 1)][1];
                if (currhome != nexthome && currhome != nextaway &&
                    curraway != nexthome && curraway != nextaway) {
                    ans.push_back({currhome, curraway});
                    continue;
                }
                int j = 0;
                for (; j < ans.size(); j++) {

                    nexthome = ans[j][0];
                    nextaway = ans[j][1];
                    bool flag1 =
                        (currhome != nexthome && currhome != nextaway &&
                         curraway != nexthome && curraway != nextaway);

                    if (j == 0) {
                        if (flag1) {

                            break;
                        }
                    } else {
                        prevhome = ans[j - 1][0];
                        prevaway = ans[j - 1][1];
                        bool flag2 =
                            (currhome != prevhome && currhome != prevaway &&
                             curraway != prevhome && curraway != prevaway);
                        if (flag1 && flag2) {
                            // ans.push_back({currhome, curraway});
                            break;
                        }
                    }
                }
                if (j == ans.size()) {
                    temp.push_back({currhome, curraway});
                } else {
                    ans.insert(ans.begin() + j, {currhome, curraway});
                }
            }
            allmatch = temp;
        }
        return ans;
    }
};