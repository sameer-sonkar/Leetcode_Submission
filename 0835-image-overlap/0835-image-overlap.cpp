class Solution {
private:
    int fun(int row, int col, vector<vector<int>>& img1,
            vector<vector<int>>& img2) {
        int n = img1.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int dx = row + i, dy = col + j;
                if (dx >= 0 && dx < n && dy >= 0 && dy < n) {
                    if (img1[dx][dy] == 1 && img1[dx][dy] == img2[i][j])
                        cnt++;
                }
            }
        }
        return cnt;
    }

public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        int ans=0;
        // there are the 2*n-1 poss of shift the matrix up down and 2*n-1 poss of shift left right so brute force all
        for (int row = 1 - n; row < n; row++) {
            for (int col = 1 - n; col < n; col++) {
                int x = fun(row, col, img1, img2);
                ans = max(ans, x);
            }
        }
        return ans;
    }
};