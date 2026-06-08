class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> result;
        
        //base case
        if(root == NULL){
            return result;
        }
        
        //a bool variable for direction
        bool leftToRight = true;
        
        //queue for level order traversal
        queue<Node*> q;
        
        //push root elem
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> ans(size);
            
            for(int i=0; i<size; i++){
                Node* temp = q.front();
                q.pop();
                
                //normal insert or reverse insert
                int index = leftToRight ? i : size-i-1;
                ans[index] = temp->data;
                
                //now left tree
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            leftToRight = !leftToRight;
            
            for(auto i:ans){
                result.push_back(i);
            }
        }
        
        return result;
    }
};