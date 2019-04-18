/*
Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 
and takes one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) 
that represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.

Input: ["a==b","b!=a"]
Output: false
*/

class Unionfind{
private:
    vector<int> root=vector<int>(26,0);
public:
    Unionfind(){
        for(int i=0;i<26;i++)
            root[i]=i;
    }
    int rootfind(int i){
        if(i!=root[i])
            root[i]=rootfind(root[i]);
        return root[i];
    }
    void Union(int i,int j){
        int ri=rootfind(i),rj=rootfind(j);
        if(ri!=rj)
            root[ri]=rj;
        return;
    }
};
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        Unionfind u;
        for(auto equa:equations)
            if(equa[1]=='=')
                u.Union(equa[0]-'a',equa[3]-'a');
        for(auto equa:equations)
            if(equa[1]=='!' && u.rootfind(equa[0]-'a')==u.rootfind(equa[3]-'a'))
                return false;
        return true;
    }
};
