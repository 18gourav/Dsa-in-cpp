/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void leftTraversal(Node* root,vector<int> &ans){
        //base case(
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return ;
        }
        
        //store root data in ans
        ans.push_back(root->data);
        
        //if that root left exist then call that
        if(root->left){
            leftTraversal(root->left,ans);
        }
        else{
            leftTraversal(root->right,ans);
        }
        
        
    }
    void leafNodeTraversal(Node* root,vector<int> &ans){
        //base case
        if(root == NULL){
            return ;
        }
        
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
        }
        
        //now go to left node
        leafNodeTraversal(root->left,ans);
        
        //now go to right
        leafNodeTraversal(root->right,ans);
        
    }
    
    void rightNodeTraversal(Node* root,vector<int> &ans){
        if((root == NULL) || (root->left == NULL && root->right == NULL)){
            return ;
        }
        
        //if that root left exist then call that
        if(root->right){
            rightNodeTraversal(root->right,ans);
        }
        else{
            rightNodeTraversal(root->left,ans);
        }
        
        //store root data in ans
        ans.push_back(root->data);
        
    }
    vector<int> boundaryTraversal(Node *root) {
        // code here
        vector<int> ans;
        
        //base case
        if(root == NULL){
            return ans;
        }
        
        ans.push_back(root->data);
        
        //go to left
        leftTraversal(root->left,ans);
        
        //go to leaf node in left tree
        leafNodeTraversal(root->left,ans);
        
        //got to leaf node in right tree
        leafNodeTraversal(root->right,ans);
        
        //now to the right
        rightNodeTraversal(root->right,ans);
        
        return ans;
    }
};