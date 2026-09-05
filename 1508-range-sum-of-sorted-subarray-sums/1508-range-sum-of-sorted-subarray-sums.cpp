class Solution {
public:
    long long MOD=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
       
        vector<long long>pre(n+1,0);
       
        for(int i=1;i<=n;i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        vector<long long>sum;
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                long long x=pre[j]-pre[i-1];
                sum.push_back(x);
            }
        }
        sort(sum.begin(),sum.end());
        int m=sum.size();
        for(int i=1;i<m;i++){
            sum[i]=(sum[i]%MOD+sum[i-1]%MOD)%MOD;
        }
        right--;
        left--;
        long long ans=(sum[right]%MOD-(left>0?sum[left-1]%MOD:0)+MOD)%MOD;
        return (int)ans;

        
    }
};