class Solution {
  public:
    Node* solve(Node *root, int &k, int node){
        //base case
        if(root == NULL){
            return NULL;
        }
        
        //we found our node
        if(root->data == node){
            return root;
        }
        
        //left
        Node* leftAns = solve(root->left,k,node);
        
        //right
        Node* rightAns = solve(root->right,k,node);
        
        if(leftAns != NULL && rightAns == NULL){
            k--;
            if(k<=0){
                //answer lock
                k = INT_MAX;
                return root;
            }
            return leftAns;
        }
        
        if(leftAns == NULL && rightAns != NULL){
            k--;
            if(k<=0){\//answer lock
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }
        
        return NULL;
    }
    int kthAncestor(Node *root, int k, int node) {
        // code here
        Node* ans = solve(root,k,node);
        
        if(ans == NULL || ans->data == node){
            return -1;
        }
        else{
            return ans->data;
        }
    }
};
