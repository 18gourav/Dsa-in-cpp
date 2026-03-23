// Stream First Non-repeating

// Given a string s consisting of only lowercase alphabets, for each index i in the string (0 ≤ i < n), 
// find the first non-repeating character in the prefix s[0..i]. If no such character exists, use '#'.

class Solution {
  public:
    string firstNonRepeating(string &s) {
        //pehle har char ka count store karn ake lite map banao
        unordered_map<char,int> count;
        queue<int> q;
        string ans = "";
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            
            //sabse pehle us char ka count badhao
            count[ch]++;
            
            //ab usko queue ma push kardo
            q.push(ch);
            
            //ab we have to find out non - repeating character
            while(!q.empty()){
                //repeating char
                if(count[q.front()] > 1){
                    q.pop();
                }
                //non repeating mil gaya
                else{
                    ans.push_back(q.front());
                    break;
                }
                
            }
            if(q.empty()){
                ans.push_back('#');
            }
        }
        
        return ans;
        
    }
};