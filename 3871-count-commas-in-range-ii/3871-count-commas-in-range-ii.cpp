class Solution {
private:
long long fun(string &s){
    long long ans=0;
    for(auto &x:s){
        ans*=10;
        ans+=(x-'0');
    }
    return ans;
}
public:
    long long countCommas(long long n) {
        int dig=0;
        long long temp=n;
        while(temp){
            dig++;
            temp/=10;
        }
        long long ans=0;
        int x=4;
        string s="999";
        while(x<dig){
            long long num=fun(s);
            ans+=n-num;
            s+="999";
            x+=3;

        }
        long long num=fun(s);
        if(n>=num)
         ans+=n-num;
         return ans;

        
    }
};