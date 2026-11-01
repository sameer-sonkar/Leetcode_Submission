class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int y=*min_element(nums.begin(),nums.end());
        for(auto &x:nums){
            ans+=x;
        }
        ans-=n*y;
        return ans;
        
    }
};