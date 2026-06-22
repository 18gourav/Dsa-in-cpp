#include<queue>
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>,greater<int>> miniPq;

	for(int i=0; i<arr.size(); i++){
		int sum = 0;
		for(int j=i;j<arr.size(); j++){
			sum = sum + arr[j];
			if(miniPq.size() < k){
				miniPq.push(sum);
			}
			else{
				if(sum>miniPq.top()){
					miniPq.pop();
					miniPq.push(sum);
				}
			}
		}		
	}

	return miniPq.top();
}