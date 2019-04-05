/*
On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.
Now, a move consists of removing a stone that shares a column or row with another stone on the grid.
What is the largest possible number of moves we can make?
Example 1:
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
*/

class UnionFind{
private:
    vector<int> nums;
public:
    UnionFind(int n){
        for(int i=0;i<n;i++)
            nums.push_back(i);
    }
    int root(int i){
        if(nums[i]!=i)
            nums[i]=root(nums[i]);
        return nums[i];
    }
    void Union(int i,int j){
        if(i!=j){
            int ri=root(i), rj=root(j);
            nums[ri]=rj;
        }
        return;
    }
    int count(){
        int res=0;
        for(int i=0;i<nums.size();i++){
            root(i);
            if(i==nums[i])
                res++;
        }
        return res;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        UnionFind u(n);
        unordered_map<int,int> r,c;
        for(int i=0;i<n;i++){
            if(!r.count(stones[i][0]) && !c.count(stones[i][1]))
                r[stones[i][0]]=c[stones[i][1]]=i;
            else if(!r.count(stones[i][0])){
                r[stones[i][0]]=c[stones[i][1]];
                u.Union(i,c[stones[i][1]]);
            }
            else if(!c.count(stones[i][1])){
                c[stones[i][1]]=r[stones[i][0]];
                u.Union(i,r[stones[i][0]]);
            }
            else{
                u.Union(c[stones[i][1]],r[stones[i][0]]);
                u.Union(i,r[stones[i][0]]);
            }
        }
        return n-u.count();
    }
};
