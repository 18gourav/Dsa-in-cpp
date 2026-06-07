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
    private:
    int height(Node* root){
        //base case
        if(root == NULL){
            return -1;
        }
        
        //left tree
        int n1 = height(root->left);
        int n2 = height(root->right);
        
        int ans = max(n1,n2) + 1;
        
        return ans;
    }
  public:
    bool isBalanced(Node* root) {
        // code here
        //base case
        if(root == NULL){
            return true;
        }
        
        bool left = isBalanced(root->left);
        bool right  = isBalanced(root->right);
        
        bool balance = abs(height(root->left) - height(root->right)) <= 1;
        
        if(left & right & balance){
            return true;
        }
        
        return false;
        
    }
};