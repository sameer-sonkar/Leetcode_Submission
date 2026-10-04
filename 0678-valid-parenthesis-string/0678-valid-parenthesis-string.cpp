class Solution {
public:
    bool checkValidString(string s) {
        int lo=0,hi=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                lo--;
                hi--;
                
            }
            else if(s[i]=='('){
                lo++;
                hi++;
            }
            else{
                lo--;
                hi++;
            }
            if(hi<0){
                return false;
            }
            lo=max(lo,0);

        }
        if(lo!=0){
            return false;
        }
        return true;
        // think of this que as the range of all possible scenarios with start and close and open bracket 
        // if upperbound is negative then it is false and lo cant be zero 
        // if lo is not zero means there are so many open brackets
    }
};