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
};