class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long a = 0, b = 0;
        for (auto& x : source) {
            a += x;
        }

        for (auto& x : target) {
            b += x;
        }
        return a == b;
    }
};