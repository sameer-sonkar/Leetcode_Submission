class Solution {
private:
    int solve(string &arr1, string &dept1, string &arr2, string &dept2) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int arrm1 = stoi(string(arr1.begin(), arr1.begin() + 2));
        int arrm2 = stoi(string(arr2.begin(), arr2.begin() + 2));
        int deptm1 = stoi(string(dept1.begin(), dept1.begin() + 2));
        int deptm2 = stoi(string(dept2.begin(), dept2.begin() + 2));

        int arrd1 = stoi(string(arr1.begin() + 3, arr1.end()));
        int arrd2 = stoi(string(arr2.begin() + 3, arr2.end()));
        int deptd1 = stoi(string(dept1.begin() + 3, dept1.end()));
        int deptd2 = stoi(string(dept2.begin() + 3, dept2.end()));

        int stday1 = 0, stday2 = 0, endday1 = 0, endday2 = 0;
        for(int m = 0; m < arrm1 - 1; m++) {
            stday1 += days[m];
        }
        stday1 += arrd1;
        for(int m = 0; m < arrm2 - 1; m++) {
            stday2 += days[m];
        }
        stday2 += arrd2;

        for(int m = 0; m < deptm1 - 1; m++) {
            endday1 += days[m];
        }
        endday1 += deptd1;

        for(int m = 0; m < deptm2 - 1; m++) {
            endday2 += days[m];
        }
        endday2 += deptd2;

        int st = max(stday1, stday2), end = min(endday1, endday2);
        if(st > end) return 0;

        return end - st + 1;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        return solve(arriveAlice, leaveAlice, arriveBob, leaveBob);
    }
};