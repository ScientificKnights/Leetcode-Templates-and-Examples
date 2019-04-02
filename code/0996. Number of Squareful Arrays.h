/*
Given an array A of non-negative integers, the array is squareful if for every pair of adjacent elements, 
their sum is a perfect square.
Return the number of permutations of A that are squareful. 
Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].

Input: [1,17,8]
Output: 2
Explanation: 
[1,8,17] and [17,8,1] are the valid permutations.
*/

class Solution {
private:
    bool square(vector<int>& A, int pos1,int pos2){
        int n=sqrt(A[pos1]+A[pos2]);
        if(n*n==A[pos1]+A[pos2]) return true;
        else return false;
    }
    void backtrack(vector<int>& A,int pos, int & res){
        int n=A.size();
        if(pos==n) res++;
        else{
            unordered_map<int,int> used;
            for(int i=pos;i<n;i++){
                if(used.count(A[i])==0 && (pos==0 || square(A,pos-1,i))){
                    used[A[i]]++;
                    swap(A[pos],A[i]);
                    backtrack(A,pos+1,res);
                    swap(A[pos],A[i]);
                }
            }
        }
        return;
    }
public:
    int numSquarefulPerms(vector<int>& A) {
        int res=0;
        backtrack(A,0,res);
        return res;
    }
};
