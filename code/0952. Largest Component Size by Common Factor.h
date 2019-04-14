/*
Given a non-empty array of unique positive integers A, consider the following graph:

There are A.length nodes, labelled A[0] to A[A.length - 1];
There is an edge between A[i] and A[j] if and only if A[i] and A[j] share a common factor greater than 1.
Return the size of the largest connected component in the graph.

Input: [4,6,15,35]
Output: 4

Input: [20,50,9,63]
Output: 2
*/

class UnionFind{
private:
    vector<int> nums;
public:
    UnionFind(int n){
        nums=vector<int>(n,0);
        for(int i=0;i<n;i++)
            nums[i]=i;
    }
    void Union(int i,int j){
        int ri=root(i),rj=root(j);
        if(ri!=rj)
            nums[ri]=rj;
        return;
    }
    int root(int i){
        if(nums[i]!=i){
            nums[i]=root(nums[i]);
        }
        return nums[i];
    }
    int getroot(int i){
        return nums[i];
    }
    int count(){            //count largest divider
        int res=0, n=nums.size();
        vector<int> v(n,0);
        for(int i=0;i<n;i++){
            int r=root(i);
            v[r]++;
            res=max(res,v[r]);
        }
        return res;
    }
};
class Solution {
public:
    int largestComponentSize(vector<int>& A) {
        int n=A.size();
        unordered_map<int,int> graph;
        UnionFind u(n);
        for(int i=0;i<n;i++){
            for(int j=2;j<=(int)sqrt(A[i]);j++){
                if(A[i]%j==0){
                    if(graph.count(j)) u.Union(i,graph[j]);
                    else graph[j]=u.getroot(i);
                    
                    if(graph.count(A[i]/j)) u.Union(i,graph[A[i]/j] );          //replace j by A[i]/j
                    else graph[A[i]/j]=u.getroot(i);
                }
            }
            if(graph.count(A[i])) u.Union(i,graph[A[i]]);                       //replace j by A[i]
            else graph[A[i]]=u.getroot(i);
        }
        return u.count();
    }
};
