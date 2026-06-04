// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array\\
// to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> maxi;
        vector<int> ans;

        //process the first window
        for(int i=0; i<k; i++){
            while(!maxi.empty() && (nums[maxi.back()]<=nums[i])){
                maxi.pop_back();
            }
            maxi.push_back(i);
        }

        ans.push_back(nums[maxi.front()]);

        //now slide the window
        for(int i=k; i<nums.size(); i++){
            //remove elem from prev window
            if(!maxi.empty() && (i-maxi.front() >= k)){
                maxi.pop_front();
            }

            //now add elem to the window

            while(!maxi.empty() && (nums[maxi.back()]<=nums[i])){
                maxi.pop_back();
            }
            maxi.push_back(i);

            ans.push_back(nums[maxi.front()]);
        }

        return ans;
    }
};