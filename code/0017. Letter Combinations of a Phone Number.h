/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
        m['2']={'a','b','c'};m['3']={'d','e','f'};m['4']={'g','h','i'};
        m['5']={'j','k','l'};m['6']={'m','n','o'};m['7']={'p','q','r','s'};
        m['8']={'t','u','v'};m['9']={'w','x','y','z'};
*/

void backtrack(vector<string> &res,string &path, unordered_map<char,vector<char>> & m, string &digits,int pos, int n){
    if(pos==n){
        res.push_back(path);
        return;
    }
    for(int i=0;i<m[digits[pos]].size();i++){
        path.push_back(m[digits[pos]][i]);
        backtrack(res,path,m,digits,pos+1,n);
        path.pop_back();
    }
    return;
}
vector<string> letterCombinations(string digits) {
    //backtracking all solution
    vector<string> res;
    if(digits=="") return res;
    unordered_map<char,vector<char>> m;
    m['2']={'a','b','c'};m['3']={'d','e','f'};m['4']={'g','h','i'};
    m['5']={'j','k','l'};m['6']={'m','n','o'};m['7']={'p','q','r','s'};
    m['8']={'t','u','v'};m['9']={'w','x','y','z'};

    string path="";
    backtrack(res,path,m,digits,0,digits.size());
    return res;
}
