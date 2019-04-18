/*
In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) 
for which all other nodes are descendants of this node, plus every node has exactly one parent, 
except for the root node which has no parents.

The given input is a directed graph that started as a rooted tree with N nodes (with distinct values 1, 2, ..., N), 
with one additional directed edge added. The added edge has two different vertices chosen from 1 to N, 
and was not an edge that already existed.

The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [u, v] 
that represents a directed edge connecting nodes u and v, where u is a parent of child v.

Return an edge that can be removed so that the resulting graph is a rooted tree of N nodes. 
If there are multiple answers, return the answer that occurs last in the given 2D-array.

Input: [[1,2], [1,3], [2,3]]
Output: [2,3]
Explanation: The given directed graph will be like this:
  1
 / \
v   v
2-->3

Input: [[1,2], [2,3], [3,4], [4,1], [1,5]]
Output: [4,1]
Explanation: The given directed graph will be like this:
5 <- 1 -> 2
     ^    |
     |    v
     4 <- 3
     
The size of the input 2D-array will be between 3 and 1000.
Every integer represented in the 2D-array will be between 1 and N, where N is the size of the input array.
*/

class Unionfind{
//两种情况，1.two parent 1-2 1-3 2-4 3-4, delete second of two parent
//2. there is loop 1-2 2-3 3-4, delete last one in loop
//3. both [[2,1],[3,1],[4,2],[1,4]]  //delete the one in loop and also is a parent.
private:
    vector<int> root;
public:
    Unionfind(int n){
        root=vector<int>(n+1,0);
        for(int i=0;i<n+1;i++)
            root[i]=i;
    }
    int rootfind(int i){
        if(i!=root[i])
            root[i]=rootfind(root[i]);
        return root[i];
    }
    bool Union(int i,int j){
        int ri=rootfind(i),rj=rootfind(j);
        if(rj==ri) return false;
        root[rj]=ri;
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> indegree(n+1);
        vector<int> flag;    //the node has two parent 
        for(auto i:edges){
            indegree[i[1]].push_back(i[0]);
            if(indegree[i[1]].size()==2) {
                flag=i; 
                break;
            }
        }
        Unionfind u(n);
        for(auto edge:edges){
            if(edge!=flag && !u.Union(edge[0],edge[1])){   //先不加入第二个parent
                if(!flag.size())        //没有两个parent：case 2
                    return edge;
                else
                    return {indegree[flag[1]][0],flag[1]};  //case 3
            }
        }
        return flag;    //case 2 and 3
    }
};
