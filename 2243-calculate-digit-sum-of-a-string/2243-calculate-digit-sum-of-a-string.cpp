class Solution {
private:
    string fun(string& temp, int k) {
        string ans = "";
        int dig = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (i % k == 0 && i != 0) {
                string num = to_string(dig);
                cout << num << endl;
                ans += num;
                dig = 0;
            }
            dig += temp[i] - '0';
        }
   
            ans += to_string(dig);

        cout << ans << endl;
        // int num = stoi(ans);
        // ans = to_string(num);
        return ans;
    }

public:
    string digitSum(string s, int k) {
        string temp = s;
        while (1) {
            if (temp.size() <= k) {
                break;
            }
            temp = fun(temp, k);
        }
        return temp;
    }
};