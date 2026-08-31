/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr)
            return {-1, -1};
        vector<int>v;
        int idx = 0;
        ListNode* temp = head;

        while (temp->next->next != nullptr) {
            if ((temp->next->val > temp->val &&
                 temp->next->val > temp->next->next->val) ||
                (temp->next->val < temp->val &&
                 temp->next->val < temp->next->next->val)) {
                v.push_back(idx);
            }
            idx++;
            temp = temp->next;
        }
        if (v.size() < 2)
            return {-1, -1};
        int n = v.size();
        vector<int> ans(2);
        ans[1] = v[n - 1] - v[0];
        ans[0] = INT_MAX;
        for (int i = 1; i < n; i++) {

            if (ans[0] > v[i] - v[i - 1])
                ans[0] = v[i] - v[i - 1];
        }
        return ans;
    }
};