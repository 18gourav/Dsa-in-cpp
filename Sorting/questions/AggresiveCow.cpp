#include <climits> 
bool isPossible(vector<int> &stalls, int k,int mid){
	int cowDistance = stalls[0];
	int cowCount = 1;	

	for(int i=0; i<stalls.size(); i++){
		if(stalls[i] - cowDistance >= mid){
			cowCount++;
			if(cowCount == k){
			return true;
		}
		cowDistance = stalls[i];
		}
		
	}

	return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());

	int s = 0;
	int maxi = -1;
	int ans = 0;

	for(int i=0; i<stalls.size(); i++){
		maxi = max(maxi,stalls[i]);
	}

	int e = maxi;
	int mid = s + (e-s)/2;

	while(s<e){
		if(isPossible(stalls,k,mid)){
            ans = mid;
			s = mid +1;
		}
		else {
			e = mid -1;
		}
		mid = s + (e-s)/2;
	}

	return ans;
}