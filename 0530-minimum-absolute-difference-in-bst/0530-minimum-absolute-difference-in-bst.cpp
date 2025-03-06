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
public:
    int solver(TreeNode* root, int& diff, TreeNode*& prev){
        if(root==nullptr) return diff;

        solver(root->left,diff,prev);
        if(prev != nullptr){
            diff = min(diff, abs(root->val - prev->val));
        }
        prev=root;
        solver(root->right,diff,prev);
        return diff;
    }
    
    int getMinimumDifference(TreeNode* root) {
        int diff = INT_MAX;
        TreeNode* prev=nullptr;
        return solver(root,diff,prev);
    }
};