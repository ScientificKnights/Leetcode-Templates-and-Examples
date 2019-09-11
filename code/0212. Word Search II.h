/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring.
The same letter cell may not be used more than once in a word.

Input: 
board = [
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
 
Note:
All inputs are consist of lowercase letters a-z.
The values of words are distinct.
*/

class Tire{
private:
    bool isend;
public:
    unordered_map<char,Tire*> m;
    Tire(){
        isend=false;
    }
    void add(const string &s){
        int n=s.size();
        Tire* cur=this;
        for(int i=0;i<n;i++){
            if(cur->m.count(s[i])==0)
                cur->m[s[i]]=new Tire();
            cur=cur->m[s[i]];
        }
        cur->isend=true;
    }
    bool getEnd(){
        return isend;
    }
};
class Solution {
private:
    void backtrack(vector<vector<char>>& board, vector<string> &res,string &path, int i, int j, Tire* t){
        char temp=board[i][j];
        if(t->m.count(temp)==0) return;
        
        board[i][j]='.';
        path+=temp;
        if(t->m[temp]->getEnd()){
            res.push_back(path);
        }
        int n=board.size(),m=board[0].size();
        if(i+1<n)
            backtrack(board,res,path,i+1,j,t->m[temp]);
        if(j+1<m)
            backtrack(board,res,path,i,j+1,t->m[temp]);
        if(i-1>=0)
            backtrack(board,res,path,i-1,j,t->m[temp]);
        if(j-1>=0)
            backtrack(board,res,path,i,j-1,t->m[temp]);
        
        board[i][j]=temp;
        path.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Tire* t=new Tire();
        for(auto i:words) t->add(i);
        int n=board.size();
        if(n==0) return {};
        int m=board[0].size();
        vector<string> res;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++){
                string path="";
                backtrack(board,res,path,i,j,t);
            }
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());
        return res;
    }
};
