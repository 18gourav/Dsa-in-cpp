// You have been given a string 'STR' of words. You need to replace all the spaces between words with “@40”.

#include <bits/stdc++.h> 
string replaceSpaces(string &str){
	// Write your code here.
	string result;
	for(int i=0; i<str.length(); i++){
		if(str[i] == ' '){
			result += "@40";
		}
		else {
			result += str[i];
		}
	}
	return result;
}