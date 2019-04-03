/*
The set [1,2,3,...,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Input: n = 3, k = 3
Output: "213"

Input: n = 4, k = 9
Output: "2314"
*/

class Solution {
private:
    void helper(string & res, unordered_set<int>& visited, int total, int n, int k){
        if(0==n) return;
        int m=k/total+1,count=0,i=1;
        while(count<m){
            if(visited.count(i)==0)
                count++;
            i++;
        }
        visited.insert(i-1);
        res+=to_string(i-1);
        helper(res,visited,(n==1)?1:total/(n-1),n-1,k%total);
    }
public:
    string getPermutation(int n, int k) {
        unordered_set<int> visited;
        string res="";
        int total=1;
        //total is (N-1)!, cut into group by first number, the number in a group
        for(int i=1;i<n;i++)
            total*=i;
        helper(res,visited,total,n,k-1);
        return res;
    }
};
