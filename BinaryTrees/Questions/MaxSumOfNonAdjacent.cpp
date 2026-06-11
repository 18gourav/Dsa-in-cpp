class Solution {
  public:
    pair<int,int> solve(Node* root){
        //base case
        
        //in our pair we return -> pair<a->int,b->int>
        //a -> we are calculate sum with including that node
        //b -> we are calculate sum without including that node
        
        
        if(root == NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        //now go to left
        pair<int,int> left = solve(root->left);
        
        //now go for right
        pair<int,int> right = solve(root->right);
        
        pair<int,int> finalAns;
        
        finalAns.first = root->data + left.second + right.second;
        
        finalAns.second = max(left.first,left.second) + max(right.first,right.second);
        
        return finalAns;
    }
    int getMaxSum(Node *root) {
        // code here
        pair<int,int> ans = solve(root);
        
        return max(ans.first,ans.second);
    }
};