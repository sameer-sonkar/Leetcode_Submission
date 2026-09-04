class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int second=INT_MIN;
        int n=nums.size();
        stack<int>s;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<second)return true;
            while(s.size()>0&&nums[i]>s.top()){
                second=s.top();
                s.pop();
            }
            s.push(nums[i]);
        }
        return false;
        
    }
};