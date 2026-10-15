class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
       long long ans=0;
       int n=source.size();
       for(int i=0;i<n;i++){
        ans+=source[i]-target[i];
       }
        return (!ans);
       
    }
   
};