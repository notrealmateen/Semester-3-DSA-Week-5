class Solution {
public:
    vector<int> inorderTraversal(ListNode* root) {
        
        vector<int> vtr;
        while (root!=NULL)
        {
            vtr.push_back(root->val);
            cout<<root->val<<endl;
            root=root->next;
        }
        return vtr;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums=inorderTraversal(head);
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
};