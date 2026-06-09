class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        
        //base case
        if(root == NULL){
            return ans;
        }
        //hd -> horizontal distance
        //queue<node,hd>
        queue<pair<Node*,int>> q;
        
        map<int,int> topNode;
        
        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int> frontNode = q.front();
            q.pop();
            
            Node* Node = frontNode.first;
            int hd = frontNode.second;
            
            //check 1:1 mapping
            if(topNode.find(hd) == topNode.end()){
                topNode[hd] = Node->data;
            }
            
            //now go to left node
            if(Node->left){
                q.push(make_pair(Node->left,hd-1));
            }
            
            //now go to right node
            if(Node->right){
                q.push(make_pair(Node->right,hd+1));
            }
        }
        
        for(auto i:topNode){
            ans.push_back(i.second);
        }
        
        return ans;
        
    }
};