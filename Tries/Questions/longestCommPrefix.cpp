//Approach 1:
string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "";

    //first for loop for iterating first index
    for(int i=0; i<arr[0].size(); i++){
        char ch = arr[0][i];

        //now to check if char is matched with all string char
        bool isMatched = true;
        for(int j=1; j<n; j++){
            //not matched
            if(arr[j].size()<i || arr[j][i] != ch){
                isMatched=false;
                break;
            }
        }
        if(isMatched){
            ans.push_back(ch);
        }
        else{
            break;
        }
    }

    return ans;
}

//Approach2:

class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        childCount = 0;
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word){
        //base case->When we reach the end of the word, now we have to mark that node to terminal
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        //now we have created a alphabet array for any root node, now we have to find that index
        int index = word[0] - 'a';
        TrieNode* child;

        //first case -> it is a existing node
        if(root->children[index] != NULL){
            child = root->children[index];
        }

        //2nd cse -> it is not present we have to create it
        else{
            child = new TrieNode(word[0]);
            root->childCount++;
            root->children[index] = child;
        }

        //now recursion
        insertUtil(child,word.substr(1));
    }

    void insert(string word){
        insertUtil(root,word);
    }

    void lcp(string first,string &ans){
        TrieNode* temp = root;

        for(int i=0;i<first.length();i++)
        {
            char ch = first[i];

            if(temp->childCount==1 && !temp->isTerminal)
            {
                ans.push_back(ch);
                temp = temp->children[ch-'a'];
            }
            else
            {
                break;
            }
        }
     }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie* T = new Trie();

    if(n == 0)
        return "";

    for(int i=0; i<n; i++){
        T->insert(arr[i]);
    }



    string first = arr[0];
    string ans = "";
    T->lcp(first,ans);

    return ans;

}