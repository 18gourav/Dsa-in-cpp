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

    //searching

    //1st way
    cout<<map["babbar"]<<endl;

    //2nd way
    cout<<map.at("mera")<<endl;

    //now accesing thae key which is not in map
    // cout<<map.at("UnknownKey")<<endl;
    //now this will throw an error that it is out of range cuz we did not make any entry like this

    //now this will note give error because this line will make this entry and set it as 0
    cout<<map["UnknownKey"]<<endl;

    //now this will also give 0
    cout<<map.at("UnknownKey")<<endl;

    cout<<map.size()<<endl;

    cout<<map.count("bro")<<endl;;
    //will give 0 cuz this key is not present

    cout<<map.count("babbar")<<endl;
    //will give 1 cuz this key is present

    //erase->this will erase that key from map
    map.erase("mera");

    //now using ITERATOR to iterate map
    unordered_map<string,int> :: iterator it = map.begin();

    while(it != map.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }

}