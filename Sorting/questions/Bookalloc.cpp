// You are the Librarian of the Ninja library. There are ‘N’ books available in the library and ‘B’ ninjas want to
//  read the books. You know the number of pages in each book and you have to allocate the books to the ‘B’ ninjas in
//   such a way that the maximum number of pages allocated to a ninja is minimum.

// Note:
// A book will be allocated to exactly one ninja. 
// At least one book has to be allocated to a ninja.
// Allotment of the books should be done in a contiguous manner. For example, a ninja can not be allocated book 2 
// and book 4, skipping book 3.
// The task is to return the minimum of the maximum number of pages allocated to a ninja.


#include <bits/stdc++.h> 
bool isPossible(vector<int> &pages, int n, int b,int mid){
	int PageSum = 0;
	int studentCount = 1;

	for(int i=0;i<n;i++){
		if(PageSum + pages[i] <= mid){
			PageSum += pages[i];
		}
		else{
			studentCount++;
			if(studentCount > b || pages[i] > mid){
				return false;
			}
			PageSum = pages[i];
		}
	}
	return true;
}

int allocateBooks(vector<int> &pages, int n, int b)
{
	// Write your code here.
	if(b>n){
		return -1;
	}
	int s = 0;
	int sum = 0;
	int ans = -1;

	for(int i=0;i<n;i++){
		sum += pages[i];
	}

	int e = sum;
	int mid = s + (e-s)/2;
	while(s<=e){
	if(isPossible(pages,n,b,mid)){
		ans = mid;
		e = mid-1;
	}
	else {
		s = mid+1;
	}
       mid = s + (e-s)/2;
	}

	return ans;
}