#include<iostream>
using namespace std;

// iss leetcode ques ma hamna koi word testSample- isme e sabse zyada baar ha to vo de diya

char getMaxCharacter(string s){
    // sabse pehle hamna ek aaray banai 26 alphabet or unko no se jod diya
    //a-1,b-2---------------z-26
    int arr[26] = {0};

    // fir hamna string ke upar ek loop chala diya
    for(int i=0;i<s.length(); i++){
        char ch = s[i];

        int num = 0;
        // or fir jo bhi char hoga uski value ma sa a ko subtract karke usi alpahbet ke no ma count++ kardenge jisse
        //harno ka count mil jayega
        num = ch - 'a';
        arr[num]++;
    }

    // fir hum log isse us array ma max value nikalenge
    int maxi = -1,ans = 0;
    for(int j=0; j<26; j++){
        if(maxi<arr[j]){
            ans = j;
            maxi = arr[j];
        }
    }

    // fir human uss max value ma a jod diya to vo alphabet nikal gaya 
    return 'a' + ans;
}

int main(){

    string s;
    cin>>s;
    cout<<getMaxCharacter(s);

    return 0;
}