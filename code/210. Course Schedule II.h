/*
There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses,
return an empty array.

Input: 2, [[1,0]] 
Output: [0,1]

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
*/

vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses,vector<int>());
    vector<int> indegree(numCourses,0);
    for(auto i:prerequisites){
        graph[i.second].push_back(i.first);
        indegree[i.first]++;
    }
    queue<int> todo;
    for(int i=0;i<numCourses;i++)
        if(!indegree[i])
            todo.push(i);
    vector<int> path;
    while(!todo.empty()){
        int cur=todo.front();
        todo.pop();
        path.push_back(cur);
        for(auto i:graph[cur]){
            indegree[i]--;
            if(!indegree[i]) todo.push(i);
        }
    }
    return (path.size()==numCourses)?path:vector<int>();
}
