class Solution {

public:
    long long MOD1=1e9+7;
    long long MOD2=1e9+9;
    long long base1=911382323;
    long long base2=972663759;
    long long gethash(vector<int>&nums,long long k,long long base,long long MOD){
        long long hash=0;
        for(long long i=0;i<k;i++){
            hash=((hash*base)%MOD+nums[i])%MOD;
        }
        return hash;
    }
    long long fun(vector<int>&nums,long long n,long long k){
        long long hash1=gethash(nums,k,base1,MOD1);
        long long hash2=gethash(nums,k,base2,MOD2);
        long long radix1=1;
        long long radix2=1;
        for(long long i=1;i<=k;i++){
            radix1=(radix1*base1)%MOD1;
            radix2=(radix2*base2)%MOD2;
        }
        map<pair<long long,long long>,long long>m;
        m[{hash1,hash2}]++;
        for(long long i=k;i<n;i++){
            hash1=(((hash1*base1)%MOD1-(radix1*nums[i-k])%MOD1+MOD1)+nums[i])%MOD1;
            hash2=(((hash2*base2)%MOD2-(radix2*nums[i-k])%MOD2+MOD2)+nums[i])%MOD2;
            m[{hash1,hash2}]++;
        }
        for(auto &x:m){
            if(x.second==1)return 1;
 
        }
        m.clear();
        return 0;
    }
    
    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int lo=1,hi=n;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(fun(nums,n,mid)){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
        
    }
};