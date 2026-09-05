class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        multiset<int>m;
        for(auto &x:nums){
            m.insert(x);
        }
        long long ans=0;
        while(k--){
            int x=*m.rbegin();
            ans+=x;
            m.erase(m.find(x));
            m.insert((x+2)/3);
        }
        return ans;
        
    }
};