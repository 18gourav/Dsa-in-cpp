class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        
        //hd -> horizontal distance
        //in this map<hd,map<level,nodes>>
        map<int,map<int,vector<int>>> nodes;
        
        //queue<node,pair<hd,level>>
        queue<pair<Node*,pair<int,int>>> q;
        
        //to store ans
        vector<vector<int>> ans;
        
        //base case
        if(root == NULL){
            return ans;
        }
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node*,pair<int,int>> temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            
            //insert that entry in map
            nodes[hd][level].push_back(frontNode->data);
            
            //update root left in queue
            if(frontNode->left)
                //in left tree, hd dist is always decrease and level always increase
                q.push(make_pair(frontNode->left,make_pair(hd-1,level+1)));
            
            //same for right
            if(frontNode->right)
            //in left tree, hd dist is always increase and level always increase
               q.push(make_pair(frontNode->right,make_pair(hd+1,level+1)));;
        }
        
        for(auto i:nodes){
            vector<int> col;
            for(auto j:i.second){
              for(auto k: j.second){
                  col.push_back(k);
              }
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};