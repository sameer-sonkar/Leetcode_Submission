/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    pair<int,int>fun(int &cnt,TreeNode* root){
     
       if(root==nullptr)return {0,0};
        int ans=0;
        int freq=0;
        auto left=fun(cnt,root->left);
        auto right=fun(cnt,root->right);
        ans=left.first+right.first;
        freq=left.second+right.second;
        ans+=root->val;
        freq++;
        if(ans/freq==root->val)cnt++;
        return {ans,freq};


    }
public:
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        auto  sum=fun(cnt,root);
        return cnt;
        
        
    }
};