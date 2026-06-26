//It is a type of tree in which a parent has multiple child nodes

#include<iostream>
using namespace std;

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

    void createUtil(TrieNode* root,string word){
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
        createUtil(child,word.substr(1));
    }

    void insert(string word){
        createUtil(root,word);
    }

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

    bool search(string word){
        return searchUtil(root,word);
    }
};

//TC:
//Insertion -> O(l)
//Searching -> O(l)
//l -> length of word
int main() {

    Trie* t = new Trie();

    t->insert("abc");
    t->insert("time");
    cout<<"this is present "<< t->search("tim") <<endl;


    return 0;
}