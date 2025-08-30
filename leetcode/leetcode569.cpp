// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.


// iss ques ko karna ki technique ko dsa market ma "sliding window" naam se bhi jana jata ha
class Solution {
private:
    bool isSame(int a[26], int b[26]){
        for(int i = 0; i < 26; i++){
            if(a[i] != b[i]){
                return false;
            }
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }

        // isma sabse pehle humne ek alphabet array banali or usma count store karvali
        int arr1[26] = {0};
        for(int i = 0; i < s1.length(); i++){
            int index = s1[i] - 'a';
            arr1[index]++;
        }

        int i = 0;
        int windowSize = s1.length();
        int arr2[26] = {0};

        // fir hamna kya kara pehli window ma gaya jo ki ha s1 length usma jitna alphabet tha unka count store karliya
        //ek arr[2] naam ki nayi array ma
        while(i < windowSize){
            int index = s2[i] - 'a';  
            arr2[index]++;
            i++;
        }

        //agar wo dono same hui to hama ans mil gaya
        if(isSame(arr1, arr2)){
            return true;
        }

        // fir hamna window slide kardi
        while(i < s2.length()){
            //isma hamna naya character add kiya window ma
            char newChar = s2[i];
            int index = newChar - 'a';
            arr2[index]++; 

            //isma jo pehle alphabet tha uska hata kar or uska count bhi hata diya
            char oldChar = s2[i - windowSize];
            index = oldChar - 'a';
            arr2[index]--; 

            i++;
            if(isSame(arr1, arr2)){
                return true;
            }
        }

        return false;
    }
};
