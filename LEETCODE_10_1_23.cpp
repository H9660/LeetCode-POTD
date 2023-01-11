
// problem: https://leetcode.com/problems/same-tree/
// solution: https://leetcode.com/problems/same-tree/solutions/3033043/c-simple-o-n-o-n/

class Solution {
public:
    
    bool issame(TreeNode*p, TreeNode*q)
    {
     if(p==nullptr || q==nullptr)
     return p==q;
        
      return p->val==q->val && issame(p->right, q->right) && issame(p->left, q->left);

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return issame(p,q);

    }
};
