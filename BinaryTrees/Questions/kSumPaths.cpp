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
    void solve(Node *root, int k,vector<int> &path,int &count){
        //base case
        if(root == NULL){
            return ;
        }
        
        path.push_back(root->data);
        
        //go to left
        solve(root->left,k,path,count);
        
        //go to right
        solve(root->right,k,path,count);
        
        //now check the k sum in path vector
        int size = path.size();
        int Sum =0;
        
        for(int i=size-1; i>=0; i--){
            
            Sum += path[i];
            
            if(Sum == k){
                count++;
            }
            
        }
        
        //now pop elem from tree while going back in tree
        path.pop_back();
    }
    int countAllPaths(Node *root, int k) {
        // code here
        vector<int> path;
        int count = 0;
        
        solve(root,k,path,count);
        
        return count;
    }
};