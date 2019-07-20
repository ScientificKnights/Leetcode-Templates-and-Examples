/*
Given strings A and B of the same length, we say A[i] and B[i] are equivalent characters. 
For example, if A = "abc" and B = "cde", then we have 'a' == 'c', 'b' == 'd', 'c' == 'e'.

Equivalent characters follow the usual rules of any equivalence relation:

Reflexivity: 'a' == 'a'
Symmetry: 'a' == 'b' implies 'b' == 'a'
Transitivity: 'a' == 'b' and 'b' == 'c' implies 'a' == 'c'
For example, given the equivalency information from A and B above, S = "eed", "acd", and "aab" are equivalent strings,
and "aab" is the lexicographically smallest equivalent string of S.

Return the lexicographically smallest equivalent string of S by using the equivalency information from A and B.

Input: A = "parker", B = "morris", S = "parser"
Output: "makkek"

Input: A = "hello", B = "world", S = "hold"
Output: "hdld"

Input: A = "leetcode", B = "programs", S = "sourcecode"
Output: "aauaaaaada"

String A, B and S consist of only lowercase English letters from 'a' - 'z'.
The lengths of string A, B and S are between 1 and 1000.
String A and B are of the same length.
*/
class UnionFind{
private:
    vector<int> root;
public:
    UnionFind(){
        root.resize(26);
        for(int i=0;i<26;i++)
            root[i]=i;
    }
    int findroot(int i){
        if(root[i]!=i)
            root[i]=findroot(root[i]);
        return root[i];
    }
    void merge(int i, int j){
        int u=findroot(i),v=findroot(j);
        if(u!=v)    //存最小的
            root[max(u,v)]=min(u,v);
        return;
    }
};
class Solution {
public:
    string smallestEquivalentString(string A, string B, string S) {
        UnionFind uf;
        for(int i=0;i<A.size();i++)
            uf.merge(A[i]-'a',B[i]-'a');
        for(int i=0;i<S.size();i++)
            S[i]=uf.findroot(S[i]-'a')+'a';
        return S;
    }
};
