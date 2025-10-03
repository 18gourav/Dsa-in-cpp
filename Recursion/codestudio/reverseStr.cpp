#include <bits/stdc++.h> 
void reverseStr(string& str,int i, int j){
    if(i>j){
        return ;
    }

    swap(str[i],str[j]);
    i++;
    j--;
    reverseStr(str,i,j);
}
string reverseString(string str)
{
	// Write your code here.
	reverseStr(str,0,str.length()-1);
    return str;
}