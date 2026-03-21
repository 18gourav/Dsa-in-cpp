class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        stack<int> s;
        
        //checking some edge cases
        if (q.empty() || k <= 0 || k > q.size()) {
            return q;
        }
        
        //first push k elem into the stack
        for(int i=0; i<k; i++){
            int no = q.front();
            q.pop();
            s.push(no);
        }
        
        //now push these elem into the queue
        while(!s.empty()){
            int n= s.top();
            s.pop();
            q.push(n);
        }
        
        //now fetch (n-k) elem and push them again into the queue
        int t = q.size()-k;
        
        while(t--){
            int n = q.front();
            q.pop();
            q.push(n);
        }
        
        return q;
    }
};