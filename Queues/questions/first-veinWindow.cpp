// First negative in every window of size k
    
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        vector<int> ans;
        int n = arr.size();
        deque<int> q;
        
        //process the first window
        for(int i=0; i<k; i++){
            if(arr[i]<0){
                q.push_back(i);
            }
        }
        
        //get the ans
        if(q.size() > 0){
            ans.push_back(arr[q.front()]);
        }
        else{
            ans.push_back(0);
        }
        
        //now we will slide thie window
        for(int i=k; i<n; i++){
            //first remove elem 
            if(!q.empty() && i-q.front() >= k){
                q.pop_front();
            }
            
            //now add the elem
            if(arr[i] < 0){
                q.push_back(i);
            }
            
             //get the ans
            if(q.size()>0){
                ans.push_back(arr[q.front()]);
            }
            else{
                ans.push_back(0);
            }
        }
        
        return ans;
    }
};