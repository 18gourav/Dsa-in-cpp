// Given a binary tree root[], you need to find the sum of the nodes on the longest path from the root to any leaf node. 
// If two or more paths have the same length, the path with the maximum sum of node values should be considered

class Solution {
  public:
    void solve(Node* root,int len,int &maxlen,int sum,int &maxSum){
        //base case
        if(root == NULL){
            if(len > maxlen){
                maxlen = len;
                maxSum = sum;
            }
            else if(len == maxlen){
                maxSum = max(maxSum,sum);
            }
            
            return ;
        }
        
        //now add the value of root data in sum
        sum += root->data;
        
        //left call
        solve(root->left,len+1,maxlen,sum,maxSum);
        
        //right call
        solve(root->right,len+1,maxlen,sum,maxSum);
    }
    int sumOfLongRootToLeafPath(Node *root) {
        // code here
        int len =0;
        int maxLen = 0;
        
        int sum = 0;
        int maxSum = INT_MIN;
        
        solve(root,len,maxLen,sum,maxSum);
        
        return maxSum;
    }
};