/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  int totalCount(Node* root){
      //base case
      if(root == NULL){
          return 0;
      }
      
      int ans = 1 + totalCount(root->left) + totalCount(root->right);
      return ans;
  }
  bool isCBT(Node* root,int index,int totalNodes){
      //base case
      if(root == NULL){
          return true;
      }
      
      //base case
      if(index >= totalNodes){
          //iska matlab left node ki jagah pehle right node a gyi
          return false;
      }
      
      else{
          return (isCBT(root->left,2*index + 1,totalNodes) && isCBT(root->right,2*index + 2,totalNodes));
      }
  }
   bool isMaxHeap(Node* root){
       //base case
      if(root == NULL){
          return true;
      }
       
       //leaf node
       if(root->left == NULL && root->right == NULL){
           return true;
       }
       //only have left child
       else if(root->left != NULL && root->right == NULL ){
           return (root->data > root->left->data);
       }
       //having both child
       else{
           bool left = isMaxHeap(root->left);
           bool right = isMaxHeap(root->right);
           if(left & right){
               return (root->data > root->left->data && root-> data > root->right->data);
           }
       }
       
       return false;
       
   }
    bool isHeap(Node* tree) {
        // code here
        int index = 0;
        int totalNodes = totalCount(tree);
        
        if(isCBT(tree,index,totalNodes) && isMaxHeap(tree))
            return true;
            
        else
            return false;
    }
};