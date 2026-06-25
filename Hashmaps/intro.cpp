//It is a data structure which has very low tc(like O(1)) in insertion ,deletion and searching
//Used to store key value pair

//In built stuff:
//1. Map -> ordered and implemented using BST and has tc of O(logn) in insertion ,deletion and searching
//2. Unordered_map -> implemented using hash table and has tc of O(1) in insertion ,deletion and searching

//now implementation
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    //creation
    unordered_map<string,int> map;

    //insertion

    //1st way:
    pair<string,int> pair1 = make_pair("babbar",2);
    map.insert(pair1);

    //2nd way
    pair<string,int> pair2("love",1);
    map.insert(pair2);

    //3rd way
    map["mera"] = 1;

}