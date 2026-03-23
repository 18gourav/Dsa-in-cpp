// Gas Station

// There are n gas stations along a circular tour. You are given two integer arrays gas[] and cost[], 
// where gas[i] is the amount of gas available at station i and cost[i] is the gas needed to travel from station i to station (i+1).
// You have a car with an unlimited gas tank and start with an empty tank at some station.
// Your task is to return the index of the starting station if it is possible to travel once around the circular route in a clockwise direction without running out of gas at any station; otherwise,
// return -1.

class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        
        // in this we create balance for goinf to other gas station
        int balance = 0;
        //deficit is for like if we start and at a station if petro is -ve
        //then we store that in deficit
        int deficit = 0;
        int start = 0;
        
        for(int i=0; i<gas.size(); i++){
            balance += gas[i] - cost[i];
            if(balance < 0){
                deficit += balance;
                start = i+1;
                balance = 0;
            }
        }
        
        if(deficit + balance >= 0){
            return start;
        }
        else{
            return -1;
        }
    }
};