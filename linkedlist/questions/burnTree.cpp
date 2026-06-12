class Solution {
  public:
    Node* createParentMapping(Node* root, int target, map<Node*,Node*> &parentToNode){
        Node* ans = NULL;
        
        queue<Node*> q;
        q.push(root);
        
        parentToNode[root] = NULL;
        
        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            
            if(temp -> data == target){
                ans = temp;
            }
            
            if(temp->left){
                parentToNode[temp->left] = temp;
                q.push(temp->left);
            }
            
            if(temp->right){
                parentToNode[temp->right] = temp;
                q.push(temp->right);
            }
        }
        
        return ans;
    }
    int burnTree(Node* node,  map<Node*,Node*> parentToNode){
        int ans = 0;
        map<Node*,bool> visited;
        queue<Node*> q;
        
        q.push(node);
        visited[node] = 1;
        
        while(!q.empty()){
            int flag = 0;
            
            int size = q.size();
            
            for(int i=0; i<size; i++){
                
                Node* temp = q.front();
                q.pop();
                
                //now process left
                if(temp->left && !visited[temp->left]){
                    flag = 1;
                    visited[temp->left] = 1;
                    q.push(temp->left);
                }
                //now process right
                if(temp->right && !visited[temp->right]){
                    flag = 1;
                    visited[temp->right] = 1;
                    q.push(temp->right);
                }
                //now process parent
                if(parentToNode[temp] && !visited[parentToNode[temp]]){
                    flag = 1;
                    visited[parentToNode[temp]] = 1;
                    q.push(parentToNode[temp]);
                }
            }
            if(flag == 1){
                ans++;
            }
        }
        
        return ans;
    }
    int minTime(Node* root, int target) {
        // code here
        //algo
        // 1. Create parent to node mapping
        // 2 . find that node
        //3. burn the tree
        
        map<Node*,Node*> parentToNode;
        
        Node* node = createParentMapping(root,target,parentToNode);
        
        int ans = burnTree(node,parentToNode);
        
        return ans;
        
        
    }
};