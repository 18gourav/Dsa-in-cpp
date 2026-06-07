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
    int height(Node* root) {
        // code here
        
        //base cade
        if(root == NULL){
            return -1;
        }
        
        //in this we calculate left tree height
        int left = height(root->left);
        
        //in this we calculate right tree height
        int right = height(root->right);
        
        int ans = max(left,right) + 1;
        
        return ans;
    }
  public:
    int diameter(Node* root) {
        // code here
        
        //base case
        if(root == NULL){
            return 0;
        }
        
        //ans can be in only left subtree
        int option1 = diameter(root->left);
        
        //ans can be in nly right subtree
        int option2 = diameter(root->right);
        
        //ans can be in both right and left
        //why we add 2 -> one node from left to root and one from right to tot
        int option3 = height(root->left) + 2 + height(root->right);
        
        int ans = max(option1,max(option2,option3));
        
        return ans;
    }
};