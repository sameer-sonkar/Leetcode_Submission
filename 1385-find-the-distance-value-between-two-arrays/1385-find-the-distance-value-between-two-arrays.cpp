class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
       sort(arr2.begin(),arr2.end());
       int cnt=0;
       for(auto&x:arr1){
        int a=upper_bound(arr2.begin(),arr2.end(),x)-arr2.begin();
        int y=INT_MAX;
        if(a<arr2.size()){
            y=min(y,arr2[a]-x);

        }
        if(a-1>=0){
            y=min(y,abs(arr2[a-1]-x));
        }
        if(y>d)cnt++;
    
       }
       return cnt;
    }
};