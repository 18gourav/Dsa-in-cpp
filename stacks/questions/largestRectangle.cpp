class Solution {
    private:
    vector<int> nextSmallerElem(vector<int> heights,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            while(s.top()!=-1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            //we get our ans on s.top()
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }
    vector<int> nextprevSmallerElem(vector<int> heights,int n){
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++){
            while(s.top()!=-1 && heights[s.top()] >= heights[i]){
                s.pop();
            }
            //we get our ans on s.top()
            ans[i] = s.top();
            s.push(i);
        }

        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElem(heights,n);

        vector<int> prev(n);
        prev = nextprevSmallerElem(heights,n);
        int area =0;
        for(int i=0; i<n; i++){
            int h = heights[i];
          
            if(next[i] == -1){
                next[i]=n;
            }
            int b = next[i] - prev[i]-1;
            int newArea = h*b;
            area = max(area,newArea);
        }
        return area;
        
    }
};
this beats only 5% PEOPLE