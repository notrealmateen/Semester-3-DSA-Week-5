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
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        else
        {
            int left=height(root->left);
            int right=height(root->right);
            int dif=abs(left-right);
            if(dif<=1)
            {
                return isBalanced(root->left) && isBalanced(root->right);
            }
            else
            {
                return false;
            }
        }
    }
    int height(TreeNode* node)
    {
        if(node==NULL) return 0;
        else
        {
            return 1+max(height(node->left),height(node->right));
        }
    }
};