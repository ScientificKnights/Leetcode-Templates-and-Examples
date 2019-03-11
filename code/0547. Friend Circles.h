/*
There are N students in a class. Some of them are friends, while some are not. 
Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, 
then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, 
then the ith and jth students are direct friends with each other, otherwise not. 
And you have to output the total number of friend circles among all the students.

Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
*/

class Unionfind{
private:
    vector<int> root;
public:
    //constructor
    Unionfind(int n){
        root=vector<int>(n,0);
        for(int i=0;i<n;i++)
            root[i]=i;
    }
    //Union
    bool Union(int u,int v){
        int root_u=findroot(u),root_v=findroot(v);
        if(root_u==root_v) return false;
        root[root_u]=root_v;
        return true;
    }
    //find root
    int findroot(int u){
        if(u!=root[u])
            root[u]=findroot(root[u]);      //path compression
        return root[u];
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n=M.size();
        Unionfind uf(n);
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(M[i][j])
                    uf.Union(i,j);
            
        unordered_set<int> res;
        for(int i=0;i<n;i++)
            res.insert(uf.findroot(i));
        return res.size();
    }
};
