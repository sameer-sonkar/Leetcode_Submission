#define unq(v) v.resize(distance(v.begin(), unique(v.begin(), v.end())));


class Solution {
public:
    
    int minimizeSum(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
   
         int n=nums.size();
     
        if(n<=3){
            return 0;
        }
        else{
            return min(nums[n-1]-nums[2],min(nums[n-2]-nums[1],nums[n-3]-nums[0]));
        }
        return 0;
        
        
    }
}; 