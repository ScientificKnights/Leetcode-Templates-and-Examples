/*
There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. 
You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. 
Derive the order of letters in this language.

Input:
[  "wrt",  "wrf",  "er",  "ett",  "rftt"  ]
Output: "wertf"

Input:
[  "z",  "x"  ]
Output: "zx"

Input:
[  "z",  "x",  "z"  ] 
*/
string alienOrder(vector<string>& words) {
    //topological sort
    int n=words.size();
    vector<unordered_set<int>> graph(26);
    unordered_map<int,int> indegree;
    if(n>=1)
        for(auto i:words[0])
            indegree[i-'a']+=0;
    for(int i=1;i<n;i++){
        int len1=words[i-1].size(),len2=words[i].size();
        int j=0;
        for(;j<min(len1,len2);j++){
            indegree[words[i][j]-'a']+=0;
            if(words[i-1][j]!=words[i][j]){
                if(graph[words[i][j]-'a'].count(words[i-1][j]-'a')==0){
                    graph[words[i][j]-'a'].insert(words[i-1][j]-'a');
                    indegree[words[i-1][j]-'a']++;
                    indegree[words[i][j]-'a']+=0;
                }
                break;
            }
        }
        if(j==min(len1,len2)) j--;  //["wrt","wrtkj"] j不是在break处停的
        for(int k=j+1;k<len1;k++)
            indegree[words[i-1][k]-'a']+=0;
        for(int k=j+1;k<len2;k++)
            indegree[words[i][k]-'a']+=0;
    }
    queue<int> todo;
    string res="";
    for(auto i:indegree)
        if(i.second==0)
            todo.push(i.first);
    while(!todo.empty()){
        int cur=todo.front();
        todo.pop();
        res+=('a'+cur);
        for(auto i:graph[cur]){
            indegree[i]--;
            if(!indegree[i])
                todo.push(i);
        }
    }
    reverse(res.begin(),res.end());
    return (res.size()==indegree.size())?res:"";    //if there is loop
}
