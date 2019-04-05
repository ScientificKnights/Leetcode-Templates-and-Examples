/*
Check whether the original sequence org can be uniquely reconstructed from the sequences in seqs. 
The org sequence is a permutation of the integers from 1 to n, with 1 ≤ n ≤ 104. 
Reconstruction means building a shortest common supersequence of the sequences in seqs 
(i.e., a shortest sequence so that all sequences in seqs are subsequences of it). 
Determine whether there is only one sequence that can be reconstructed from seqs and it is the org sequence.

Input:
org: [1,2,3], seqs: [[1,2],[1,3]]
Output:
false
Explanation:
[1,2,3] is not the only one sequence that can be reconstructed, because [1,3,2] is also a valid sequence that can be reconstructed.

Input:
org: [1,2,3], seqs: [[1,2]]
Output:
false
Explanation:
The reconstructed sequence can only be [1,2].

Input:
org: [1,2,3], seqs: [[1,2],[1,3],[2,3]]
Output:
true
*/

bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
    //topological sort, only one zero indegree elements, 
    int count=0,n=org.size();
    unordered_map<int,int> indegree;
    unordered_map<int,set<int>> graph;
    unordered_map<int,int> visited; //whether visited by seqs. [1][[][]] and [1][[1],[1],[1]]
    for(auto seq:seqs){
        if(seq.size()>=1) visited[seq[0]]++;
        for(int j=1;j<seq.size();j++){
            if(graph[seq[j-1]].count(seq[j])==0){
                visited[seq[j]]++;
                indegree[seq[j]]++;
                graph[seq[j-1]].insert(seq[j]);
            }
        }
    }
    if(visited.size()!=n) return false;
    queue<int> todo;
    for(auto i:org)
        if(indegree.count(i)==0)
            todo.push(i);
    while(!todo.empty()){
        if(todo.size()!=1)
            return false;
        int cur=todo.front();
        todo.pop();
        count++;
        for(auto i:graph[cur]){
            indegree[i]--;
            if(!indegree[i])
                todo.push(i);
        }
    }
    return count==n;
}
