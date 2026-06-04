// Given a queue q[] of even size. Your task is to rearrange the queue by interleaving its first half
// with the second half.
// Interleaving is the process of mixing two sequences by alternating their elements while preserving
// their relative order.
// In other words, Interleaving means place the first element from the first half and then first
// element from the 2nd half and again second element from the first half and then second element 
// from the 2nd half and so on....

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        queue<int> newQ;
        int n = q.size();
        
        for(int i=0; i<n/2;i++){
            newQ.push(q.front());
            q.pop();
        }
        
        while(!newQ.empty()){
            q.push(newQ.front());
            q.push(q.front());
            q.pop();
            newQ.pop();
        }
        
        
    }
};