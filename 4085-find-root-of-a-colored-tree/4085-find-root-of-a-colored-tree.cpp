class Solution {
public:
    int findColoredRoot(vector<vector<int>>& edges, string colors) {
        unordered_map<char, char> nextcolor;
        int n = colors.size();
        nextcolor['R'] = 'B';
        nextcolor['B'] = 'W';
        nextcolor['W'] = 'R';
        // always this order is followed so we can identify who is parent and who is child
        // and also the root node has indeg zero and outdeg at max 2
        vector<int> indeg(n, 0);
        vector<int> outdeg(n, 0);
        for (auto& x : edges) {
            int u = x[0], v = x[1];
            if (nextcolor[colors[u]] == colors[v]) {
                indeg[v]++;
                outdeg[u]++;
            } else if (nextcolor[colors[v]] == colors[u]) {
                indeg[u]++;
                outdeg[v]++;

            } else {
                return -1;
            }
        }
        int idx = -1;

        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                if (idx != -1)
                    return -1;
                idx = i;
            }
        }
        if (idx == -1)
            return -1;
        if (outdeg[idx] > 2)
            return -1;
        return idx;
    }
};