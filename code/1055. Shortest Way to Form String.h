/*
From any string, we can form a subsequence of that string by deleting some number of characters (possibly no deletions).
Given two strings source and target, return the minimum number of subsequences of source 
such that their concatenation equals target. If the task is impossible, return -1.

Input: source = "abc", target = "abcbc"
Output: 2

Input: source = "abc", target = "acdbc"
Output: -1
*/

int shortestWay(string source, string target) {
    int n=source.size(),m=target.size();
    vector<int> visited(26,0);
    for(auto i: source)
        visited[i-'a']++;
    int pos=0;
    for(int i=0;i<m;i++){
        if(!visited[target[i]-'a']) return -1;
        while(source[(pos)%n]!=target[i]) pos++;
        pos++;
    }
    return (pos+n-1)/n;
}
