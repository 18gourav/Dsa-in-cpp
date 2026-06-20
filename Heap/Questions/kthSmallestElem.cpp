class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
  
        //step1 -> Make a max heap of first k elem
        priority_queue<int> pq;
        for(int i=0; i<k; i++){
            pq.push(arr[i]);
        }
        
        //step2 -> Now for rest elem check if that elem is less than pq.top() then remove at
        // ans push new elem
        for(int i=k; i<arr.size(); i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        //step 3 -> Now our max heap has first k small elem, and our pq.top is ans
        return pq.top();
    }
};