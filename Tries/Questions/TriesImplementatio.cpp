class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};


class Trie {

public:
    TrieNode* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('\0');
    }

    /** Inserts a word into the trie. */
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
            root->children[index] = child;
        }

        //now recursion
        insertUtil  (child,word.substr(1));
    }

    void insert(string word) {
        insertUtil(root,word);
    }

    /** Returns if the word is in the trie. */
    bool searchUtil(TrieNode* root,string word){
        //base case
        if(word.length() == 0){
            return root->isTerminal;
        }

        //index of word
        int index = word[0] - 'a';
        TrieNode* child;

        //char found
        if(root->children[index] != NULL){
            //now move to next node
            child = root->children[index];
        }
        //not found
        else{
            return false;
        }

        //now recursion
        return searchUtil(child,word.substr(1));
    }

    bool search(string word) {
        return searchUtil(root,word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool prefixUtil(TrieNode* root,string word){
        //base case
        if(word.length() == 0){
            return true;
        }

        //index of word
        int index = word[0] - 'a';
        TrieNode* child;

        //char found
        if(root->children[index] != NULL){
            //now move to next node
            child = root->children[index];
        }
        //not found
        else{
            return false;
        }

        //now recursion
        return prefixUtil(child,word.substr(1));
    }
    bool startsWith(string prefix) {
        return prefixUtil(root,prefix);
    }
};