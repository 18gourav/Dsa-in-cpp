// You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome,
// consider alphabets and numbers only and ignore the symbols and whitespaces.
// Note : String 'S' is NOT case sensitive.

#include <bits/stdc++.h> 
//iss vala part ma hum log basically jo bhi uppercase letter ha usko lower case ma kar de raha ha
char toLowerCase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else {
// iss formula ma hum log basically ASCII values ke sath khel raha ha
// Asan tarika samajhna ka --> Uppercase ma sa uppercase hatado or lowercase jod do to wo lowercase ban jayega 
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

//iss vala part ma ham logo ne spaces,special character in sab ko ignore mara ha
bool valid(char ch){
     if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z') || (ch>='0' && ch<='9')){
         return true;
     }

     return false;
}

bool checkPalindrome(string s)
{
     string temp = "";
     
     // fir iss vala part ma hum logo ne nayi string banai or agar letter ya no ha to usko nayi string ma daldiya 
     // jisse space and special character ignored
     for(int i =0; i<s.length(); i++){
         if(valid(s[i])){
             temp.push_back(s[i]);
         }
     }
     
     // fir us nayi string temp pa humne sabko lowercase banake palindrome dekhliya
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
