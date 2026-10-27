class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>ans;
        for(int i=0;i<m;i++){
            string col="";
            for(int j=0;j<n;j++){
                if(i==m-1)col+='.';
                else{
                    if(j==0)col+='.';
                    else{
                        col+='#';
                    }
                }
                
            }
            ans.push_back(col);
        }
        return ans;
        
    }
};