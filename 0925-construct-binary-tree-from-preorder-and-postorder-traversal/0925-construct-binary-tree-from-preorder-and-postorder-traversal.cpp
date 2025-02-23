/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructTree(vector<int>& pre, vector<int>& post, int& preIndex,
                            int left, int right,
                            unordered_map<int, int>& postMap) {
        if (left > right || preIndex >= pre.size())
            return nullptr;

        TreeNode* root = new TreeNode(pre[preIndex++]);
        if (left == right)
            return root;

        int divider =
            postMap[pre[preIndex]]; // Find left subtree root index in postorder

        root->left = constructTree(pre, post, preIndex, left, divider, postMap);
        root->right =
            constructTree(pre, post, preIndex, divider + 1, right - 1, postMap);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int preIndex = 0;
        unordered_map<int, int> postMap;

        for (int i = 0; i < post.size(); i++)
            postMap[post[i]] = i;

        return constructTree(pre, post, preIndex, 0, post.size() - 1, postMap);
    }
};