/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(root == NULL){
            return NULL;
        }
        
        if((root->val == p->val) || (root->val == q->val)){
            return root;
        }
        
        //now go to left
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        
        //now go to left
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
        
        //now if both left and right are nt null
        if(leftAns != NULL && rightAns != NULL){
            return root;
        }
        
        //if right is NULL
        else if(leftAns != NULL && rightAns == NULL){
            return leftAns;
        }
        
        //if left is NULL
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }
        
        //if both are null
        else{
            return NULL;
        }
    }
};