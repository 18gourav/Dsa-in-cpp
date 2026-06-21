// Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. 
// The cost to connect two ropes is the sum of their lengths

class Solution {
  public:
    int minCost(vector<int>& arr) {
        //Algo:
        //step1->create a min heap and sara elem daldo
        //step2 -> ab min heap ma sabse pehle 2 elem honge wo sabse chote honge
        //unko pop karo or unka sum kahi store karta jao or minheap ma dalta jao
        //jab tak size 1 na ho
        priority_queue<int,vector<int>,greater<int>> minHeap;
        
        for(auto i:arr){
            minHeap.push(i);
        }
        
        int ans = 0;
        
        while(minHeap.size() > 1){
            int a = minHeap.top();
            minHeap.pop();
            int b = minHeap.top();
            minHeap.pop();
            
            int sum = a + b;
            ans += sum;
            minHeap.push(sum);
        }
        
        return ans;
        
    }
};
// Tc -> O(nlogn)
// Sc -> O(n)