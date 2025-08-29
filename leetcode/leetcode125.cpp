// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-
// alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// iss vala sol ki puri explanation --> strings/codestudio/plaindromeCase.cpp
class Solution {
private:
char toLowerCase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool valid(char ch){
     if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
         return true;
     }

     return false;
}
public:
    bool isPalindrome(string s) {
        string temp = "";

     for(int i =0; i<s.length(); i++){
         if(valid(s[i])){
             temp.push_back(s[i]);
         }
     }

     int start = 0;
     int end = temp.length()-1;

          while(start<=end){
            if(toLowerCase(temp[start]) == toLowerCase(temp[end])){
                start++;
                end--;
            }
            else{
                return false;
            }
          }
          return true;
        
    }
};