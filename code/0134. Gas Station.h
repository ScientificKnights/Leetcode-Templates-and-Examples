/*
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). 
You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1.

If there exists a solution, it is guaranteed to be unique.
Both input arrays are non-empty and have the same length.
Each element in the input arrays is a non-negative integer.

Input: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
Output: 3

Input: 
gas  = [2,3,4]
cost = [3,4,3]
Output: -1
*/

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    //if sum positive, there must be a solution
    int total=0,sum=0,n=gas.size(),res=0;
    for(int i=0;i<n;i++){
        sum+=(gas[i]-cost[i]);
        total+=(gas[i]-cost[i]);
        if(sum<0) res=i+1,sum=0;
    }
    return (total<0)?-1:res;
}
