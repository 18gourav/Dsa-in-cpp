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

class Trie{
    public:

    //first we will create a root node
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
            root->children[index] = child;
        }

        //now recursion
        insertUtil(child,word.substr(1));
    }

    void insert(string word){
        insertUtil(root,word);
    }

    void printSuggestions(TrieNode* curr,vector<string> &temp,string prefix){
        if(curr -> isTerminal){
            temp.push_back(prefix);
        }

        for(char ch = 'a';ch<='z'; ch++){
            TrieNode* next = curr -> children[ch - 'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }

    vector<vector<string>> getSuggestion(string queryStr) {
        TrieNode* prev = root;
        vector<vector<string>> output;
        string prefix = "";

        for(int i=0; i<queryStr.length(); i++){
            prefix.push_back(queryStr[i]);
            char lastCh = queryStr[i];

            TrieNode* curr = prev->children[lastCh - 'a'];

            //ifcurr is not found
            if(curr == NULL){
                break;
            }
            
            //means last ch is founded
            //now print all suggestion
            vector<string> temp;
            printSuggestions(curr,temp,prefix);

            output.push_back(temp);

            prev = curr;
            
        }

        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //create a trie
    Trie* t = new Trie();

    //insert all contact in a trie
    for(int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        t->insert(str);
    }
    
    return t->getSuggestion(queryStr);
}

//TC: O(M*N^2)
//SC: O(M*N)
//m->length of word
//n -> total no of word in contact list