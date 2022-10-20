class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums=inorderTraversal(root);
        return TreeMaker(nums,0,nums.size()-1);
    }
    TreeNode* TreeMaker(vector<int>& nums,int start,int end)
    {
        if(start>end)
        {
            return NULL;
        }
        int mid=(start+end)/2;
        TreeNode *root=new TreeNode(nums[mid]);
        root->left=TreeMaker(nums,start,mid-1);
        root->right=TreeMaker(nums,mid+1,end);
        return root;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> stack;
        TreeNode *curr = root;
        vector<int> vtr;
        while (!stack.empty() || curr != NULL)
        {
            if (curr != NULL)
            {
                stack.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = stack.top();
                stack.pop();
                vtr.push_back(curr->val);
                curr = curr->right;
            }
        }
        return vtr;
    }
};