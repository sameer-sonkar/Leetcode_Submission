class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string temp = s;
        string a = s;
        string b = s;
        sort(temp.begin(), temp.end());
        sort(a.begin() + 1, a.end());
        sort(b.begin(), b.begin() + n - 1);
        if (s == temp)
            return 0;
        else if (a == temp || b == temp)
            return 1;
        else if (n == 2)
            return -1;
        else {
            sort(a.begin(),a.begin()+n-1);
            sort(b.begin()+1,b.end());
            if(a==temp||b==temp)
            return 2;
        }
        return 3;
    }
};